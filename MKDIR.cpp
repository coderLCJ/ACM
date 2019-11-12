#include<iostream>
#include<istream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<direct.h>
using namespace std;

void DOS_version()
{
    cout<<"Microsoft Windows [版本 6.1.7601]\n版权所有 (c) 2009 Microsoft Corporation。保留所有权利。\n\n";
}

void input(vector<string> &dos)
{
    string s,temp,Original;
    getline(cin,s);
    istringstream sin(s);                                  //建立字符串流，去除所有多余空格
    while(sin>>temp)
    {
        dos.push_back(temp);
    }
}

bool judge(vector<string> dos)
{
    string OR=dos[0];
    transform(dos[0].begin(),dos[0].end(),dos[0].begin(),::tolower);      //将命令转换成小写
    if(dos[0]=="exit")
    {
        exit(0);
    }
    if(dos[0]!="mkdir")
    {
        cout<<"\'"<<OR<<"\'"<<" 不是内部或外部命令，也不是可运行的程序\n或批处理文件。\n"<<endl;
        return true;
    }
    return false;
}

bool Find(string s)
{
    sort(s.begin(),s.end());
    return binary_search(s.begin(),s.end(),'\\');
}

bool Warning(string s)
{
    for(auto p:s)
    {
        if(!isalnum(p)&&!isalpha(p)&&p!='\\'&&p!=':'||p=='\/')
        {
            return true;
        }
    }
    return false;
}

void break_down(string s,vector<string> &bulids)
{
    string temp;
    for(int i=0; i<=s.size(); i++)
    {
        if(s[i]=='\\'||i==s.size())
        {
            bulids.push_back(temp);
            temp="";
            continue;
        }
        temp+=s[i];
    }
}

void bulid(vector<string> dos)
{
    int ans=0,wa=0;
    vector<string> Repeat;
    for(int i=1; i<dos.size(); i++)
    {
        if(Find(dos[i]))                     //此命令为多级创建，需特殊处理
        {
            vector<string> bulids;
            string New;
            break_down(dos[i],bulids);      //将多级目录分解，逐个创建
            for(int j=0; j<bulids.size(); j++)
            {
                New+=bulids[j];
                ans=mkdir(New.c_str());
                if(j==bulids.size()-1&&ans!=0)         //判断文件是否已存在
                {
                    ans=-1;
                }
                else
                {
                    ans=0;
                }
                New+="\\\\";                  //加入两个\\,前一个为转义作用，逐级创建文件
            }
        }
        else
        {
            ans=mkdir(dos[i].c_str());
        }
        if(ans==-1)                             //文件已存在，将重复文件名加入容器，用于之后输出
        {
            wa=1;
            Repeat.push_back(dos[i]);
        }
        if(Warning(dos[i]))                     //判断命令是否合法
            wa=2;
    }
    if(wa==1)
    {
        for(auto k:Repeat)
        {
            cout<<"子目录或文件 "<<k<<" 已经存在\n";
        }
    }
    else if(wa==2)
    {
        cout<<"命令或语法错误\n";
    }
    cout<<endl;
}

string Get_pos(char * s)
{
    for(int i=strlen(s)-1; i>=0; i--)
    {
        if(s[i]=='\\')
        {
            s[i]='\0';
            break;
        }
    }
    return string(s);
}

void position(string pos)
{
    cout<<pos<<">";
}

int main(int argc,char *argv[])
{
    ios::sync_with_stdio(false);        //关闭同步
    vector<string> dos;                 //存放DOS命令容器
    string pos=Get_pos(argv[0]);        //获取当前路径
    DOS_version();                      //版本号
    while(1)
    {
        dos.clear();                    //重置容器
        position(pos);                  //输出当前路径
        input(dos);                     //输入命令
        if(judge(dos))                  //判断是否为创建文件命令
            continue;
        bulid(dos);                     //创建
    }
}
