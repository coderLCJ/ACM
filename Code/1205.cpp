#include<bits/stdc++.h>
using namespace std;
int main(){
    string n[1000],t;
    int s=0;
    while(cin>>t){
        n[s++]=t;
        char c=getchar();
        if(c=='\n'){
            break;
        }
    }
    cout<<n[s-1];
    for(int i=s-2;i>=0;i--){
        cout<<' '<<n[i];
    }
    cout<<endl;
}

