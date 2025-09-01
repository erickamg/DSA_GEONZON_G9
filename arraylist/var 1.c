#include <stdio.h>
#include <stdlib.h>
#define MAX 10 

typedef struct {
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);

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
    
    return L;
}