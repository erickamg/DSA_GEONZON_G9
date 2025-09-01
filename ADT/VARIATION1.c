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

int main(){
    List L;
    L = initialize(L);
    int num = 1;
    
     for(int i = 0; i <= 5; i++){
        L.elem[i] = num;
        num++;
        L.count++;
    }
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    int x;

    if(L.count < MAX){
        if(position >= 0 && position <= L.count){
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
    
}
