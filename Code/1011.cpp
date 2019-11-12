#include<bits/stdc++.h>
using namespace std;
int s=1;
void dfs(int n){
    for(int i=n/2;i>=1;i--){
        s++;
        dfs(i);
    }

}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    dfs(n);
    cout<<s<<endl;
}

