#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<9;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<' ';
    }
}
