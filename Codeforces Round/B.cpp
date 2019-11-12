#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a[110000],k=0;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>a[i];
        if(0==n%2)
        {
            if(a[i]>=0)cout <<-a[i]-1<<' ';
            else cout <<a[i]<<' ';
        }
        else
        {
            if(a[i]<0)a[i]=-a[i]-1;
            if(a[i]>a[k])k=i;
        }
    }
    if(1==n%2)
    {
        for(i=0;i<n;i++)
        {
            if(i!=k)a[i]=-a[i]-1;
            cout <<a[i]<<' ';
        }
    }
    return 0;
}
