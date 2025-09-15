#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
}Stack;

// Top is the last index of the stack

Stack* initialize(); // Allocate memory for the stack and initialize the top
bool isFull(Stack *S); // Check if the stack is full
bool isEmpty(Stack *S); // Check if the stack is empty
void push(Stack* S, int value); // Push or insert a new element at the top/last
int pop(Stack* S); // Pop or delete the last element in the top
int peek(Stack* S); // Returns the value at the top of the stack
int top(Stack* S); // Returns the index/position of top
void display(Stack* S);

int main(){
    Stack *S;
    S = initialize(S);
    push(S, 5);
    push(S, 3);
    push(S, 8);
    push(S, 11);
    push(S, 5);
    
    display(S);
    
    int topVal, topped, popped;
    
    popped = pop(S);
    printf("\nThe value removed is %d", popped);
    
    topVal = peek(S);
    printf("\nThe value at the top is %d", topVal);
    
    topped = top(S);
    printf("\nThe current top is %d", topped);
    
    printf("\n\nThe current stack is:\n\n");
    display(S);

    return 0;
}

Stack* initialize(){
    Stack* S =(Stack*)malloc(sizeof(Stack));
    S->top = MAX;
    
    return S;
}

bool isFull(Stack* S){
    if(S->top == 0){
        return 1;
    }else{
        return 0;
    }

}

bool isEmpty(Stack* S){
    if(S->top == MAX){
        return 1;
    }else{
        return 0;
    }

}

void push(Stack* S, int value){
    if(isFull(S)){
        printf("Stack is full.");
        exit(1);
    }

    S->top--;
    S->items[S->top] = value;

}

int pop(Stack* S){

    if (isEmpty(S)){
        printf("Stack underflow.");
        exit(1);
    }

    int val = S->items[S->top];
    S->top++;
    
    return val;
}

int peek(Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty");
        exit(1);
    }

    int val = S->items[S->top];
    return val;
}

int top(Stack* S){
    return S->top;
}

void display(Stack* S){

    if(isEmpty(S)){
        printf("Stack is empty");
        return;
    }

    for(int i = S->top; i < MAX; i++){
        printf("      %d\n", S->items[i]);
        printf("-------------\n");
    }

}