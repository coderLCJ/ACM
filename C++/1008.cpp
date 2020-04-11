#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m>n) m%=n;
    if(m==0) m=n;
    for(int i=n-m;s<n;i++){
        if(s==0){
            cout<<a[i];
        }
        else{
            cout<<' '<<a[i];
        }
        if(i>=n-1){
            i=-1;
        }
        s++;
    }
}

