#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
}List;

typedef struct {
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull();
bool isEmpty();
void enqueue(Queue* Q, int value);
int dequeue(Queue* Q);

int main(){

}

Queue* initialize(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;

    return Q;
}

bool isFull(Queue* Q){

    if(Q->list.count == MAX){
        return 1;
    }else{
        return 0;
    }

}

bool isEmpty(Queue* Q){

    if(Q->list.count == 0){
        return 1;
    }else{
        return 0;
    }

}

void enqueue(Queue* Q, int value){

    if(isFull(Q)){

        printf("Queue is full.");
        exit(1);

    }else if(isEmpty(Q)){

        Q->front = 0;
        Q->rear = 0;

    }else{
        Q->rear = ((Q->rear + 1) % MAX);
    }
    
    Q->list.items[Q->rear] = value;
    Q->list.count++;

}

int dequeue(Queue* Q){
    int val;

    if(isEmpty(Q)){
        printf("Queue is empty.");
        return -1;
    }

    val = front(Q);

    if(Q->list.count == 1){
        Q->list.count = 0;
        Q->front = -1;
        Q->rear = -1;
        // If this is the last element in the queue, reset the queue to its initial empty state
    }else{
        Q->front = (Q->front + 1) % MAX;
    }

    Q->list.count--;
    return val;
}

int front(Queue* Q){

    if(isEmpty(Q)){
        return;
    }else{
       return Q->front; 
    }
    
}

void display(Queue* Q){
    if(isEmpty(Q)){
        return;
    }else{

        for(int i = Q->front; i < Q->list.count; i = (i + 1) % MAX){
            printf("d ", Q->list.items[i]);
        }

    }
}