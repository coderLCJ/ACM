#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,ans=0;
    string n;
    cin>>n>>m;
    int len=n.size();
    for(int i=0;i<len;i++){
        if(isdigit(n[i]))
           ans+=(n[i]-'0')*pow(m,len-1-i);
        else
           ans+=(n[i]-'A'+10)*pow(m,len-1-i);
    }
    cout<<ans<<endl;
}
