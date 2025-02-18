#include "../include/stack.h"

// Initialize stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Check if stack is empty
int isStackEmpty(Stack *s) {
    return s->top == NULL;
}

// Push element onto stack
void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop element from stack
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }

    int value = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);

    return value;
}

// Print stack elements
void printStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    Node *temp = s->top;
    printf("Stack (Top -> Bottom): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free stack memory
void freeStack(Stack *s) {
    Node *temp = s->top;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    s->top = NULL;
}
