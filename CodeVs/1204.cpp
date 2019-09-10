#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[0]){
            string t=a.substr(i,b.size());
            if(t==b){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
}

