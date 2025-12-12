#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 15

typedef struct{
    char tName[20];
    int pNum;
}task;

typedef struct{
    task tasks[SIZE];
    int lastNdx;
}maxHeap;

void initMaxHeap(maxHeap* MH);
void insert(maxHeap* MH, task item);
void display(maxHeap MH);
task deleteMax(maxHeap* MH);

int main(void){
    maxHeap MH;
    initMaxHeap(&MH);
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        task item;
        printf("Enter task name: ");
        scanf(" %[^\n]", item.tName);
        printf("Enter task priority: ");
        scanf("%d", &item.pNum);
        insert(&MH, item);
    }
    display(MH);
}

void initMaxHeap(maxHeap* MH){
    MH->lastNdx = -1;
}

void insert(maxHeap* MH, task item){
    if(MH->lastNdx+1 < SIZE){
        MH->tasks[++MH->lastNdx] = item;
        int cNdx = MH->lastNdx;
        int pNdx = (cNdx-1)/2;
        while(cNdx>0 && MH->tasks[cNdx].pNum > MH->tasks[pNdx].pNum){
            task temp = MH->tasks[cNdx];
            MH->tasks[cNdx] = MH->tasks[pNdx];
            MH->tasks[pNdx] = temp;
            cNdx = pNdx;
            pNdx = (pNdx-1)/2;
        }
    }
}

task deleteMax(maxHeap* MH){
    task item;
    strcpy(item.tName, "NULL");
    item.pNum = -1;
    if(MH->lastNdx!=-1){
        item = MH->tasks[0];
        MH->tasks[0] = MH->tasks[MH->lastNdx--];
        task temp = MH->tasks[0];
        int pNdx = 0;
        int lcNdx = 1;
        int rcNdx = 2;
        int bcNdx = 0;
        if(lcNdx <= MH->lastNdx && MH->tasks[lcNdx].pNum > MH->tasks[bcNdx].pNum){
            bcNdx = lcNdx;
        }
        if(rcNdx <= MH->lastNdx && MH->tasks[rcNdx].pNum > MH->tasks[bcNdx].pNum){
            bcNdx = rcNdx;
        }
        while(bcNdx!=pNdx){
            temp = MH->tasks[pNdx];
            MH->tasks[pNdx] = MH->tasks[bcNdx];
            MH->tasks[bcNdx]  = temp;
            pNdx = bcNdx;
            lcNdx = pNdx*2+1;
            rcNdx = pNdx*2+2;
            if(lcNdx<=MH->lastNdx && MH->tasks[lcNdx].pNum > MH->tasks[bcNdx].pNum){
                bcNdx = lcNdx;
            }
            if(rcNdx<= MH->lastNdx && MH->tasks[rcNdx].pNum > MH->tasks[bcNdx].pNum){
                bcNdx = rcNdx;
            }
        }
    }
    return item;
}
void display(maxHeap MH){
    while(MH.lastNdx!=-1){
        task item = deleteMax(&MH);
        printf("%s\n", item.tName);
    }
}