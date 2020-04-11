#include<bits/stdc++.h>
using namespace std;
struct Student{
    int num;
    string name;
};
void after(Student *p1){
    p1->num++;
}
int main(){
    Student s1;
    s1.num=1001;
    s1.name="zhangsan";
    cout<<s1.num<<' '<<s1.name<<endl;
    after(&s1);
    cout<<s1.num<<' '<<s1.name<<endl;
}
