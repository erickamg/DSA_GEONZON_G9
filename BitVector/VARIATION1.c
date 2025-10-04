#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main(){
    unsigned char set = 8*sizeof(char);

    initialize(&set);
    insert(&set, 7);
    insert(&set, 3);
    insert(&set, 6);

    delete(&set, 3);

    find(set, 6);

    return 0;
}

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){

    if(element >= 0 && element < 8){
        *set |= (1 << element);
    }

}

void delete(unsigned char *set, int element){

    if(element >= 0 && element < 8){
       *set &= ~(1 << element);
    }

}

bool find(unsigned char set, int element){

    if(element >= 0 && element < 8){
        return (set & (1 << element)) != 0;

    }

    return false;
}

unsigned char Union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B){
    return A & ~B;
}

void display(unsigned char set){
    for(int i = 0; i < 8; i++){
        if(set & (1 << i)){
            printf("%d, ", i);
        }
    }
}