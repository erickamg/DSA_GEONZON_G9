#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int field : 8;
}Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set Union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
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

    U = Union(A, B);
    printf("Union: ");
    display(U);
    printf("\n");

    I = intersection(A, B);
    printf("Intersection: ");
    display(I);
    printf("\n");

    D = difference(A, B);
    printf("Difference: ");
    display(D);
    printf("\n");

    return 0;

}

void initialize(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < 8){
        return (set.field & (1 << element)) !=0;
    }

    return false;
}

Set Union(Set A, Set B){
    A.field |= B.field;
    return A;
}

Set intersection(Set A, Set B){
    A.field &= B.field;
    return A;
}

Set difference(Set A, Set B){
    A.field &= ~B.field;
    return A;
}

void display(Set set){
    for(int i = 0; i < 8; i++){
        if(set.field & (1 << i)){
            printf("%d, ", i);
        }
    }
}