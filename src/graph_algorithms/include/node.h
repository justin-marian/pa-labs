#ifndef __NODE_H_
#define __NODE_H_

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

#endif // __NODE_H_
