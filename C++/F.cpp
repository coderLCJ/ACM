#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m)
    {
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int day=1; day<=m; day++)
        {
            a[n-1]--;
            for(int i=n-1; i>=1; i--)
            {
                if(a[i]<a[i-1])
                {
                    swap(a[i],a[i-1]);
                }
                else
                    break;
            }
            a[0]++;
            for(int i=0; i<n-1; i++)
            {
                if(a[i]>a[i+1])
                {
                    swap(a[i],a[i+1]);
                }
                else
                    break;
            }
        }
        cout<<a[n-1]-a[0]<<endl;
    }
}
