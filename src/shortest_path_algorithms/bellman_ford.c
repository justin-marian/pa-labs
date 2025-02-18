#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Node {
    int value;
    int dist;
    int parent;
} Node;

// Function to print the distance and predecessor vectors
void print_graph(int V, Node** vector) {
    printf("\nVertices: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", vector[i]->value);
    }

    printf("\nDistances: ");
    for (int i = 0; i < V; i++) {
        if (vector[i]->dist == INF) 
            printf("∞ ");
        else 
            printf("%d ", vector[i]->dist);
    }

    printf("\nPredecessors: ");
    for (int i = 0; i < V; i++) {
        if (vector[i]->parent == -1)
            printf("X ");
        else
            printf("%d ", vector[i]->parent);
    }

    printf("\n");
}

// Bellman-Ford Algorithm
void Bellman_Ford(int V, int graph[100][100], int src) {
    Node** vector = malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        vector[i] = malloc(sizeof(Node));
        vector[i]->value = i;
        vector[i]->dist = INF;
        vector[i]->parent = -1;
    }

    vector[src]->dist = 0;
    print_graph(V, vector);

    // Relax all edges V-1 times
    for (int step = 0; step < V - 1; step++) {
        printf("\nIteration %d:\n", step + 1);
        int updated = 0;

        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0) {
                    int weight = graph[u][v];

                    if (vector[u]->dist != INF && vector[v]->dist > vector[u]->dist + weight) {
                        printf("Relaxing edge (%d -> %d) with weight %d\n", u, v, weight);
                        vector[v]->dist = vector[u]->dist + weight;
                        vector[v]->parent = u;
                        updated = 1;
                    }
                }
            }
        }

        print_graph(V, vector);
        if (!updated) break;
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];

                if (vector[u]->dist != INF && vector[v]->dist > vector[u]->dist + weight) {
                    printf("\nNegative weight cycle detected!\n");
                    goto cleanup;
                }
            }
        }
    }

cleanup:
    for (int i = 0; i < V; i++) {
        free(vector[i]);
    }
    free(vector);
}

int main() {
    int graph[100][100] = {0};
    int V = 7;

    graph[0][1] = 3;
    graph[0][2] = 4;
    graph[0][4] = 1;
    graph[0][5] = 10;
    graph[0][6] = 3;
    graph[1][2] = 2;
    graph[2][3] = 2;
    graph[2][5] = 2;
    graph[4][3] = 3;
    graph[4][6] = 1;
    graph[5][3] = 2;
    graph[6][2] = 1;
    graph[6][3] = 10;
    graph[6][4] = 2;

    Bellman_Ford(V, graph, 0);

    return 0;
}
