#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,c,d;
    string  e[7]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int t=0,m=0,n=0,flag=0;
    cin>>a>>b>>c>>d;
    for(int i=0; i<=60; i++)
    {
        if(a[i]>='A'&&a[i]<='G'&&a[i]==b[i]&&flag==0)
        {
            t=a[i]-'A';
            flag=1;
            continue;
        }
        if(a[i]==b[i]&&flag==1)
        {
            if(a[i]>='A'&&a[i]<='N')
            {
                m=a[i]-'A'+10; break;
            }
            else if(a[i]>='0'&&a[i]<='9')
            {
                m=a[i]-'0';     break;
            }
        }
    }
    for(int j=0; j<=60; j++)
    {
        if((('a' <= c[j] && c[j] <= 'z') || ('A' <= c[j] && c[j] <= 'Z'))&&c[j]==d[j])
        {
            n=j;
            break;
        }
    }
    cout<<e[t]<<" ";
    printf("%02d:%02d\n",m,n);
}
