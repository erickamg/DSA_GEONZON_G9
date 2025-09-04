/* STATIC ARRAY AND ACCESSED BY VALUE */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 

typedef struct {
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate (List L, int data);
List insertSorted(List L, int data);

int main(){
    List L;
    L = initialize(L);
    int num = 1, j, d;

    for(int i = 0; i < 8; i++){
        L = insertPos(L, num, i);
        num++;
    }
    
    printf("Array after inserting at position: ");
    for(int i = 0; i < 8; i++){
        printf("%d ", L.elem[i]);
    }

    L = deletePos(L, 4);

    printf("\n");
    
    printf("\nArray after deleting at position:");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    
    printf("\n\nEnter data to locate: ");
    scanf("%d", &d);
    j = locate (L, d);
    if(j > 0){
        printf("\nData %d is located at position %d", d, j);
    }else{
        printf("\nData %d could not be located.", d, j);
    }

    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    int x;

    if(L.count < MAX){ //The array must not be full
        if(position >= 0 && position <= L.count){ //position must be valid
            for(x = L.count; x > position - 1; x--){
                L.elem[x] = L.elem[x-1];
            }
            
            L.elem[position] = data;
            L.count++;
        }
    }

    return L;
}

List deletePos(List L, int position){

    int i;

    if(position <= L.count){
        for( i = 0; i < position - 1; i++){
            
        }

        for(int x = i; x < L.count; x++){
            L.elem[x] = L.elem[x + 1];
        }

        L.count--;
    }

    return L;
}

int locate (List L, int data){

    int i, x = 0;

    for(i = 0; i <=L.count ; i++){
        if(L.elem[i] == data){
            return i + 1;
            x = 1;
        }
    }

    if(x != 1){
        return -1;
    }

}

List insertSorted(List L, int data){
    
}