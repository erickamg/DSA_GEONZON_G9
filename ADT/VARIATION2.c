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
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);

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
            for(int i = L->count - 1; i != position - 1; i--){
                L->elem[i + 1] = L->elem[i];
            }

            L->elem[i] = data;
            L->count++;
        }
    }

}

void deletePos(EPtr L, int position){
    int i;

    if(position <= L->count){
        if(position >= 0 && position <= L->count){
            for(i = 0; i != position - 1; i++){
                
            }

            for(int x = i; x < L->count; x++){
                L->elem[x] = L->elem[x + 1];
            }

            L->count--;

        }
    }

}

int locate(EPtr L, int data){

    int i;

    for(i = 0; L->elem[i] != data && i < L->count; i++){
        
    }

    if(L->elem[i] == data){
        return i + 1;
    }else{
        return -1;
    }

}

int retrieve(EPtr L, int position){

    if(position <= L->count && position >= 0){
        for(int i = 0; i + 1 != position; i++ ){

        }

        if(i + 1 == position){
            return L->elem[i];
        }else{
            return -1;
        }
    }
}

void insertSorted(EPtr L, int data){

    if(){
        
    }

}