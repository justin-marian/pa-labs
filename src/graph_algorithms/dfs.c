#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/stack.h"
#include "include/queue.h"
#include "include/graph.h"

void explore(int u, Graph *G, char *c, int *p, int *d, int *f, int *step) {
    (*step)++;
    d[u] = *step;
    c[u] = 'g';
    printf("Node %c discovered at time %d, colors %c, parent %c\n", u + 'A', d[u], c[u], p[u] + 'A');

    // Iterate through adjacency list correctly
    Node *temp = G->adjList[u];
    while (temp) {
        int v = temp->data;
        if (c[v] == 'w') {
            p[v] = u;
            explore(v, G, c, p, d, f, step);
        }
        temp = temp->next;
    }

    (*step)++;
    f[u] = *step;
    c[u] = 'b';
    printf("Node %c finished at time %d, colors %c, parent %c\n", u + 'A', f[u], c[u], p[u] + 'A');
}

void DFS(Graph *G) {
    char c[MAX_VERTICES];
    int p[MAX_VERTICES];
    int d[MAX_VERTICES];
    int f[MAX_VERTICES];

    int step = 0;
    for (int u = 0; u < G->numVertices; u++) {
        c[u] = 'w'; p[u] = -1; d[u] = 0; f[u] = 0;
    }

    printf("Starting DFS from node %d\n\n", 0);
    for (int u = 0; u < G->numVertices; u++) {
        if (c[u] == 'w') {
            explore(u, G, c, p, d, f, &step);
        }
    }

    printf("\n");
    for (int u = 0; u < G->numVertices; u++) {
        printf("Node %c: Discovery time = %d, \t Finish time = %d\n", u + 'A', d[u], f[u]);
    }
}

int main() {
    Graph G;
    int numVertices, numEdges;
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    initGraph(&G, numVertices);

    printf("Enter edges (u, v):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&G, u, v);
    }

    DFS(&G);

    freeGraph(&G);
    return 0;
}
