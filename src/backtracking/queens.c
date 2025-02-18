#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(int i, int *v) {
    for (int k = 1; k < i; k++) {
        if (v[k] == v[i] || abs(v[i] - v[k]) == i - k) {
            return false;
        }
    }
    return true;
}

void printQueenPositions(int n, int *v) {
    printf("\n{ ");
    for (int i = 1; i < n; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d }\n", v[n]);
}

void printBoard(int n, int *v) {
    // Print top border
    printf("+");
    for (int i = 0; i < n; i++) printf("---+");
    printf("\n");

    for (int i = 1; i <= n; i++) {
        printf("|");
        for (int j = 1; j <= n; j++) {
            printf(" %c |", (v[i] == j) ? 'Q' : ' ');
        }
        printf("\n+");
        for (int i = 0; i < n; i++) printf("---+");
        printf("\n");
    }
}

// Generate all possible solutions to the N-Queens
int nQueens(int n, int startVal, int step, int maxVal, int numQueens) {
    int *v = (int *)malloc((numQueens + 1) * sizeof(int));
    if (!v) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    for (int k = 1; k <= numQueens; k++) {
        v[k] = startVal;
    }

    int i = 1, count = 0;
    while (i >= 1) {
        bool valid = false;

        // Find a valid position for the queen
        while (!valid && v[i] <= maxVal) {
            v[i] += step;
            valid = isValid(i, v);
        }

        if (v[i] <= maxVal) {
            // Toggle 0 → 1 (Include element)
            if (i == numQueens) {
                count++;
                printf("Solution %d", count);
                printQueenPositions(n, v);
                printBoard(n, v);
            } else {
                i++;
            }
        } else {
            // Reset current position (Backtrack)
            v[i] = startVal;
            i--;
        }
    }

    free(v);
    return count;
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    printf("%d solutions found.\n", nQueens(n, 0, 1, n, n));
    return 0;
}
