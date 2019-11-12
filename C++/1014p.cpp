#include<bits/stdc++.h>
using namespace std;
int main(){
    string A,B,C,D;
    string ans[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin>>A>>B>>C>>D;
    int len1=A.size()>B.size()?B.size():A.size();
    int len2=C.size()>D.size()?C.size():D.size();
    int time=1,day,hour,mini;
    for(int i=0;i<len1;i++){
        if(A[i]==B[i]&&A[i]>='A'&&A[i]<='G'&&time==1){
             day=A[i]-'A';
             time++;
        }
        else if(time==2&&A[i]==B[i]){
             if(A[i]>='A'&&A[i]<='N'){
                hour=A[i]-'A'+10;
                break;
             }
             else if(A[i]>='0'&&A[i]<='9'){
                hour=A[i]-'0';
                break;
             }
        }
    }
    for(int i=0;i<len2;i++){
        if(isalpha(C[i])&&C[i]==D[i]){
            mini=i;
            break;
        }
    }
    cout<<ans[day]<<" ";
    printf("%02d:%02d\n",hour,mini);
}
