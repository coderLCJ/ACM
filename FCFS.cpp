#include<bits/stdc++.h>
using namespace std;
struct FCFS{
    char ID[4];
    double TJ;
    double DX;
    int NU;
    double S;
    double E;
    double Z;
};
FCFS j[100];
int n;
void in(){
    cout<<"请输入进程数:"<<endl;
    cin>>n;
    cout<<"请输入每个作业的作业号、提交时刻、作业大小(小时)"<<endl;
    for(int i=0;i<n;i++){
        cin>>j[i].ID>>j[i].TJ>>j[i].DX;
    }
    cout<<"\n进程信息如下\n-------------------------------------------------"<<endl;
    printf("作业号 \t\t提交时刻\t\t作业大小\n");
    for(int i=0;i<n;i++){
        printf("%3s %18.2f %22.1f\n",j[i].ID,j[i].TJ,j[i].DX);
    }
    puts("-------------------------------------------------");
}
void Fcfs(){
    double ks=10.0;
    for(int i=0;i<n;i++){
        j[i].NU=i+1;
        j[i].S=ks;
        int k1=int(j[i].S*100)%100;
        int k2=int(j[i].S);
        double l=j[i].DX*10;
        k2+=(k1+l*60/10)/60;
        k1=(k1+int(l*60/10))%60;
        j[i].E=double(k2*100+k1)/100;
        double temp=j[i].TJ*10;
        int p1=int(j[i].E),p2=int(j[i].E*100)%100;
        int l1=int(j[i].TJ),l2=int(temp*100/10)%100;
        j[i].Z=(p1*60+p2)-(l1*60+l2);
        ks=j[i].E;
    }

}
void put(){
    cout<<"\n调度过程如下\n--------------------------------------------------------------------------"<<endl;
    printf("作业号 \t提交时刻\t作业大小\t顺序\t开始运行\t  完成\t  周转时间\n");
    for(int i=0;i<n;i++){
         printf("%s  \t %.2f \t\t %.1f \t\t %d \t %.2f \t\t %.2f \t %.2f-%.2f=%d\n",j[i].ID,j[i].TJ,j[i].DX,j[i].NU,j[i].S,j[i].E,j[i].E,j[i].TJ,int(j[i].Z));
    }
    cout<<"--------------------------------------------------------------------------"<<endl;
}
int main(){
    in();
    Fcfs();
    put();
}
/*

J1 9.00 0.8
J2 9.10 1
J3 9.45 0.6
J4 10.00 0.4
*/
