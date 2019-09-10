#include<cstdio>
#define min(a,b,c) (a)<(b)?(a)<(c)?(a):(c):(b)<(c)?(b):(c)
#define max(a,b,c) (a)>(b)?(a)>(c)?(a):(c):(b)>(c)?(b):(c)
short f,x,y,b=500,e,cnt;
short fx[501],r[1030],t[1030][1030];
inline short read()
{
	short i=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') i=(i<<3)+(i<<1)+c-48,c=getchar();
	return i;
}
void find(short x)
{
	for(short i=b;i<=e;++i)
		if(t[x][i])
		{
			--t[x][i];
			--t[i][x];
			find(i);
		}
	r[++cnt]=x;
}
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	f=read();
	for(short i=1;i<=f;++i)
	{
		x=read();
		y=read();
		++t[x][y];
		++t[y][x];
		++fx[x];
		++fx[y];
		b=min(b,x,y);
		e=max(e,x,y);
	}
	for(short i=b;i<=e;++i)
		if(fx[i]&1)
		{
			find(i);
			break;
		}
		else if(i==e) find(b);
	for(short i=cnt;i>=1;--i) printf("%d\n",r[i]);
	return 0;

}
