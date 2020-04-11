#include<bits/stdc++.h>
using namespace std;
class Student{
public:
    void setstudent(int n1,string n2){
         num=n1;
         name=n2;
    }
    void after(){
         num++;
    }
    void display(){
         cout<<num<<' '<<name<<endl;
    }
    int num;
    string name;
};

int main(){
    Student s1;
    s1.setstudent(1001,"zhangsan");
    s1.display();
    s1.after();
    s1.display();0
}

