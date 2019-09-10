#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,Max=INT_MIN,Min=INT_MAX;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>Max){
            Max=t;
        }
        if(t<Min){
            Min=t;
        }
    }
    cout<<Min<<' '<<Max<<endl;
}
