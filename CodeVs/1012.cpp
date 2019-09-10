#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int x,y,s=0;
    cin>>x>>y;
    for(int i=x;i<=y;i+=x){
        for(int j=x+x;j<=y;j++){
            if(__gcd(i,j)==x&&i*j/x==y){
                s++;
            }
        }
    }
    if(s!=0)
       cout<<s+1<<endl;
    else
       cout<<0<<endl;
}
