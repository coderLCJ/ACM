#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL q,n;
    cin>>q;
    for(LL i=0;i<q;i++){
        cin>>n;
        LL s=0;
        while(n%5==0){
            n=4*n/5;
            s++;
        }
        while(n%3==0){
            n=2*n/3;
            s++;
        }
        while(n%2==0){
            n/=2;
            s++;
        }
        if(n==1){
            cout<<s<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
