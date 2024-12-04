#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{int level; char name[17];}Player;
typedef struct{int membercount,minl,maxl; Player players[300];}Room;

int comparep(const void*x,const void*y){
    return strcmp(((Player*)x)->name,((Player*)y)->name);
}
int main(){
    int totalp,roommax,roomcount=0;
    Player plist[300];
    Room rlist[300]={0};
    scanf("%d %d",&totalp,&roommax);
    for(int i=0; i<totalp; i++)
        scanf("%d %s",&plist[i].level,plist[i].name);
    for(int i=0; i<totalp; i++){
        int assigned=0;
        for(int j=0; j<roomcount; j++){
            if(rlist[j].membercount<roommax && plist[i].level>=rlist[j].minl && plist[i].level<=rlist[j].maxl){
                rlist[j].players[rlist[j].membercount++]=plist[i];
                assigned=1;
                break;
            }
        }
        if(!assigned){
            rlist[roomcount].membercount=1;
            rlist[roomcount].minl=plist[i].level-10;
            rlist[roomcount].maxl=plist[i].level+10;
            rlist[roomcount++].players[0]=plist[i];
        }
    }
    for(int i=0; i<roomcount; i++){
        qsort(rlist[i].players,rlist[i].membercount,sizeof(Player),comparep);
        printf("%s\n",rlist[i].membercount==roommax ? "Started!":"Waiting!");
        for(int j=0; j<rlist[i].membercount; j++)
            printf("%d %s\n",rlist[i].players[j].level,rlist[i].players[j].name);
    }
    return 0;
}
