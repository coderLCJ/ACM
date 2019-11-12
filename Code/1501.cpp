#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
int a[MAX]={0};
int n,x,y;
void findw(){
    int now=1,w=0,wide=1;
    while(now<n*2+1){
        for(int i=now;i<now*2;i++){
            if(a[i]){
                w++;
            }
        }
        now*=2;
        if(w>wide){
            wide=w;
        }
        w=0;
    }
    cout<<wide<<' ';
}
void findh(){
    int deep=1,flag=1,d=0;
    while(flag){
        flag=0;
        for(int i=deep;i<deep*2;i++){
            if(a[i]){
                flag=1;
                d++;
                break;
            }
        }
        deep*=2;
    }
    cout<<d<<endl;
}
int main(){
    cin>>n;
    a[1]=1;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[x]=1;
        a[y]=1;
    }
    findw();
    findh();
}


