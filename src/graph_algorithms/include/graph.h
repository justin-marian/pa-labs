#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "node.h"

#define MAX_VERTICES 100

// Graph represented using adjacency lists
typedef struct Graph {
    int numVertices;
    Node *adjList[MAX_VERTICES];
} Graph;

// Graph functions
void initGraph(Graph *g, int numVertices);
void printGraph(Graph *g);
void addEdge(Graph *g, int src, int dest);
void removeEdge(Graph *g, int src, int dest);
void freeGraph(Graph *g);

#endif
