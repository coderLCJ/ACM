#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100100
using namespace std;
int n,d,p[N];
char ans[N],dec[N];
int main(){
    scanf("%d%d",&n,&d);
    sprintf(ans,"%d.",n/d);
    n%=d;
    memset(p,-1,sizeof p);
    for(int i=0;;i++){
        p[n]=i;
        n*=10;
        dec[i]=n/d+'0';
        n%=d;
        if(!n){
            sprintf(ans+strlen(ans),"%s",dec);
            break;
        }
        if(p[n]!=-1){
            sprintf(ans+strlen(ans),"%.*s(%s)",p[n],dec,dec+p[n]);
            break;
        }
    }
    for(int i=0;ans[i];i+=76)
        printf("%.76s\n",ans+i);
    return 0;
}
