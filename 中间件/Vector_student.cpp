#include<bits/stdc++.h>
using namespace std;
void menu(){
    cout<<"1.Ôö\n2.É¾\n3.¸Ä\n4.²é\n5.show\n"<<endl;
}
void add(vector<string> &s){
    string name;
    cin>>name;
    s.push_back(name);
}
void era(vector<string> &s){
    string name;
    cin>>name;
    for(auto i=s.begin();i!=s.end();i++){
        if(*i==name){
            s.erase(i);
            return ;
        }
    }
}
void cha(vector<string> &s){
    string name1,name2;
    cin>>name1>>name2;
    for(auto &p:s){
        if(p==name1){
            p=name2;
            return;
        }
    }
}
void sea(vector<string> &s){
    sort(s.begin(),s.end());
    string name;
    cin>>name;
    binary_search(s.begin(),s.end(),name)?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
void show(vector<string> &s){
    for(auto p:s){
        cout<<p<<endl;
    }
}
int main(){
    vector<string> student;
    menu();
    int T;
    string name;
    while(cin>>T){
        if(T==1){
           add(student);
        }
        else if(T==2){
           era(student);
        }
        else if(T==3){
           cha(student);
        }
        else if(T==4){
           sea(student);
        }
        else{
           show(student);
        }
    }
}

