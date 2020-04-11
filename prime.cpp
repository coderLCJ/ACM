#include<bits/stdc++.h>
using namespace std;
int a[1000000]={0};
void prime()
{
    int i,j;
    a[0]=a[1]=1;
    for(i=2;i<1000000;i++)
      for(j=i*2;j<1000000;j+=i)
          a[j]=1;
}
int main()
{
     prime();
     for(int i=0;i<100;i++){
         if(!a[i])
            cout<<i<<endl;
     }
}
