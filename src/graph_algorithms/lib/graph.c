#include "../include/graph.h"

// Initialize graph with empty adjacency lists
void initGraph(Graph *g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        g->adjList[i] = NULL;
    }
}

// Add edge (undirected)
void addEdge(Graph *g, int src, int dest) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    // Add reverse edge for undirected graph
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

// Remove an edge
void removeEdge(Graph *g, int src, int dest) {
    Node *temp = g->adjList[src], *prev = NULL;
    while (temp != NULL && temp->data != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            g->adjList[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    // Remove reverse edge
    temp = g->adjList[dest], prev = NULL;
    while (temp != NULL && temp->data != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            g->adjList[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

// Print the graph
void printGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        Node *temp = g->adjList[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free the graph memory
void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        Node *temp = g->adjList[i];
        while (temp) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}
