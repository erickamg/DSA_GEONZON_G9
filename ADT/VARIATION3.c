/* DYNAMIC ARRAY AND ACCESSED BY VALUE*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List intialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L;
}

List intialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    int i;
    
    if(L.count < L.max){
        if(position - 1 <= L.count && position >= 0){
            for(i = 0; i != position - 1; i++){
                L.elemPtr[i + 1] = L.elemPtr[i];
            }
            
            L.elemPtr[i] = data;
            L.count++;
        }
    }else{
        resize(L);
        L = insertPos(L, data, position);
    }

    return L;
}

List deletePos(List L, int position){
    
    int i, x;
    
    if(position <= L.count){
        for(i = 0; i != position - 1; i++){
            
        }
        
        for(x = i; x <= L.count - 1; x++){
            L.elemPtr[x] = L.elemPtr[x + 1];
        }
        
        L.count--;
    }
    
    return L;
}

int locate(List L, int data){
    
    int i;
    
    for(i = 0; L.elemPtr[i] != data; i++){
        
    }
    
    if(L.elemPtr[i] == data){
        return i + 1;
    }else{
        return -1;
    }
}

List insertSorted(List L, int data){
    
    if(L.count < L.max){
       
       for(int i = L.count - 1; data < L.elemPtr[i]; i--){
           L.elemPtr[i + 1] = L.elemPtr[i];
       }
       
       L.elemPtr[i] = data;
       L.count++;
       
    }else{
        resize(L);
        L = insertSorted(L, data);
    }
    
    return L;
}

void display(List L){
    
    for(int i = 0; i <L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    
}

List resize(List L){

    L.elemPtr = (int*)realloc(L.elemPtr, (LENGTH * 2)*sizeof(int));
    L.max = LENGTH * 2;

    return L;
}