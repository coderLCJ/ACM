#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        double l[n+1],s[n+1],v[n+1];
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
        while(s[0]>0){
            double temp,Mintime=INT_MAX,Min[n];
            int Mini,Minj;
            for(int i=0;i<n;i++){
                //cout<<s[i]<<" "<<s[i+1]<<" "<<l[i+1]<<endl;
                if(v[i]>v[i+1]){
                    temp=1.0*(s[i]-(s[i+1]+l[i+1]))/(v[i]-v[i+1]);
                    /*
                    if(temp<Mintime){
                        Mintime=temp;
                        Mini=i;
                        Minj=i+1;
                    }
                    */
                    Min[i]=temp;
                }
            }
            for(int i=0;i<n;i++)cout<<Min[i]<<endl;

            //cout<<s[0]<<" "<<ans<<endl;
        }
        if(!flag)
           printf("%.10f",ans);
    }
}
