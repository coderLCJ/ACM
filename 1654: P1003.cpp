#include<iostream>
#include<bits/stdc++.h>
using namespace std;\
char faker[100][100],uzi[100][100],xiaohu[100];
int main(){
    int t=0,letme[100]={0};
    while(cin>>faker[t]){
          strcpy(uzi[t],faker[t]);
          sort(faker[t],faker[t]+strlen(faker[t]));
          t++;
          char pdd=getchar();
          if(pdd=='\n')
             break;
    }
    while(cin>>xiaohu){
          sort(xiaohu,xiaohu+strlen(xiaohu));
          for(int i=0;i<t;i++){
              if(strcmp(faker[i],xiaohu)==0){
                 letme[i]=1;
                 break;
              }
          }
          char pdd=getchar();
          if(pdd=='\n')
             break;
    }
    for(int i=0;i<t;i++){
        if(letme[i])
           cout<<uzi[i]<<' ';
    }
}
