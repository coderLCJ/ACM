#include<bits/stdc++.h>
using namespace std;
///������������
///�ṹ�����й�����ʱ�㹲�������������ֽ�
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
