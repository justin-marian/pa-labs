#ifndef _STACK_H_
#define _STACK_H_

#include "node.h"

// Stack structure
typedef struct Stack {
    Node *top;
} Stack;

// Stack functions
void initStack(Stack *s);
int isStackEmpty(Stack *s);
void printStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void freeStack(Stack *s);

#endif
