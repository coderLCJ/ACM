#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    cin>>n>>m;
    for(int i = 1;i <= n / 2;i++) {
        for(int j = 1;j <= m;j++) {
            cout<<i<<" "<<j<<"\n";
            cout<<n - i + 1<<" "<<m - j + 1<<"\n";
        }
    }
    if(n % 2 == 1){
        int mid = n - n / 2;
        for(int i = 1;i <= m / 2;i++){
            cout<<mid<<" "<<i<<"\n";
            cout<<mid<<" "<<m - i + 1<<"\n";
        }
        if(m % 2 == 1) cout<<mid<<" "<<m - m / 2<<"\n";
    }
    return 0;
}
