#include<bits/stdc++.h>
using namespace std;
bool judge(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    if(judge(n)){
        cout<<"\\t"<<endl;
    }
    else{
        cout<<"\\n"<<endl;
    }
}
