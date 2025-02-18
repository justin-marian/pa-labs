#include <stdio.h>
#include <stdlib.h>

int n, r;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort (sorting by value-to-weight ratio in descending order)
void bubble_sort(int *w, int *v, int *idx) {
    int sorted;
    do {
        sorted = 0;
        for (int i = 0; i < n - 1; i++) {
            double ratio1 = (double)v[idx[i]] / w[idx[i]];
            double ratio2 = (double)v[idx[i + 1]] / w[idx[i + 1]];
            
            printf("Comparing ratio: %.2f vs %.2f\n", ratio1, ratio2);

            if (ratio1 < ratio2) {
                swap(&idx[i], &idx[i + 1]);
                sorted = 1;
            }
        }
    } while (sorted);
}

int main() {
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &r);

    int *w = malloc(n * sizeof(int));
    int *v = malloc(n * sizeof(int));
    int *idx = malloc(n * sizeof(int));
    float *frac = calloc(n, sizeof(float));

    for (int i = 0; i < n; i++) {
        idx[i] = i;
        scanf("%d %d", &w[i], &v[i]);
    }

    // Sorting items by value-to-weight ratio
    printf("\nSorting items by value-to-weight ratio:\n");
    bubble_sort(w, v, idx);

    // Fractional Knapsack Algorithm
    printf("\nFilling the knapsack...\n");
    int remaining_capacity = r;
    double total_value = 0;
    int i = 0;

    while (i < n && remaining_capacity >= w[idx[i]]) {
        remaining_capacity -= w[idx[i]];
        frac[idx[i]] = 1.0;  // Fully include this item
        total_value += v[idx[i]];
        
        printf("Selected full item %d: Weight = %d, Value = %d, Remaining capacity = %d\n",
               idx[i] + 1, w[idx[i]], v[idx[i]], remaining_capacity);
        i++;
    }

    // Include fraction of the next item if the knapsack is not full
    if (i < n) {
        double fraction = (double)remaining_capacity / w[idx[i]];
        frac[idx[i]] = fraction;
        total_value += v[idx[i]] * fraction;
        
        printf("Selected partial item %d: Weight = %d, Fraction = %.2f, Remaining capacity = 0\n",
               idx[i] + 1, w[idx[i]], fraction);
    }

    printf("\nFinal Knapsack Selection:\n");
    for (int i = 0; i < n; i++) {
        if (frac[i] > 0) {
            printf("Item %d: Weight = %d, Value = %.2f%%\n", i + 1, w[i], frac[i] * 100);
        }
    }

    printf("\nTotal value: %.2f\n", total_value);

    free(w);
    free(v);
    free(idx);
    free(frac);

    return 0;
}
