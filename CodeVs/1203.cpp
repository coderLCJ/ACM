#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    if(fabs(a-b)<=1e-8){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
}
