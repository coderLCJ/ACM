#include<bits/stdc++.h>
using namespace std;
const double PI=atan(1)*4;
map<string ,double> Answer;            //答案数组
class Line{                            //线
public:
    Line(double t){
        l=t;
    }
    void show(){
        for(auto p:Answer){
            cout<<p.first<<' '<<p.second<<endl;
        }
    }
    virtual void Get_answer(){
        Answer["1 Length = "]=l;
    }
protected:
    double l;                             //长度
};

class Rectangle:public Line{              //长方形
public:
    Rectangle(double r,double l):Line(l){
        R=r;
        L=l;
    }
    virtual void Get_answer(){
        Answer["2 S.Rectangle = "]=L*R;
    }
protected:
    double R,L;                          //长,宽
};

class Circle:public Line{                //圆
public:
    Circle(double t,double p):Line(t){
        R=t;
        PI=p;
    }
    virtual void Get_answer(){
        Answer["3 S.Circle = "]=PI*R*R;
    }
protected:
    double PI,R;                       //圆周率,半径
};

class Cuboid:public Rectangle{         //长方体
public:
    Cuboid(double h,double r,double t):Rectangle(r,t){
        H=h;
        R=r;
        L=t;
    }
    virtual void Get_answer(){
        Answer["4 S.Cuboid = "]=L*R*2+L*H*2+H*R*2;
        Answer["5 V.Cuboid = "]=L*R*H;
    }
protected:
    double L,R,H;                       //长,宽,高
};

class Circular:public Circle{           //圆柱体
public:
    Circular(double r,double p,double h):Circle(r,p){
        R=r;
        P=p;
        H=h;
    }
    virtual void Get_answer(){
        Answer["6 S.Circular = "]=PI*R*R*2+2*PI*R*H;
        Answer["7 V.Circular = "]=PI*R*R*H;
    }
protected:
    double R,P,H;                        //半径,圆周率,高
};
/// 1.无多余属性 2.继承 3.多态
int main(int argc, char const *argv[]){
    ///构造
    Line      t0(5);
    Rectangle t1(3,7);
    Circle    t2(2,PI);
    Cuboid    t3(1,3,4);
    Circular  t4(2,PI,2);
    ///求解
    Line *p;
    p=&t0,p->Get_answer();
    p=&t1,p->Get_answer();
    p=&t2,p->Get_answer();
    p=&t3,p->Get_answer();
    p=&t4,p->Get_answer();
    ///输出
    p->show();
}
