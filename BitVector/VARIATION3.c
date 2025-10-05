#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
void Union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main(){

}

void initialize(Set *set){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){
        *set[i] = false;
    }
}

void insert(Set *set, int element){
    if(element >= 0 && element < 8){
        *set[element] = true;
    }
}

void delete(Set *set, int element){
    if(element >= 0 && element < 8){
        *set[element] = false;
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < 8){
        return set[element];
    }
}

void Union(Set A, Set B, Set C){

    for(int i = 0; i < 8; i++){
        C[i] = A[i] | B[i];
    }

}

void intersection(Set A, Set B, Set C){

    for(int i = 0; i < 8; i++){
        C[i] = A[i] & B[i];
    }

}

void difference(Set A, Set B, Set C){

    for(int i = 0; i < 8; i++){
        C[i] = A[i] & ~B[i];
    }

}

void display(Set set){
    for(int i = 0; i < 8; i++){
        printf("%d, ", set[i]);
    }
}