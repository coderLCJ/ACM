#include<bits/stdc++.h>
using namespace std;
int a[50]={0,1,1,2};
void made(){
    for(int i=3;i<=40;i++){
        a[i]=a[i-1]+a[i-2];
    }
}
int main(){
    int n;
    cin>>n;
    made();
    cout<<a[n]<<endl;
}

