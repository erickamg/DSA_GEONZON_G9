#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for BST of strings */
typedef struct node {
    char *key;             /* pointer to dynamically-allocated string */
    struct node *LC;       /* left child */
    struct node *RC;       /* right child */
} Node, *BST;

/* Helper: create a new node with its own copy of key_data */
Node *create_node(const char *key_data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "malloc failed for node\n");
        exit(EXIT_FAILURE);
    }

    /* allocate and copy the string so each node "owns" its key */
    size_t len = strlen(key_data) + 1;
    n->key = malloc(len);
    if (n->key == NULL) {
        fprintf(stderr, "malloc failed for key\n");
        free(n);
        exit(EXIT_FAILURE);
    }
    memcpy(n->key, key_data, len); /* copy including terminating '\0' */

    n->LC = NULL;
    n->RC = NULL;
    return n;
}

/* Insert key_data into the BST. Duplicates are ignored. */
void insert(BST *tree, const char *key_data) {
    /* If the subtree is empty, create and attach a new node */
    if (*tree == NULL) {
        *tree = create_node(key_data);
        return;
    }

    /* Compare the new key with the current node's key */
    int cmp = strcmp(key_data, (*tree)->key);

    if (cmp < 0) {
        /* new key is alphabetically before current key -> go left */
        insert(&((*tree)->LC), key_data);
    } else if (cmp > 0) {
        /* new key is alphabetically after current key -> go right */
        insert(&((*tree)->RC), key_data);
    } else {
        /* cmp == 0: duplicate — we choose to ignore duplicates */
        /* could print a message or handle duplicates differently */
        return;
    }
}

/* In-order traversal: left, root, right */
void inorderTraversal(BST tree) {
    if (tree == NULL) return;
    inorderTraversal(tree->LC);
    printf("%s ", tree->key);
    inorderTraversal(tree->RC);
}

/* Pre-order traversal: root, left, right */
void preorderTraversal(BST tree) {
    if (tree == NULL) return;
    printf("%s ", tree->key);
    preorderTraversal(tree->LC);
    preorderTraversal(tree->RC);
}

/* Post-order traversal: left, right, root */
void postorderTraversal(BST tree) {
    if (tree == NULL) return;
    postorderTraversal(tree->LC);
    postorderTraversal(tree->RC);
    printf("%s ", tree->key);
}

/* Frees node->key and the node itself recursively */
void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);

        if (tree->key != NULL) {
            free(tree->key);
        }
        free(tree);
    }
}

int main(void) {
    BST myTree = NULL;

    insert(&myTree, "Mango");
    insert(&myTree, "Apple");
    insert(&myTree, "Pineapple");
    insert(&myTree, "Banana");
    insert(&myTree, "Grape");
    insert(&myTree, "Orange");
    insert(&myTree, "Kiwi");

    /* Test duplicate handling */
    insert(&myTree, "Mango");

    printf("In-Order Traversal:   ");
    inorderTraversal(myTree);
    printf("\n");

    printf("Pre-Order Traversal:  ");
    preorderTraversal(myTree);
    printf("\n");

    printf("Post-Order Traversal: ");
    postorderTraversal(myTree);
    printf("\n");

    destroyTree(myTree);
    myTree = NULL;

    return 0;
}
