#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=1000000;
char str[MAX_SIZE];
int n,t,len[MAX_SIZE],ans,ansum;
void manacher(char str[],int len[],int n){
    len[0]=1,ansum=0,ans=0;
    for(int i=0,j=0;i<(n<<1)-1;++i){
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1 && q+len[i]<n && str[p - len[i]]== str[q+len[i]])
             ++len[i];
        if(q+len[i]-1>r)
            j=i;
        if(len[i]>=ansum){
            ansum=len[i];
            ans=i;
        }
    }
}
int main(){
    cin>>t;
    getchar();
    while(t--){
        gets(str);
        n=strlen(str);
        manacher(str,len,n);
        for(int i=0;i<n*2;i++){
            cout<<len[i]<<endl;
        }
        cout<<ans<<endl<<ansum<<endl;
    }
}
