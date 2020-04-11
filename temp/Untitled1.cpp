#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a[n],max=0,min=10000000;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(max<=a[i])
            max=a[i];
        if(min>=a[i])
            min=a[i];
    }
    cout<<max-min<<endl;
}
