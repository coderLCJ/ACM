#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
#define maxn 101
int map[maxn][maxn];
int n,m,start,en_d;

struct node
{
    int begin,sp;
};
int bfs()
{
    queue<node> q;
    node now;
    now.begin = start;
    now.sp=0;
    q.push(now);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        if(now.begin == en_d)
            return now.sp;
        if(map[now.begin][0])
        {
            map[now.begin][0]=0;
            node next;
            for(int i=1;i<=n;i++)
            {
                if(map[now.begin][i])
                {
                    next.begin = map[now.begin][i];
                    next.sp=now.sp+1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int a,b;
    while(~scanf("%d%d%d%d",&n,&m,&start,&en_d))
    {
        memset(map,0,sizeof(map));
        for(int i=1;i<n;i++)
            map[i][0]=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=b;
            map[b][a]=a;
        }
        a=bfs();
        if(a<0)
            cout<<"Connot reach"<<endl;
        else
            cout<<a<<endl;
    }
    return 0;
}
