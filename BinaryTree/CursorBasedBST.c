#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
     int data;
     int RC;
     int LC;
} nodeType;

typedef struct {
     nodeType NODES[MAX];
     int avail;
} VH;

typedef enum {FALSE, TRUE} BOOL;

void initialize (int *nodePtr, VH *bst);
void insertElem (int *nodePtr, VH *bst, int elem) ;
int allocSpace (VH *list);
BOOL isMember (int *head, VH bst, int elem);
void deleteElem (int *nodePtr, VH *bst, int elem);

int main () {
     system ("cls");
     int root;
     VH myBst;

     BOOL ans = TRUE;
     int val;

     printf("\n<< 0. Initialize Cursor Based Binary Search Tree >>\n");
     initialize (&root, &myBst);
     if (root == -1) {
          printf("\tTree is empty.");
     }

     printf("\n<< 1. Inserting Elements Into Tree >>\n");
     do {
          printf("\n\tInsert an element? <1-yes/0-no>\n\tAnswer: ");
          scanf("%d",  &ans);
          if (ans == TRUE) {
               printf("\tInput elem to insert into CB BST: ");
               scanf("%d", &val);
               insertElem (&root, &myBst, val);
          }
     } while (ans == TRUE);

     printf("\n\n");
     return 0;
}

void initialize (int *nodePtr, VH *bst) {
     int i;
     *nodePtr = -1;
     bst->avail = 0;
     for (i = 0; i < MAX; ++i) {
          bst->NODES[i].LC = -1;
          bst->NODES[i].RC = (i != MAX-1) ? i+1: -1;
     }
}

void insertElem (int *nodePtr, VH *bst, int elem) {
     if (isMember (nodePtr, *bst, elem) == FALSE) {
          if (*nodePtr == -1) {
               printf("\tElement is unique. Inserting into tree...\n");
               int idxAvail = allocSpace (bst);
               bst->NODES[idxAvail].data = elem;
               *nodePtr = idxAvail;
          } else {
               (elem < bst->NODES[*nodePtr].data) ? insertElem (&bst->NODES[*nodePtr].LC, bst, elem): insertElem (&bst->NODES[*nodePtr].RC, bst, elem);
          }
     } else {
          printf("\tElement is not unique.\n");
     }
}

int allocSpace (VH *list) {
     if (list->avail != -1) {
          int temp;
          temp = list->avail;
          list->avail = list->NODES[temp].RC;
          return temp;
     }
}

BOOL isMember (int *head, VH bst, int elem) {
     if (*head == -1) {           
          return FALSE;
     } else if (bst.NODES[*head].data == elem) {
          return TRUE;
     } else {
          return (elem < bst.NODES[*head].data) ? isMember (&(bst.NODES[*head].LC), bst, elem): isMember (&(bst.NODES[*head].RC), bst, elem);
     }
}

void deleteElem (int *nodePtr, VH *bst, int elem) {
}