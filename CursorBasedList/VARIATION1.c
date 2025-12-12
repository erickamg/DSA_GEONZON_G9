#include <stdio.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem, int pos);
void insertSorted(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);

int main(){

    return 0;
}

void initialize(VHeap *V){
    V->avail = 0;
    
    for(int i = 0; i < MAX; i++){
        V->H[i].next = i + 1;

        if(i == MAX - 1){
            V->H[i].next = -1;
        }
    }
}

int allocSpace(VHeap* V){
    if(V->avail != -1){
        int newCell = V->avail;

        V->avail = V->H[newCell].next;

        return newCell;
    }else{
        return -1;
    }
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);

    if (newCell != -1) {
        V->H[newCell].elem = elem;

        V->H[newCell].next = *L;
        *L = newCell;
    }
    
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
 
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
    }else{
        return;
    }

    if(*L == -1){
        *L = newCell;
    }else{
        int trav = *L;

        while(V->H[trav].next != -1){
            trav = V->H[trav].next;
        }

        V->H[trav].next = newCell; 
    }

}

void insertPos(int* L, VHeap* V, int elem, int pos){
    
    
    int newCell = allocSpace(V);
    
    if(newCell == -1) return;

    V->H[newCell].elem = elem;

    int trav = *L;
    int before = -1;
    int after = 1;

    if(*L == -1){
        *L = newCell;
        return;

    }else{
        while (trav != -1 && after < pos) {
            before = trav;
            trav = V->H[trav].next;
            after++;
        }
        
    }

    V->H[before].next = newCell;
    V->H[newCell].next = trav;

}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell == -1) return;

    V->H[newCell].elem = elem;
    
    int* trav = &L;
    
    while(*trav != -1 && V->H[*trav].elem < elem) {
        trav = &V->H[*trav].next;
    }

    V->H[newCell].next = trav;
    *trav = newCell;
}

void delete(int* L, VHeap* V, int elem){
    int* trav = L;
    int before = -1;

    while (V->H[*trav].elem != elem) {
        before = *trav;
        *trav = &V->H[*trav].next;
    }

    V->H[before].next = V->H[*trav].next;

    deallocSpace(V, trav);

}

void deleteAllOccurrence(int* L, VHeap* V, int elem){
    int* trav = L;

    while (*trav != -1){

        if(V->H[*trav].elem == elem){
            int temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        }else{
            *trav = &V->H[*trav].next;
        }
    }
    
}

void display(int L, VHeap V){
    int* trav = L;

    while(*trav != -1){
        printf("*d\n", V.H[*trav].elem);
        *trav = V.H[*trav].next;
    }
}