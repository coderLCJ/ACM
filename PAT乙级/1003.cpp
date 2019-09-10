#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int flag=0,len=s.size();
    	for(int i=0;i<len;i++){
    		if(s[i]!='P'&&s[i]!='A'&&s[i]!='T'){
    			flag=0;
    			break;
			}
			if(s[i]=='P'){
               if(s[i+1]=='A'&&s[i+2]=='T'){
                  flag=1;
                  if((len-3)%2!=0){
                      flag=0;
                      break;
                  }
                  for(int j=0,k=len-1;j<i;j++,k--){
                      if(s[j]!='A'||s[k]!='A'){
                         flag=0;
                         break;
                      }
                  }
               }
               else if(s[i+1]=='A'&&s[i+2]=='A'&&s[i+3]=='T'){
                  flag=1;
                  if(len-i-1<i+1){
                     flag=0;
                     break;
                  }
                  for(int k=0;k<i;k++){
                     if(s[k]!='A'){
                        flag=0;
                        break;
                     }
                  }
                  for(int k=i+4;k<len;k++){
                     if(s[k]!='A'){
                        flag=0;
                        break;
                     }
                  }
               }
               else{
                  flag=0;
                  break;
               }
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
}
