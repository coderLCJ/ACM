#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1e5+10;
struct Node{
    LL A,B;
};
Node N[MAX];
int main(){
    LL n,temp,q,Search,Max=INT_MIN;
    cin>>n>>q;
    deque<LL> k;
    for(LL i=0;i<n;i++){
        cin>>temp;
        k.push_back(temp);
        if(temp>Max)
            Max=temp;
    }
    LL Front,Second,i,v,F=k.at(0),S=k.at(1); //cout<<Max<<endl;
    for(i=1;;i++){
            Front=k.at(0);
            Second=k.at(1);
            if(Front==Max){
                 v=i;
                 break;
            }
            if(Front>Second){
                 k.push_back(Second);
                 k.erase(k.begin()+1);
            }
            else{
                 k.pop_front();
                 k.push_back(Front);
            }
            N[i].A=Front;
            N[i].B=Second;
    }

    while(q--){
        cin>>Search;
        if(Search==1){
            cout<<F<<" "<<S<<endl;
            continue;
        }
        if(Search<v){
            cout<<N[Search].A<<" "<<N[Search].B<<endl;
        }
        else{
            LL temp=(Search-v+1)%(n-1);
            if(temp==0)
                temp=n-1;
            cout<<Max<<" "<<k.at(temp)<<endl;
        }
    }
}
