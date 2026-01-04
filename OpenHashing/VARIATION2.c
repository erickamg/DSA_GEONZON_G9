#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICT_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node, *List;

typedef List Dictionary[DICT_SIZE];


void initDictionary(Dictionary D) {
    for (int i = 0; i < DICT_SIZE; i++) {
        D[i] = NULL;
    }
}

int hash(int value) {
    return value % DICT_SIZE;
}

void insert(Dictionary D, int value) {
    int idx = hash(value);
    
    Node* trav = D[idx];
    while(trav != NULL) {
        if (trav->data == value) return;
        trav = trav->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = D[idx];
    D[idx] = newNode;
}

void delete(Dictionary D, int value) {
    int idx = hash(value);
    Node* trav = D[idx];
    Node* prev = NULL;
    
    while (trav != NULL) {
        if (trav->data == value) {
            if (prev == NULL) {
                D[idx] = trav->next;
            } else {
                prev->next = trav->next;
            }
            free(trav);
            return;
        }
        prev = trav;
        trav = trav->next;
    }
}

bool member(Dictionary D, int value) {
    int idx = hash(value);
    Node* trav = D[idx];
    while (trav != NULL) {
        if (trav->data == value) return true;
        trav = trav->next;
    }
    return false;
}

void display(Dictionary D) {
    printf("\n--- Dictionary Content ---\n");
    for (int i = 0; i < DICT_SIZE; i++) {
        printf("[%d]: ", i);
        Node* trav = D[i];
        while (trav != NULL) {
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Dictionary D;
    initDictionary(D);
    
    insert(D, 15);
    insert(D, 25);
    insert(D, 35);
    insert(D, 7);
    insert(D, 10);
    
    display(D);
    
    printf("\nIs 25 a member? %s\n", member(D, 25) ? "Yes" : "No");
    
    printf("\nDeleting 25...\n");
    delete(D, 25);
    display(D);
    
    return 0;
}