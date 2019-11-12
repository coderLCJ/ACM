#include<bits/stdc++.h>
using namespace std;
const int MOD=1e6+3;
int main()
{
    int n,temp;
    while(~scanf("%d",&n))
    {
        temp=1;
        for(int i=1; i<=n; i++)
        {
            temp=temp*i%MOD;
        }
        printf("%d\n",temp);
    }
}
