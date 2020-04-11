#include  <iostream>
#include  <bits/stdc++.h>
#include  <string>
using namespace std;
int main()
{
    string a,b,c,d;
   string  e[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int t=0,m=0,n=0,k=0;
    cin>>a>>b>>c>>d;
   for(int i=0;i<60;i++)
   {
       if(a[i]>='A'&&a[i]<='G'&&a[i]==b[i]&&t==0)
       {
           k=a[i]-'A'+1;
           t++;
       }
       if(a[i]==b[i]&&t==1)
       {
           if(a[i]>='A'&&a[i]<='N')
             {   m=a[i]-'A'+10;
                 break;
             }
          if(a[i]<='9'&&a[i]>='0')
          {m=a[i]-'0';
           break;
          }
       }
   }
     for(int j=0;j<60;j++)
   {
       if((('a' <= c[j] && c[j] <= 'z') || ('A' <= c[j] && c[j] <= 'Z'))&&c[j]==d[j])
       {
           n=j;
           break;
       }
   }
    cout<<e[k-1]<<(m < 10 ? " 0" : " ") << m<< (n < 10 ? ":0" : ":") << n;
    return 0;
}

