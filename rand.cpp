#include<bits/stdc++.h>
using namespace std;
bool judge(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){

    srand((int)time(NULL));
    int a=rand()%95+32;
    cout<<a<<' '<<char(a)<<endl;
    char s[100],ans[100];
    cin>>s;
    int len=strlen(s),count=0;
    for(int j=1,i=0;i<strlen(s);j++){
        if(judge(j)){
            ans[count++]=char(s[i]+a%10); cout<<char(s[i]+a%10)<<' '<<j<<endl;
            ans[count++]=char(a);
            i++;
            a=a*len%128;
            len+=a*a*a;
            a=a%95+32;

        }
        else{
            ans[count++]=char(a%95+32);
        }
    }
    ans[count]='\0';
    cout<<endl;
    cout<<ans<<endl;
/*
    string p;
    for(int i=0,j=1;i<ans.size();i++){
        if(judge(j)){
            p+=ans[i]-ans[i+1]%10;cout<<p<<endl;
            j++;
            i++;
        }
        else{
            j++;
        }
    }
    */
}


