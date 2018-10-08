#include<bits/stdc++.h>
using namespace std;
string fake,uzi[200],faker;
int letme=0,ming[200]={0};
void set1(){
     int i;
     if(faker.length()>0){
        for(i=0;i<letme;i++){
            if(uzi[i]==faker)
               break;
        }
        if(i==letme){
           uzi[letme]=faker;
           ming[letme]++;
           letme++;
        }
        else{
           ming[i]++;
        }
    }
    faker="";
}
int main()
{
    while(cin>>fake){
        for(int i=0;i<fake.length();i++){
            if(isalpha(fake[i])){
               if(fake[i]>='a'&&fake[i]<='z')
                  faker+=(fake[i]-32);
               else
                  faker+=fake[i];
            }
            else
               set1();
        }
        set1();
        char pdd=getchar();
        if(pdd=='\n')
           break;
    }
    int wide=uzi[0].length();
    for(int j=0;j<letme;j++){

           cout<<uzi[j];

        cout<<':';
        for(int j1=0;j1<ming[j];j1++){
            cout<<'*';
        }
        cout<<ming[j]<<endl;
    }
}
