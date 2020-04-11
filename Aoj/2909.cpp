#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long q[400][400];
int time1[400];
void add(int s){
    int t=2;
    while(s!=1){
        if(s%t==0){
            time1[t]++;
            s/=t;
        }else t++;
    }
    return;
}
void shan(int s){
    int t=2;
    while(s!=1){
        if(s%t==0){
            time1[t]--;
            s/=t;
        }else t++;
    }
    return;
}
long long c(int p,int q){
    if(p<q)return 0;
    long long ans=1;
    memset(time1,0,sizeof(time1));
    for(int i=1;i<=p;i++)add(i);
    for(int i=1;i<=q;i++)shan(i);
    for(int i=1;i<=(p-q);i++)shan(i);
    for(int i=1;i<=p;i++){
        for(int j=1;j<=time1[i];j++){
            ans*=i;
        }
    }
    return ans;
}
long long get(int pos,int len){
    long long ans=0;
    for(int i=1;i<=len;i++){
        ans+=q[pos-1][i];
    }
    return ans+1;
}
void wait(){
    for(int i=1;i<=32;i++){
        for(int j=i;j>=0;j--){
            q[i][j]=c(i,j);
        }
    }
}
int dp[1000];
int main(){
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    int n,l;
    long long k;
    wait();
    scanf("%d%d",&n,&l);
    cin>>k;
    int last=l;
    while(k!=0){//k是剩下的大小
        for(int i=1;i<=n+1;i++){
            long long getans=get(i,last)+1;//getans是当前点的大小
            if(k<getans){
                dp[i-1]=1;//当前点定为1
                k-=get(i-1,last);//若比他大则减去，此处减去的并不是getans，
                last--;
                break;
            }else if(k==getans){
                dp[i]=1;
                k-=getans;
                break;
            }
        }
    }
    for(int i=n;i>=1;i--)
        printf("%d",dp[i]);
    printf("\n");
}
