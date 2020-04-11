#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
int a[MAX];
int main() {
    ios::sync_with_stdio(false);
    int N,Q,l,r;
    while(cin>>N>>Q){
        for(int i=0;i<N;i++){
            cin>>a[i];
        }

        while(Q--){
            int s1=0,s2=0,s3=0,sum,ans=-1;
            cin>>l>>r;
            if(r-l<2){
                cout<<-1<<endl;
                continue;
            }
            for(int i=l-1;i<r;i++){
                 if(a[i]>s1){
                    s3=s2,s2=s1,s1=a[i];
                 }
                 else if(a[i]>s2){
                    s3=s2,s2=a[i];
                 }
                 else if(a[i]>s3){
                    s3=a[i];
                 }
                 sum=s2+s3;
                 if(s1&&s2&&s3&&sum>s1){
                     if(sum+s1>ans){
                        ans=sum+s1;
                     }
                     //cout<<"ans="<<ans<<endl;
                 }
                 //cout<<s1<<" "<<s2<<" "<<s3<<endl;
            }
            cout<<ans<<endl;
        }
    }
}
