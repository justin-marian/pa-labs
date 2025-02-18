#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#include "include/stack.h"
#include "include/queue.h"
#include "include/graph.h"

// Print details of BFS step
void print_details(int step, Graph *G, char *c, int *p, int *dist, Queue *Q) {
    printf("\nStep: %d\n", step);
    
    printf("Queue: ");
    printQueue(Q);
    
    printf("Color: ");
    for (int u = 0; u < G->numVertices; u++) {
        printf("%c ", c[u]);
    }
    printf("\n");

    printf("Parent: ");
    for (int u = 0; u < G->numVertices; u++) {
        printf("%d ", p[u]);
    }
    printf("\n");

    printf("Distance: ");
    for (int u = 0; u < G->numVertices; u++) {
        if (dist[u] == INT_MAX) {
            printf("∞ ");
        } else {
            printf("%d ", dist[u]);
        }
    }
    printf("\n");
}

// BFS Algorithm
void BFS(int s, Graph *G) {
    char c[MAX_VERTICES];
    int p[MAX_VERTICES];
    int dist[MAX_VERTICES];

    for (int u = 0; u < G->numVertices; u++) {
        c[u] = 'w'; 
        p[u] = -1; 
        dist[u] = INT_MAX;
    }

    Queue Q;
    initQueue(&Q);

    // Initialize BFS
    enqueue(&Q, s);
    c[s] = 'g'; 
    dist[s] = 0;
    int step = 1;
    print_details(step, G, c, p, dist, &Q);

    // BFS Iteration
    while (!isQueueEmpty(&Q)) {
        step++;
        int u = dequeue(&Q);
        c[u] = 'b';

        // Iterate through adjacency list (Linked List)
        Node *temp = G->adjList[u];
        while (temp) {
            int v = temp->data;
            if (c[v] == 'w') {
                dist[v] = dist[u] + 1;
                p[v] = u;
                enqueue(&Q, v);
                c[v] = 'g';
            }
            temp = temp->next;
        }
        print_details(step, G, c, p, dist, &Q);
    }

    freeQueue(&Q);
}

int main() {
    Graph G;
    int numVertices, numEdges, source;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);
    
    printf("Enter source data: ");
    scanf("%d", &source);

    initGraph(&G, numVertices);

    printf("Enter edges (u, v):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&G, u, v);
    }
    
    printf("\nBFS from source %d:\n", source);
    BFS(source, &G);

    freeGraph(&G);
    return 0;
}
