/* DYNAMIC ARRAY AND ACCESSED BY VALUE*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L = initialize(L);
    
    printf("Array after inserting at position:");
    for(int i = 0; i < 8; i++){
        L = insertPos(L, i + 1, i);
    }
    
    display(L);
    
    printf("Array after deleting at position: ");
    L = deletePos(L, 5);
    display(L);
    
    int loc;
    printf("Enter location of data: ");
    scanf("%d", &loc);
    if(loc <= L.count){
        int l = locate(L, loc);
        printf("\nData located at position %d: %d\n", loc, l);
    }else{
        printf("Data cannot be located.");
    }
    
    printf("\nArray after inserting sorted: ");
    L = insertSorted(L, 4);
    display(L);
    return 0;
}

List initialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    int i;
    
    if(L.count >= L.max){
        L = resize(L);
    }
    
    if(L.count < L.max){
        if(position <= L.count && position >= 0){
            for(i = L.count - 1; i >= position; i--){
                L.elemPtr[i + 1] = L.elemPtr[i];
            }
            
            L.elemPtr[position] = data;
            L.count++;
        }
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
    int i;
    
    if(L.count >= L.max){
        L = resize(L);
    }
    
    if(L.count < L.max){
       
       for(i = L.count - 1; data < L.elemPtr[i]; i--){
           L.elemPtr[i + 1] = L.elemPtr[i];
       }
       
       L.elemPtr[i] = data;
       L.count++;
       
    }
    
    return L;
}

void display(List L){
    
    for(int i = 0; i <L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
    
}

List resize(List L){

    L.elemPtr = (int*)realloc(L.elemPtr, (LENGTH * 2)*sizeof(int));
    L.max = LENGTH * 2;

    return L;
}