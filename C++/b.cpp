#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,MAX=2010;
int w[MAX][MAX];
int M=1e10;
int main(){
    int t,q;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                w[i][j]=M;
            }
        }
        for(int i=0;i<m;i++){
                cin>>x>>y;
                cin>>q;
                if(q<w[x][y]){
                    w[x][y]=q;
                }

        }
        int ans=0;
          for(int i=1;i<=n;i++){
              for(int j=1;j<=n;j++){
                   if(i!=j&&abs(i-j)!=1&&(i!=1||j!=n)&&(i!=n||j!=1)){//cout<<i<<" "<<j<<endl;
                       int slove=__gcd(i,j);
                       ans=(ans+abs(i/slove-j/slove))%MOD;
                   }
              }
          }
          cout<<ans<<endl;
    }
}



