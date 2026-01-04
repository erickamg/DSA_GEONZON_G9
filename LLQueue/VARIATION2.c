#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front; // Points to the LAST node (Tail)
    Node* rear;  // Points to the FIRST node (Head)
} Queue;

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->rear == NULL);
}

// Insert at Rear
void enqueue(Queue* q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = q->rear;
    
    q->rear = newNode;
    
    if (q->front == NULL) {
        q->front = newNode;
    }
}

// Remove from Front
int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    
    int data;
    
    // Case 1: Only one node
    if (q->rear == q->front) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } 
    // Case 2: More than one node
    else {
        Node *trav = q->rear;
        while (trav->next != q->front) {
            trav = trav->next;
        }
        
        data = q->front->data;
        free(q->front);
        
        q->front = trav;
        q->front->next = NULL;
    }
    
    return data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    
    printf("Queue (Rear/Head to Front/Tail): ");
    Node *trav = q->rear;
    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    Queue *Q = initialize();
    
    printf("Enqueue 10, 20, 30...\n");
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q));
    display(Q);
    
    return 0;
}