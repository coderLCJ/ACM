#include<bits/stdc++.h>
using namespace std;
int  prime(int a);
int main()
{
    int m,n,t=0,number=0;
    cin>>m>>n;
    for(int j=2; number<=n; j++)
    {
        if(prime(j)){
            number++;
            if(number>=m)
            {
                if(t==0)
                {
                    cout<<j;
                    t++;
                }
                else
                {
                    cout<<' '<<j;
                    t++;
                }
                if(t==10)
                {
                    cout<<endl;
                    t=0;
                }
            }
        }
    }
}
int  prime(int a)
{
    if(a%2==0&&a!=2)
        return  0;
    for(int l=3; l<=sqrt(a); l++)
    {
        if(a%l==0)
            return 0;
    }
    return  1;
}
