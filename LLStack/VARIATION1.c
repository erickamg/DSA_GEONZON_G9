#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

Stack* initialize();
bool isFull(Stack* S);
bool isEmpty(Stack* S);
void push(Stack *S, int value);
int pop(Stack* S);
int peek(Stack* S);
void display(Stack* S);

int main(){
    Stack* S = initialize();

    push(S, 8);
    push(S,11);
    push(S, 13);
    push(S, 6);
    push(S, 7);
    push(S, 9);
    display(S);

    int a = pop(S);
    printf("\nDeleted data %d", a);
    int b = pop(S);
    printf("\nDeleted data %d\n", b);

    int x = peek(S);
    printf("Current data at top is %d\n", x);
    display(S);

    return 0;
}

Stack* initialize(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;

    return S;
}

bool isFull(Stack* S){

    return 0;

}

bool isEmpty(Stack* S){

    if(S->top == NULL){
        return 1;
    }else{
        return 0;
    }

}

void push(Stack* S, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = S->top;
    
    S->top = newNode;

}

int pop(Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty.");
        exit(1);
    }

    Node* temp = S->top;
    int val = temp->data;
    S->top = S->top->next;

    free(temp);
    temp = NULL;

    return val;

}

int peek(Stack* S){
    if(isEmpty(S)){
        printf("The stack is empty.");
        exit(1);
    }

    return S->top->data;
}

void display(Stack* S){
    
    if (isEmpty(S)){
        printf("Stack is empty.");
        exit(1);
    }

    Node* temp = S->top;
    printf("\n");
    while (temp){
        printf("        %d\n", temp->data);
        printf("-----------------\n");
        temp = temp->next;
    }
    
    
}
