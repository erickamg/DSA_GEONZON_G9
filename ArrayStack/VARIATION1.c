#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
}Stack;

// Top is the last index of the stack

Stack initialize(Stack S); // Allocate memory for the stack and initialize the top
bool isFull(Stack S); // Check if the stack is full
bool isEmpty(Stack S); // Check if the stack is empty
Stack push(Stack S, int value); // Push or insert a new element at the top/last
int pop(Stack S); // Pop or delete the last element in the top
int peek(Stack S); // Returns the value at the top of the stack
int top(Stack S); // Returns the index/position of top
void display(Stack S);

int main(){
    Stack S = initialize(S);
    S = push(S, 5);
    S = push(S, 3);
    S = push(S, 8);
    S = push(S, 11);
    
    display(S);

    return 0;
}

Stack initialize(Stack S){
    S.top = -1;
    
    return S;
}

bool isFull(Stack S){
    if(S.top == MAX - 1){
        return 1;
    }else{
        return 0;
    }

}

bool isEmpty(Stack S){
    if(S.top == -1){
        return 1;
    }else{
        return 0;
    }

}

Stack push(Stack S, int value){
    if(isFull){
        printf("Stack is full.");
        exit(1);
    }

    S.top++;
    S.items[S.top] = value;

    return S;
}

int pop(Stack S){

    if (isEmpty){
        printf("Stack underflow.");
        exit(1);
    }

    int val = S.items[S.top];
    S.top--;
    
    return val;
}

int peek(Stack S){
    if(isEmpty){
        printf("Stack is empty");
        exit(1);
    }

    int val = S.items[S.top];
    return val;
}

int top(Stack S){
    return S.top;
}

void display(Stack S){

    if(isEmpty){
        printf("Stack is empty");
        return;
    }

    for(int i = S.top; i >= 0; i-- ){
        printf("%d\n", S.items[i]);
    }

}