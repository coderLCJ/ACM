#include<bits/stdc++.h>
using namespace std;
char str[10010][10010];
int ans,l,r,k,Size;
struct Trie
{
    int next[1010*50][128],fail[1010*50],end[1010*50];
    int root,L;
    int newnode()
    {
        for(int i=0; i<128; i++)
        {
            next[L][i]=-1;
        }
        end[L++]=-1;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char *s,int id)
    {
        int len=strlen(s);
        int now=root;
        for(int i=0; i<len; i++)
        {
            if(next[now][s[i]]==-1)
                next[now][s[i]]=newnode();
            now=next[now][s[i]];
        }
        end[now]=id;
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for(int i=0; i<128; i++)
        {
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for(int i=0; i<128; i++)
            {
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    int num[1010];
    void query(char *buf,int n)
    {
        memset(num,0,sizeof(num[0]));
        int len=strlen(buf);
        int now=root;
        int sum=0;
        for(int i=0; i<len; i++)
        {
            now=next[now][buf[i]];
            int temp=now;
            while(temp!=root)
            {
                if(end[temp]!=-1){
                    num[end[temp]]++;
                    sum++;
                }

                if(sum==k){
                    printf("%d\n",i+1);
                    return;
                }
                else if(sum==Size){
                    printf("-1\n");
                    return ;
                }
                temp=fail[temp];
            }
        }
        printf("-1\n");
    }

} ac;
char buf[2000010],String[2000010];
int main()
{
    int n,q;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&Size,&q);
        scanf("%s",String);
        for(int i=0;i<q;i++){
             ans=0;
             scanf("%d%d%d",&l,&r,&k);
             ac.init();
             for(int w=l-1,j=0;w<r;w++,j++){
                 str[i][j]=String[w];
             }
              str[i][r-l+1]='\0';
              ac.insert(str[i],i);
              ac.build();
              strcpy(buf,String);
              ac.query(buf,n);
        }
    }
    return 0;
}
