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
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    EPtr L = (EPtr)malloc(sizeof(Etype));

    initialize(L);

    for(int i = 0; i < 8; i++){
        insertPos(L, i, i);
    }
    printf("List after inserting at position:");
    display(L);

    deletePos(L, 6);
    printf("\nList after deleting at position:");
    display(L);

    int data;
    printf("\nEnter data: ");
    scanf("%d", &data);
    int pos = locate(L, data);
    printf("Locating data %d at position %d", data, pos);

    int getPos;
    printf("\nEnter position: ");
    scanf("%d", &getPos);
    int retPos = retrieve(L, getPos);
    if(retPos != -1){
        printf("Element retrieved from position %d is %d", getPos, retPos);
    }else{
        printf("No element retrieved.");
    }

    insertSorted(L, 6);
    display(L);

    makeNULL(L);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    
    int i;
    
    if(L->count < MAX){
        if(position >= 0 && position <= L->count){
            for(i = L->count - 1; i != position - 1; i--){
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
    int i;
    if(position <= L->count && position >= 0){
        for(i = 0; i + 1 != position; i++ ){

        }

        if(i + 1 == position){
            return L->elem[i];
        }else{
            return -1;
        }
    }
}

void insertSorted(EPtr L, int data){
    int i;
    if(L->count < MAX){
        for(i = L->count - 1; i >= 0 && data < L->elem[i]; i--){
            L->elem[i + 1] = L->elem[i];
        }

        L->elem[i + 1] = data;
        L->count++;
    }

}

void display(EPtr L){

    for(int i = 0; i < L->count - 1; i++){
        printf("%d ", L->elem[i]);
    }

}

void makeNULL(EPtr L){
    free(L);
}