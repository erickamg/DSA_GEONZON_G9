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

int main(){

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

    
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    

}
