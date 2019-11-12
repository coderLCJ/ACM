#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    unique(a,a+n);
    for(int i=0;i<n-1;i++){
        sum++;
        if(a[i]>=a[i+1]){
           break;
        }
    }
    cout<<sum<<endl<<a[0];
    for(int i=1;i<sum;i++){
        cout<<' '<<a[i];
    }
    cout<<endl;
}
