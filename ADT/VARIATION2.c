/* STATIC ARRAY AND ACCESSED BY POINTER */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);

int main(){
    EPtr L;
}

void initialize(EPtr L){
    L->count = 0;

    return L;
}

void insertPos(EPtr L, int data, int position){

    if(L->count < MAX){
        if(position >= 0 && position <= L->count){
            for(int i = L->count - 1; i != position - 1; i++){
                L->elem[i + 1] = L->elem[i];
            }

            L->elem[i] = data;
            L->count++;
        }
    }

}

void deletePos(EPtr L, int position){

    if(position <= L->count){

    }
    
}

