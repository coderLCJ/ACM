#include<bits/stdc++.h>
using namespace std;
void ten_to_n(int n,int m){
   string ans;
   while(n){
      if(n%m<=9){
        ans+=(n%m+'0');
      }
      else{
        ans+=(n%m-10+'A');
      }
      n/=m;
   }
   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;
}
int main(){
   ios::sync_with_stdio(0);
   int n,m;
   cin>>n>>m;
   ten_to_n(n,m);
}

