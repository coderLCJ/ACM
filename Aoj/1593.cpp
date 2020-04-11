#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int s;
};
const int MAX=1e3;
int e[MAX][MAX],book[MAX]= {0};
int n,m,Start,End;
int bfs()
{
    node cur,temp;
    queue<node> q;
    cur.x=Start;
    cur.s=0;
    q.push(cur);
    book[Start]=1;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==End){
            return cur.s;
        }
        for(int i=1; i<=n; i++)
        {
            if(e[cur.x][i]!=INT_MAX&&book[i]==0)
            {
                temp.x=i;
                temp.s=cur.s+1;
                q.push(temp);
                book[i]=1;
                if(i==End){
                    return temp.s;
                }
            }

        }
    }
    return -1;
}
int main()
{
   // freopen("1.txt","r",stdin);
    while(cin>>n>>m>>Start>>End)
    {
        memset(book,0,sizeof(book));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)
                    e[i][j]=0;
                else
                    e[i][j]=INT_MAX;
            }
        }
        int q,w;
        for(int i=1; i<=m; i++)
        {
            cin>>q>>w;
            e[q][w]=1;
            e[w][q]=1;
        }
        int ans=bfs();
        if(ans>=0)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"Connot reach"<<endl;
        }
    }
}
