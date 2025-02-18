#include "../include/queue.h"

// Initialize queue
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// Check if queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

// Enqueue element
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    
    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue element
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Print queue elements
void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = q->front;
    printf("Queue (Front -> Rear): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free queue memory
void freeQueue(Queue *q) {
    Node *temp = q->front;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    q->front = q->rear = NULL;
}
