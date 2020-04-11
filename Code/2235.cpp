#include<bits/stdc++.h>
using namespace std;
int main(){
    double n,a;
    cin>>n>>a;
    int temp=int(n*(a/10));
    if(temp%10<5){
        cout<<temp-temp%10<<endl;
    }
    else{
        cout<<temp-temp%10+10<<endl;
    }
}

