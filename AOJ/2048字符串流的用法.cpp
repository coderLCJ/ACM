#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        istringstream sin(s);
        string t;
        stack<int> a;
        while(sin>>t){
            if(isdigit(t[0])){
                a.push(atoi(t.c_str()));
            }
            else{
                int x=a.top();
                a.pop();
                int y=a.top();
                a.pop();
                if(t=="+"){
                   a.push(x+y);
                }
                else if(t=="-"){
                   a.push(y-x);
                }
                else if(t=="*"){
                   a.push(x*y);
                }
                else if(t=="/"){
                   a.push(y/x);
                }
            }
        }
        cout<<a.top()<<endl;
        a.pop();
    }
}