#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming approach to 0/1 Knapsack Problem
int knapSack(int R, int *m, int *v, bool *o, int n) {
    int **D = (int **)calloc(n + 1, sizeof(int *));
    for (int i = 0; i <= n; i++) {
        D[i] = (int *)calloc(R + 1, sizeof(int));
    }

    for (int i = 1; i <= n; i++) {      // Objects
        for (int j = 0; j <= R; j++) {  // Capacity
            if (m[i - 1] <= j) {
                D[i][j] = max(v[i - 1] + D[i - 1][j - m[i - 1]], D[i - 1][j]);
            } else {
                D[i][j] = D[i - 1][j];
            }
        }
    }

    int value = D[n][R];

    // Backtrack to find selected items
    int W = R;
    memset(o, false, n * sizeof(bool));

    for (int i = n; i > 0 && W > 0; i--) {
        if (D[i][W] != D[i - 1][W]) {
            // Item was included
            o[i - 1] = true;
            // Reduce capacity
            W -= m[i - 1];
        }
    }

    for (int i = 0; i <= n; i++) {
        free(D[i]);
    }
    free(D);

    return value;
}

int main() {
    printf("Enter number of items and knapsack capacity: ");

    int n, R;
    scanf("%d %d", &n, &R);

    int *m = (int *)calloc(n, sizeof(int));
    int *v = (int *)calloc(n, sizeof(int));
    bool *o = (bool *)calloc(n, sizeof(bool));

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i], &v[i]);
    }

    int total_value = knapSack(R, m, v, o, n);
    printf("\nTotal value: %d\n", total_value);

    printf("Selected items:\n");
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        if (o[i]) {
            printf("Item %d -> Weight: %d, Value: %d\n", i + 1, m[i], v[i]);
            total_weight += m[i];
        }
    }

    printf("\nTotal Weight Used: %d, Remaining Capacity: %d\n", total_weight, R - total_weight);

    free(m);
    free(v);
    free(o);
    return 0;
}
