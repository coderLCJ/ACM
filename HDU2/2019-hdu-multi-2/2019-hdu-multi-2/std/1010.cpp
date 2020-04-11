#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=(a); i<(b); i++)
typedef long long ll;
int p=1e6+3,n,ret=1;
int main() {

    while (scanf("%d",&n)!=EOF) {
        if (n>=p)  {printf("%d\n",0); continue;}
        ret=1; rep(i,1,n+1) ret=(ll)ret*i%p;
        printf("%d\n",ret);
    }

    return 0;
}

