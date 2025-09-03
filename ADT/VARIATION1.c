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
    // int num = 1;
    
    //  for(int i = 0; i < 5; i++){
    //     L.elem[i] = num;
    //     num++;
    //     L.count++;
    // }

    L = insertPos(L, 1, 0);
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

}
