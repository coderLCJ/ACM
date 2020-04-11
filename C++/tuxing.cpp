#include <iostream>
using namespace std;

class  tuxing
{
protected:
    double l;//�����߰뾶
    double s;//���
public:
    tuxing(double a=0):l(a){}
    virtual void area()=0;//
    virtual void show()
    {
        area();
    }
};
class lttx
{
protected:
    double h;//��
    double  v;//���
public :
    lttx(double a=0):h(a){}
    virtual void volum()=0;
};
class cfx:public tuxing
{
protected:
    double w;
public:
    cfx(double a=0,double b=0):tuxing(a),w(b){}
    void area()
    {
        s=l*w;
        cout <<"���������Ϊ"<<s<<endl;
    }
};

class yx:public tuxing
{
protected:
    double pi;
public:
    yx(double a=0,double b=3.14):tuxing(a),pi(b){}
    void area()
    {
        s=l*l*pi;
        cout <<"Բ�����Ϊ:"<<s<<endl;
    }
};

class cft:public cfx,public lttx
{
public:
    cft(double a=0,double b=0,double c=0):cfx(a,b),lttx(c){}
    void area()
    {
        s=l*w*2+l*h*2+h*w*2;
        cout <<  "�����������ǣ�" << s << endl;
    }
    void volum()
    {
        v=l*w*h;
        cout << "�����������" << v << endl;
    }
    void show()
    {
        area();
        volum();
    }
};

class yz:public yx,public lttx
{
public :
    yz(double a=0,double b=0):yx(a),lttx(b){}
    void area()
    {
        s=l*l*pi*2+2*l*pi*h;
        cout << "Բ���ı������:" <<s << endl;
    }
    void volum()
    {
        v=l*l*pi*h;
    }
    void show()
    {
        area();
        volum();
    }
};


int main()
{
    cfx c(12,6);
    yx y(3);
    cft ct(12,6,7);
    yz z(3,6);
    tuxing *p[4]={&c,&y,&ct,&z};
    for(int i=0;i<4;i++)
    {
        p[i]->show();
    }
    return 0;
}
