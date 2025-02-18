#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSubset(int n, int *v) {
    printf("{ ");
    int isEmpty = 1;

    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            printf("%d ", i);
            isEmpty = 0;
        }
    }

    if (isEmpty)
        printf("∅ ");

    printf("}\n");
}

// Generate all possible subsets of a set of n elements
int generateSubsets(int n, int startVal, int step, int maxVal, int len) {
    int *v = (int *)malloc((len + 1) * sizeof(int));
    if (!v) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    for (int k = 1; k <= len; k++) {
        v[k] = startVal;
    }

    int i = 1, count = 0;
    while (i >= 1) {
        bool valid = false;

        // Find a valid position for the queen
        while (!valid && v[i] <= maxVal) {
            v[i] += step;
            valid = true;
        }

        // If a valid position was found
        if (v[i] <= maxVal) {
            // Toggle 0 → 1 (Include element)
            if (i == len) {
                count++;
                printSubset(n, v);
            } else i++;
        } else {
            // Reset current position (Backtrack)
            v[i] = startVal;
            i--;
        }
    }

    return count;
}

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    int totalSubsets = generateSubsets(n, -1, 1, 1, n);
    printf("\nTotal subsets generated: %d\n", totalSubsets);

    return 0;
}