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
    cout<<"Microsoft Windows [�汾 6.1.7601]\n��Ȩ���� (c) 2009 Microsoft Corporation����������Ȩ����\n\n";
}

void input(vector<string> &dos)
{
    string s,temp,Original;
    getline(cin,s);
    istringstream sin(s);                                  //�����ַ�������ȥ�����ж���ո�
    while(sin>>temp)
    {
        dos.push_back(temp);
    }
}

bool judge(vector<string> dos)
{
    string OR=dos[0];
    transform(dos[0].begin(),dos[0].end(),dos[0].begin(),::tolower);      //������ת����Сд
    if(dos[0]=="exit")
    {
        exit(0);
    }
    if(dos[0]!="mkdir")
    {
        cout<<"\'"<<OR<<"\'"<<" �����ڲ����ⲿ���Ҳ���ǿ����еĳ���\n���������ļ���\n"<<endl;
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
        if(Find(dos[i]))                     //������Ϊ�༶�����������⴦��
        {
            vector<string> bulids;
            string New;
            break_down(dos[i],bulids);      //���༶Ŀ¼�ֽ⣬�������
            for(int j=0; j<bulids.size(); j++)
            {
                New+=bulids[j];
                ans=mkdir(New.c_str());
                if(j==bulids.size()-1&&ans!=0)         //�ж��ļ��Ƿ��Ѵ���
                {
                    ans=-1;
                }
                else
                {
                    ans=0;
                }
                New+="\\\\";                  //��������\\,ǰһ��Ϊת�����ã��𼶴����ļ�
            }
        }
        else
        {
            ans=mkdir(dos[i].c_str());
        }
        if(ans==-1)                             //�ļ��Ѵ��ڣ����ظ��ļ�����������������֮�����
        {
            wa=1;
            Repeat.push_back(dos[i]);
        }
        if(Warning(dos[i]))                     //�ж������Ƿ�Ϸ�
            wa=2;
    }
    if(wa==1)
    {
        for(auto k:Repeat)
        {
            cout<<"��Ŀ¼���ļ� "<<k<<" �Ѿ�����\n";
        }
    }
    else if(wa==2)
    {
        cout<<"������﷨����\n";
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
    ios::sync_with_stdio(false);        //�ر�ͬ��
    vector<string> dos;                 //���DOS��������
    string pos=Get_pos(argv[0]);        //��ȡ��ǰ·��
    DOS_version();                      //�汾��
    while(1)
    {
        dos.clear();                    //��������
        position(pos);                  //�����ǰ·��
        input(dos);                     //��������
        if(judge(dos))                  //�ж��Ƿ�Ϊ�����ļ�����
            continue;
        bulid(dos);                     //����
    }
}
