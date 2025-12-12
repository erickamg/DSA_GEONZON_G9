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
    Set A, B, U, I, D;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 6);

    printf("Set A: ");
    display(A);
    printf("\n");

    delete(&A, 5);
    printf("Set A after deleting 5: ");
    display(A);
    printf("\n");

    printf("Find 3 in A: %s\n", find(A, 3) ? "FOUND" : "NOT FOUND");

    Union(A, B, U);
    printf("Union: ");
    display(U);
    printf("\n");

    intersection(A, B, I);
    printf("Intersection: ");
    display(I);
    printf("\n");

    difference(A, B, D);
    printf("Difference: ");
    display(D);
    printf("\n");

    return 0;
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