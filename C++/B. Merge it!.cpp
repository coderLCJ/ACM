#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int q;
        cin>>q;
        int a[q],s1=0,s2=0,s3=0;
        for(int i=0;i<q;i++){
            cin>>a[i];
            if(a[i]%3==0){
                s1++;
            }
            else if(a[i]%3==1){
                s2++;
            }
            else{
                s3++;
            }
        }
        if(s2==s3){
            cout<<s1+s2<<endl;
        }
        else if(s2>s3){
            cout<<s1+s3+(s2-s3)/3<<endl;
        }
        else{
            cout<<s1+s2+(s3-s2)/3<<endl;
        }
    }
}
