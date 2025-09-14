/* DYNAMIC ARRAY AND ACCESSED BY POINTER */

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    List *L = (List*)malloc(sizeof(List));
    initialize(L);

    printf("Array after inserting at position: ");
    for(int i = 0; i < 10; i++){
        insertPos(L, i + 1, i);
    }
    display(L);

    printf("\nArray after deleting at position: ");
    deletePos(L, 6);
    display(L);

    int num;
    printf("\nEnter data to locate: ");
    scanf("%d", &num);
    int l = locate(L, num);
    printf("\nThe data is located at position %d", l);

    int pos;
    printf("\nEnter position to retrieve: ");
    scanf("%d", &pos);
    int r = retrieve(L, pos);
    printf("\nThe data retrieved is %d", r);

    printf("\nArray after insert sorting: ");
    insertSorted(L, 9);
    display(L);

    makeNULL(L);

    return 0;
}

void initialize(List *L){

    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;

}

void resize(List *L){

    L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr,L->max * sizeof(int));

}

void display(List *L){

    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");

}

void insertPos(List *L, int data, int position){

    if (L->count >= L->max) {
        resize(L);
    }
    

    if(position <= L->count && position >= 0){
        for(int i = L->count - 1; i >= position; i--){
            L->elemPtr[i + 1] = L->elemPtr[i];
        }

        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    int i, x;

    if(position <= L->count && position - 1 >= 0){
        for(i = 0; i != position - 1; i++){

        }

        for(x = i; x != L->count -1; x++){
            L->elemPtr[x] = L->elemPtr[x + 1];
        }

        L->count--;
    }
}

int locate(List *L, int data){

    int i;

    for(i = 0; L->elemPtr[i] != data; i++){

    }

    if(L->elemPtr[i] == data){
        return i + 1;
    }else{
        return -1;
    }

}

int retrieve(List *L, int position){

    int i;

    for(i = 0; i != position - 1; i++){

    }

    if(position == i + 1){
        return L->elemPtr[i];
    }else{
        return -1;
    }

}

void insertSorted(List *L, int data){
    
    int i;

    if(L->count >= L->max){
        resize(L);
    }

    for(i = L->count - 1; data < L->elemPtr[i] && i >= 0; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }

    L->elemPtr[i + 1] = data;
    L->count++;
}

void makeNULL(List *L){

    free(L->elemPtr);

}