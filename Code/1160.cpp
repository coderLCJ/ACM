#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],n;
void print(){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) sum+=a[i][j];
            if(i+j==n-1) sum+=a[i][j];
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<sum-a[n/2][n/2]<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    int now=1,x=n/2,y=n/2,q=0,path=1,w=0,e=0,r=0;
    a[x][y]=now++;
    while(now<=n*n){
        while(++q<=path){
            y++;
            a[x][y]=now;
            now++;
            if(now>n*n){
                print();
                return 0;
            }
        }
        while(++w<=path){
            x--;
            a[x][y]=now;
            now++;
            if(now>n*n){
                print();
                return 0;
            }
        }
        path++;
        q=0;
        w=0;
        while(++e<=path){
            --y;
            a[x][y]=now;
            now++;
            if(now>n*n){
                print();
                return 0;
            }
        }
        while(++r<=path){
            ++x;
            a[x][y]=now;
            now++;
            if(now>n*n){
                print();
                return 0;
            }
        }
        path++;
        e=0;
        r=0;
    }
}
