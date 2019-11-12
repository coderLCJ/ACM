#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    a[0]=1;
    for(int i=1; i<=n; i++)
        a[i]=a[i-1]+4*(i-1);
    cout<<a[n]<<endl;
}
