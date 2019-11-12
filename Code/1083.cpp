#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    long long n,a=1,b=1,t=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(a==1&&b==1){
            b++;
            t=0;
            continue;
        }
        else if(a==1&&b%2==0){
            a++;
            b--;
            t=0;
            continue;
        }
        else if(a==1&&b%2!=0){
            b++;
            t=0;
            continue;
        }
        else if(a%2==0&&b==1){
            a++;
            t=1;
            continue;
        }
        else if(a%2!=0&&b==1){
            a--;
            b++;
            t=1;
            continue;
        }
        if(t==1){
            a--;
            b++;
        }
        else if(t==0){
            a++;
            b--;
        }
    }
    cout<<a<<'/'<<b<<endl;
}
