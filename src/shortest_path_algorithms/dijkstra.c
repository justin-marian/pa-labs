#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000
#define INF INT_MAX

int pq[MAX_NODES];
int pq_size = 0;

int V, E;
int graph[MAX_NODES][MAX_NODES];

int dist[MAX_NODES];
int parent[MAX_NODES];

void swap(int i, int j) {
    int temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

void minHeapify(int i) {
    int left = 2 * i + 1;  // 0-based indexing
    int right = 2 * i + 2;
    int smallest = i;

    if (left < pq_size && dist[pq[left]] < dist[pq[smallest]])
        smallest = left;

    if (right < pq_size && dist[pq[right]] < dist[pq[smallest]])
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        minHeapify(smallest);
    }
}

void insert(int node) {
    if (pq_size >= MAX_NODES) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    pq[pq_size++] = node;
    int current = pq_size - 1;

    while (current > 0 && dist[pq[current]] < dist[pq[(current - 1) / 2]]) {
        swap(current, (current - 1) / 2);
        current = (current - 1) / 2;
    }
}

int extractMin() {
    if (pq_size == 0) {
        return -1;
    }

    int min = pq[0];
    pq[0] = pq[--pq_size];
    minHeapify(0);

    return min;
}

void printQueue() {
    printf("Priority Queue = { ");
    for (int i = 0; i < pq_size; i++) {
        printf("%d", pq[i]);
        if (i != pq_size - 1)
            printf(", ");
    }
    printf(" }\n");
}

void printDistances() {
    printf("Distances: [ ");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("∞ ");
        else
            printf("%d ", dist[i]);
    }
    printf("]\n");
}

void printParents() {
    printf("Parents: [ ");
    for (int i = 0; i < V; i++) {
        if (parent[i] == -1)
            printf("\\ ");
        else
            printf("%d ", parent[i]);
    }
    printf("]\n");
}

void dijkstra(int start) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;
    insert(start);

    while (pq_size > 0) {
        int u = extractMin();
        printQueue();
        printf("Processing Node: %d\n", u);
        printDistances();
        printParents();
        printf("\n");

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                insert(v);
            }
        }
    }
}

int main() {
    V = 7, E = 14;
    if (V > MAX_NODES) {
        printf("Graph size exceeds maximum limit!\n");
        return 1;
    }

    int edges[][3] = {
        {0, 1, 3}, {0, 2, 4}, {0, 4, 1}, {0, 5, 10}, {0, 6, 3},
        {1, 2, 2}, {2, 3, 2}, {2, 5, 2}, {4, 3, 3}, {4, 6, 1},
        {5, 3, 2}, {6, 2, 1}, {6, 3, 10}, {6, 4, 2}
    };

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u][v] = w;
    }

    dijkstra(0);

    return 0;
}
