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
void display(unsigned char set);

int main(){
    Set set;

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