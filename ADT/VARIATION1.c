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

int main(){
    List L;
    L = initialize(L);
    int num = 1, j;

    for(int i = 0; i < 8; i++){
        L = insertPos(L, num, i);
        num++;
    }

    for(int i = 0; i < 8; i++){
        printf("%d ", L.elem[i]);
    }

    L = deletePos(L, 4);

    printf("\n");

    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }

    j = locate (L, 6);
    printf("\nData 6 is located at position %d", j);

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

    int i, x;

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

