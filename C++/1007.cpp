#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int T,k,len;
    cin>>T;
    while(T--){
        cin>>k;
        len=pow(2,k);
        string s[len],temp;
        s[0]="CC",s[1]="PC";
        if(k==1){
            cout<<s[0]<<endl<<s[1]<<endl;
        }
        else{
            int now=2,p;
            while(now<=len/2){
                p=now;
                for(int i=0,j=p;i<p,j<len;j++,i++){
                    temp=s[i];
                    s[i]=temp+temp;
                    for(int q=0;q<p;q++){ //cout<<s[i][q]<<endl;
                        if(s[i][q]=='C'){
                            s[j]+='P';
                        }
                        else{
                            s[j]+='C';
                        }
                    }
                    s[j]+=temp;             // cout<<s[j]<<endl;
                }

                now*=2;
            }

            for(int i=0;i<len;i++){
               cout<<s[i]<<endl;
            }
        }
    }

}
