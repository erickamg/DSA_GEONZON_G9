#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lc;
    struct node *rc;
} Node, *BST;

Node* findMin(Node* node) {
    while(node->lc != NULL) {
        node = node->lc;
    }
    return node;
}

void insert(BST* B, int value) {
    BST* trav = B;
    while(*trav != NULL && (*trav)->data != value) {
        trav = ((*trav)->data > value ? &(*trav)->lc : &(*trav)->rc);
    }
    
    if(*trav == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->lc = NULL;
        newNode->rc = NULL;
        newNode->data = value;
        
        *trav = newNode;
    }
}

void deleteNode(BST* B, int value) {
    BST* trav = B;
    while(*trav != NULL && (*trav)->data != value) {
        trav = ((*trav)->data > value ? &(*trav)->lc : &(*trav)->rc);
    }
    
    if(*trav == NULL) {
        return;
    }
    
    // Node with only one child or no child
    if((*trav)->lc == NULL) {
        Node *temp = *trav;
        *trav = (*trav)->rc;
        free(temp);
    } else if((*trav)->rc == NULL) {
        Node *temp = *trav;
        *trav = (*trav)->lc;
        free(temp);
    } else { 
        // Node with two children: 
        Node *temp = findMin((*trav)->rc);
        
        (*trav)->data = temp->data;
        
        deleteNode(&(*trav)->rc, temp->data);
    }
}

void printTree(BST B) {
    if(B != NULL) {
        printTree(B->lc);
        printf("%d ", B->data);
        printTree(B->rc);
    }
}

int main() {
    BST B = NULL;
    
    insert(&B, 10);
    insert(&B, 5);
    insert(&B, 15);
    insert(&B, 3);
    insert(&B, 7);
    insert(&B, 12);
    insert(&B, 18);
    
    printf("Inorder (Sorted): ");
    printTree(B);
    printf("\n");
    
    printf("Deleting 15 (Node with 2 children)...\n");
    deleteNode(&B, 15);
    
    printf("Inorder After Delete: ");
    printTree(B);
    printf("\n");
    
    return 0;
}