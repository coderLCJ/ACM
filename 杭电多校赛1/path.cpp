#include<bits/stdc++.h>
#define MAX 16843009
#define MAXSIZE 666
using namespace std;
int arcs[MAXSIZE][MAXSIZE];
int findmin(int disk[],bool S[],int n){
    int k=0,min=MAX;
    for(int i=0;i<n;i++){
        if(!S[i]&&disk[i]<min){
            min=disk[i];
            k=i;
        }
    }
     if(min==MAX)
       return -1;
     return k;
}
void print(int d[],int p[],int n){
    cout<<d[n-1];
    cout<<endl;
}
void Dijkstra(int v,int n){    //v为出发点
    bool S[MAXSIZE]={false};
    int disk[n],path[n];
    for(int i=0;i<n;i++){
        disk[i]=arcs[v][i];
        if(disk[i]!=MAX)
            path[i]=v;
        else
            path[i]=-1;  //无前驱
    }
    S[v]=true;  disk[v]=0;
    for(int i=0;i<n;i++){
        v=findmin(disk,S,n);
        if(v==-1){
            print(disk,path,n);
            return;
        }
        //cout<<v<<endl;
        S[v]=true;
        for(int j=0;j<n;j++){
            //cout<<arcs[v][j]+disk[v]<<disk[j]<<endl;
            if(!S[j]&&(arcs[v][j]+disk[v]<disk[j])){
                disk[j]=arcs[v][j]+disk[v];
                path[j]=v;

            }
        }
    }
}
int main(){
    int i,j,d,n,m;
    while(cin>>n>>m&&(n!=0||m!=0)){
        memset(arcs,1,sizeof(arcs));
        while(m--){
           cin>>i>>j>>d;
           arcs[i-1][j-1]=d;
           arcs[j-1][i-1]=d;
        }
        Dijkstra(0,n);
    }
}
