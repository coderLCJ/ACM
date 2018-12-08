#include<bits/stdc++.h>
using namespace std;
int a[200][200],s=0,n,m,ans1,ans2,min1;
void dfs(int x,int y){
     //if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0)
     //cout<<"x="<<x<<"  y="<<y<<"  s="<<s<<endl;
    if(!(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0))
       return;

    else if(x==ans1-1&&y==ans2-1){

       if(s<min1)
            min1=s;

       return ;
    }

       s++;
       a[x][y]=2;
       dfs(x+1,y);
       dfs(x-1,y);
       dfs(x,y+1);
       dfs(x,y-1);

     if(a[x][y]==2){
        s--,a[x][y]=0;
     }
}
int main()
{
    int x,y;
    while(cin>>n>>m){
    min1=999999;
    memset(a,0,sizeof(a));
    s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    cin>>ans1>>ans2>>x>>y;
    dfs(x-1,y-1);
    min1==999999?cout<<"No Way!"<<endl:cout<<min1<<endl;
    }
}
