#include<cstdio>
using namespace std;
int a[51],f[2000001];
int k,n;
int main()
{
	int i,j;
	scanf("%d%d",&k,&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=2000000;i++)
	{
		f[i]=666666666;
		for (j=1;j<=n;j++)
		{
			if (i-a[j]>=0&&f[i]>f[i-a[j]]+1) f[i]=f[i-a[j]]+1;
		}
		if (f[i]>k)
		{
			printf("%d\n",i-1);
			return 0;
		}
	}
	printf("%d\n",i-1);
	return 0;
}
