#include<stdio.h>
int a[105][105],m,n;
void DFS(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n)//����߽�
    return;
    if(a[x][y]!=0)//����
    {
        a[x][y]=0;//����֮�� �˽ڵ���0
        DFS(x+1,y);//�ݹ���� ������
        DFS(x,y+1);//��
        DFS(x-1,y);//��
        DFS(x,y-1);//��
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
                if(a[i][j]==1)//���� 1 ��ʼ��
                {
                    DFS(i,j);
                    sum++;
                }
                //printf("%d ",a[i][j]);

        }
        printf("%d\n",sum);
    }
}
