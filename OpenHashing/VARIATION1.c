#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICT_SIZE 10
#define MAX_LIST 5

typedef struct {
    int elems[MAX_LIST];
    int count;
} List;

typedef List Dictionary[DICT_SIZE];

void initDictionary(Dictionary D) {
    for (int i = 0; i < DICT_SIZE; i++) {
        D[i].count = 0;
    }
}

int hash(int value) {
    return value % DICT_SIZE;
}

void insert(Dictionary D, int value) {
    int idx = hash(value);
    
    if (D[idx].count >= MAX_LIST) {
        printf("Bucket %d is full! Cannot insert %d.\n", idx, value);
        return;
    }
    
    for (int i = 0; i < D[idx].count; i++) {
        if (D[idx].elems[i] == value) return;
    }
    
    D[idx].elems[D[idx].count] = value;
    D[idx].count++;
}

void delete(Dictionary D, int value) {
    int idx = hash(value);
    
    for (int i = 0; i < D[idx].count; i++) {
        if (D[idx].elems[i] == value) {
            for (int j = i; j < D[idx].count - 1; j++) {
                D[idx].elems[j] = D[idx].elems[j+1];
            }
            D[idx].count--;
            return;
        }
    }
}

bool member(Dictionary D, int value) {
    int idx = hash(value);
    for (int i = 0; i < D[idx].count; i++) {
        if (D[idx].elems[i] == value) {
            return true;
        }
    }
    return false;
}

void display(Dictionary D) {
    printf("\n--- Dictionary ---\n");
    for (int i = 0; i < DICT_SIZE; i++) {
        printf("[%d]: ", i);
        if (D[i].count == 0) {
            printf("EMPTY");
        } else {
            for (int j = 0; j < D[i].count; j++) {
                printf("%d ", D[i].elems[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Dictionary D;
    initDictionary(D);
    
    insert(D, 10);
    insert(D, 20);
    insert(D, 33);
    insert(D, 43);
    insert(D, 5);
    
    display(D);
    
    printf("\nIs 20 a member? %s\n", member(D, 20) ? "Yes" : "No");
    printf("Is 99 a member? %s\n", member(D, 99) ? "Yes" : "No");
    
    printf("\nDeleting 20...\n");
    delete(D, 20);
    display(D);
    
    return 0;
}