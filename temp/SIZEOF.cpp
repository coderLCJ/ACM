#include<bits/stdc++.h>
using namespace std;
///共用体算最大的
///结构体中有共用体时算共用体最大的类型字节
typedef union{
    long i;
    int k[5];
    char c;
}DATE;
struct A{
    DATE D;
    int a;
};
int main(){
    cout<<sizeof(DATE)<<endl;
    cout<<sizeof(A);
}
