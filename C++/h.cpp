#include<bits/stdc++.h>
using namespace std;
struct player
{
    string name,cc;
    int dj;
    int dj7=0;
    int dj6_1=0,dj6_2=0;
    int dj5_1=0,dj5_2=0;
    int dj4_1=0,dj4_2=0;
    int dj3_1=0,dj3_2=0,dj3_3=0;
    int dj2_1=0,dj2_2=0;
    int dj1=0;
};
bool cmp(player p1,player p2)
{
    if(p1.dj!=p2.dj)
    {
        return p1.dj>p2.dj;
    }
    else if(p1.dj==8){
        return p1.name<p2.name;
    }
    else if(p1.dj==7)
    {
        if(p1.dj7!=p2.dj7)
        {
            return p1.dj7>p2.dj7;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==6)
    {
        if(p1.dj6_1!=p2.dj6_1)
        {
            return p1.dj6_1>p2.dj6_1;
        }
        else if(p1.dj6_2!=p2.dj6_2)
        {
            return p1.dj6_2>p2.dj6_2;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==5)
    {
        if(p1.dj5_1!=p2.dj5_1)
        {
            return p1.dj5_1>p2.dj5_1;
        }
        else if(p1.dj5_2!=p2.dj5_2)
        {
            return p1.dj5_2>p2.dj5_2;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==4)
    {
        if(p1.dj4_1!=p2.dj4_1)
        {
            return p1.dj4_1>p2.dj4_1;
        }
        else if(p1.dj4_2!=p2.dj4_2)
        {
            return p1.dj4_2>p2.dj4_2;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==3)
    {
        if(p1.dj3_1!=p2.dj3_1)
        {
            return p1.dj3_1>p2.dj3_1;
        }
        else if(p1.dj3_2!=p2.dj3_2)
        {
            return p1.dj3_2>p2.dj3_2;
        }
        else if(p1.dj3_3!=p2.dj3_3)
        {
            return p1.dj3_3>p2.dj3_3;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==2)
    {
        if(p1.dj2_1!=p2.dj2_1)
        {
            return p1.dj2_1>p2.dj2_1;
        }
        else if(p1.dj2_2!=p2.dj2_2)
        {
            return p1.dj2_2>p2.dj2_2;
        }
        else
            return p1.name<p2.name;
    }
    else if(p1.dj==1)
    {
        if(p1.dj1!=p2.dj1)
            return p1.dj1>p2.dj1;
        else
            return p1.name<p2.name;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    while(cin>>n)
    {
        player p[n];
        string name,c;
        int card[5];
        for(int i=0; i<n; i++)
        {
            cin>>name>>c;
            p[i].name=name;
            p[i].cc=c;
            int sum=0;
            for(int i=0; i<c.size(); i++)
            {
                if(c[i]=='A')
                    card[sum++]=1;
                else if(c[i]=='J')
                    card[sum++]=11;
                else if(c[i]=='Q')
                    card[sum++]=12;
                else if(c[i]=='K')
                    card[sum++]=13;
                else if(c[i]=='1')
                {
                    card[sum++]=10;
                    i++;
                }
                else
                    card[sum++]=c[i]-'0';
            }
            //for(int i=0;i<5;i++) cout<<card[i]<<' '; cout<<endl;
            sort(card,card+5);
            if(card[0]==1&&card[1]==10&&card[2]==11&&card[3]==12&&card[4]==13)
            {
                p[i].dj=8;
            }
            else
            {
                if(card[0]==card[1]-1&&card[0]==card[2]-2&&card[0]==card[3]-3&&card[0]==card[4]-4)
                {
                    p[i].dj=7;
                    p[i].dj7=card[4];
                }
                else
                {
                    if(card[0]==card[1]&&card[1]==card[2]&&card[2]==card[3]||
                            card[1]==card[2]&&card[2]==card[3]&&card[3]==card[4])
                    {
                        p[i].dj=6;
                        if(card[0]==card[1])
                        {
                            p[i].dj6_1=card[0];
                            p[i].dj6_2=card[4];
                        }
                        else
                        {
                            p[i].dj6_1=card[4];
                            p[i].dj6_2=card[0];
                        }
                    }
                    else if(card[0]==card[1]&&card[1]==card[2]&&card[3]==card[4]||
                            card[0]==card[1]&&card[2]==card[3]&&card[3]==card[4])
                    {
                        p[i].dj=5;
                        if(card[0]==card[1]&&card[1]==card[2]&&card[3]==card[4])
                        {
                            p[i].dj5_1=card[0];
                            p[i].dj5_2=card[4];
                        }
                        else
                        {
                            p[i].dj5_1=card[4];
                            p[i].dj5_2=card[0];
                        }
                    }
                    else if(card[0]==card[1]&&card[1]==card[2]||
                            card[1]==card[2]&&card[2]==card[3]||
                            card[2]==card[3]&&card[3]==card[4])
                    {
                        p[i].dj=4;
                        if(card[0]==card[1]&&card[1]==card[2])
                        {
                            p[i].dj4_1=card[0];
                            p[i].dj4_2=card[4]+card[3];
                        }
                        else if(card[1]==card[2]&&card[2]==card[3])
                        {
                            p[i].dj4_1=card[1];
                            p[i].dj4_2=card[0]+card[4];
                        }
                        else
                        {
                            p[i].dj4_1=card[3];
                            p[i].dj4_2=card[0]+card[1];
                        }
                    }
                    else if(card[0]==card[1]&&card[2]==card[3]||
                            card[1]==card[2]&&card[3]==card[4]||
                            card[0]==card[1]&&card[3]==card[4])
                    {
                        p[i].dj=3;
                        if(card[0]==card[1]&&card[2]==card[3])
                        {
                            p[i].dj3_1=card[3];
                            p[i].dj3_2=card[0];
                            p[i].dj3_3=card[4];
                        }
                        else if(card[1]==card[2]&&card[3]==card[4])
                        {
                            p[i].dj3_1=card[4];
                            p[i].dj3_2=card[1];
                            p[i].dj3_3=card[0];
                        }
                        else
                        {
                            p[i].dj3_1=card[4];
                            p[i].dj3_2=card[0];
                            p[i].dj3_3=card[2];
                        }
                    }
                    else if(card[0]==card[1]||card[1]==card[2]||
                            card[2]==card[3]||card[3]==card[4])
                    {
                        p[i].dj=2;
                        if(card[0]==card[1])
                        {
                            p[i].dj2_1=card[0];
                            p[i].dj2_2=card[2]+card[3]+card[4];
                        }
                        else if(card[1]==card[2])
                        {
                            p[i].dj2_1=card[1];
                            p[i].dj2_2=card[0]+card[3]+card[4];
                        }
                        else if(card[2]==card[3])
                        {
                            p[i].dj2_1=card[2];
                            p[i].dj2_2=card[0]+card[1]+card[4];
                        }
                        else
                        {
                            p[i].dj2_1=card[3];
                            p[i].dj2_2=card[0]+card[1]+card[2];
                        }
                    }
                    else
                    {
                        p[i].dj=1;
                        p[i].dj1=card[0]+card[1]+card[2]+card[3]+card[4];
                    }
                }
            }
          // cout<<"dj="<<p[i].dj<<endl;
        }
        sort(p,p+n,cmp);
        for(int i=0; i<n; i++)
        {
            cout<<p[i].name<<endl;
        }
    }
}

