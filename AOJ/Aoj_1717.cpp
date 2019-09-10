#include<cstdio>
#include<cstring>
using namespace std;
int type[1010];
char name[1010][25];
char data[1010][25];
int main()
{
    char cmd[10],str[25];
    int id=0,i;
    while(~scanf("%s",cmd)){
        if(cmd[0]=='e')  break;
        if(cmd[0]=='c'){
            scanf("%s%d%s",name[id],&type[id],data[id]);
            for(i=id-1;i>=0;i--)
                if(!strcmp(name[id],name[i])){
                    strcpy(data[i],data[id]);
                    type[i]=type[id];
                    id--;
                }
            id++;
        }
        else{
            scanf("%s",str);
            for(i=id;i>=0;i--)
               if(!strcmp(str,name[i])){
                 if(type[i])
                    strcpy(str,data[i]);
                 else{
                    printf("%s\n",data[i]);
                    break;
                 }
               }
        }
    }
    return 0;
}
