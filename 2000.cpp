#include<stdio.h>
int a[105][105],m,n;
void DFS(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n)//到达边界
    return;
    if(a[x][y]!=0)//跳出
    {
        a[x][y]=0;//搜完之后 此节点置0
        DFS(x+1,y);//递归调用 往下搜
        DFS(x,y+1);//右
        DFS(x-1,y);//上
        DFS(x,y-1);//左
    }
}
int main()
{
    int N,i,j;
    scanf("%d",&N);
    while(N--)
    {
        int sum=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
       for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
                if(a[i][j]==1)//遇到 1 开始搜
                {
                    DFS(i,j);
                    sum++;
                }
                //printf("%d ",a[i][j]);

        }
        printf("%d\n",sum);
    }
}
