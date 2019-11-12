#include<bits/stdc++.h>
using namespace std;
const int MAX=2*10e6;
double l[MAX+1],s[MAX+1],v[MAX+1];
int main(){
    int n;
    int t=1;
    ios::sync_with_stdio(false);
   // freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++){
            scanf("%lf",&l[i]);
        }
        for(int i=0;i<=n;i++){
            scanf("%lf",&s[i]);
        }
        for(int i=0;i<=n;i++){
            scanf("%lf",&v[i]);
        }
        double ans=0;
        int flag=0;
        for(int i=0;i<=n/2,s[0]>0;i++){
            double temp,Mintime=INT_MAX;
            int Mini,Minj;
            for(int i=0;i<n;i++){
                //cout<<s[i]<<" "<<s[i+1]<<" "<<l[i+1]<<endl;
                if(v[i]>v[i+1]){
                    temp=1.0*(s[i]-(s[i+1]+l[i+1]))/(v[i]-v[i+1]);
                    if(temp<Mintime){
                        Mintime=temp;
                        Mini=i;
                        Minj=i+1;
                    }
                }
            }
            if(Mintime==INT_MAX){
               // cout<<s[0]<<" "<<v[0]<<" "<<ans<<endl;
                printf("%.10f\n",s[0]/v[0]+ans);
                flag=1;
            }
            else if(Mintime!=INT_MAX&&s[0]-Mintime*v[0]<0){
                printf("%.10f\n",s[0]/v[0]);
                flag=1;
            }
            if(flag){
                break;
            }
            for(int i=0;i<=n;i++){
                s[i]-=v[i]*Mintime;
            }
            v[Mini]=v[Minj];
            ans+=Mintime;
            //cout<<s[0]<<" "<<ans<<endl;
        }
        if(!flag)
           printf("%.10f\n",ans);
           cout<<"t="<<t++<<endl;
    }
}
