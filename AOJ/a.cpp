#include<bits/stdc++.h>
using namespace std;
int main(){
    long long A,B,C,T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>A>>B>>C;
        if(A+B>C){
            cout<<"Case #"<<i<<": true"<<endl;
        }
        else{
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }
}
