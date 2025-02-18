#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "node.h"

// Queue structure
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Queue functions
void initQueue(Queue *q);
int isQueueEmpty(Queue *q);
void printQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void freeQueue(Queue *q);

#endif
