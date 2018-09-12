#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct T{
      string number;
      string name;
      int score;
}s[100000];
int cmp1(const void *a,const void *b){
      struct T *aa=(T *)a;
      struct T *bb=(T *)b;
      return (((aa->number)>(bb->number))?1:-1);
}
int cmp2(const void *a,const void *b){
      struct T *aa=(T *)a;
      struct T *bb=(T *)b;
      if(aa->name!=bb->name)
           return (((aa->name)>(bb->name))?1:-1);
      else
           return (((aa->number)>(bb->number))?1:-1);

}
int cmp3(const void *a,const void *b){
      struct T *aa=(T *)a;
      struct T *bb=(T *)b;
      if(aa->score!=bb->score)
           return (((aa->score)>(bb->score))?1:-1);
      else
           return (((aa->number)>(bb->number))?1:-1);

}
void show(int N){
      for(int i=0;i<N;i++){
          cout<<s[i].number<<' '<<s[i].name<<' '<<s[i].score<<endl;
      }
}
int main(){
      int N,C,d=1;
      while(cin>>N>>C&&N!=0){
          for(int i=0;i<N;i++){
              cin>>s[i].number>>s[i].name>>s[i].score;
          }
          cout<<"Case "<<d++<<':'<<endl;
          if(C==1){
             qsort(s,N,sizeof(s[0]),cmp1);
             show(N);
          }
          else if(C==2){
             qsort(s,N,sizeof(s[0]),cmp2);
             show(N);
          }
          else if(C==3){
             qsort(s,N,sizeof(s[0]),cmp3);
             show(N);
          }
      }
} 
 
