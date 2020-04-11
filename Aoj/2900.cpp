#include<bits/stdc++.h>
using namespace std;
int main()
{
    int e[100][100],k,i,j,n,m=51,t3;
    char t1,t2;
    int inf=999999;
    scanf("%d",&n);
    for(i=0; i<=m; i++)
        for(j=0; j<=m; j++)
            e[i][j]=inf;
    for(i=0; i<n; i++)
    {
        int x,y;
        cin>>t1>>t2>>t3;
        if(t1>='A'&&t1<='Z')
            x=t1-65;
        if(t2>='A'&&t2<='Z')
            y=t2-65;
        if(t1>='a'&&t1<='z')
            x=t1-97+26;
        if(t2>='a'&&t2<='z')
            y=t2-97+26;
        if(t3<e[x][y])
           e[x][y]=e[y][x]=t3;
       // cout<<x<<y<<t3<<endl;
    }
    for(k=0; k<=m; k++)
        for(i=0; i<=m; i++)
            for(j=0; j<=m; j++)
                if(e[i][j]>e[i][k]+e[k][j] )
                    e[i][j]=e[i][k]+e[k][j];
    int xiao=101000;
    char ans;
    for(i=0; i<=24; i++)
    {
        if(e[25][i]<xiao)
        {
             xiao=e[25][i];
             ans=i;
        }
    }
    printf("%c %d\n",ans+65,xiao);
}
