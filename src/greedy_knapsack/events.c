#include <stdio.h>
#include <stdlib.h>

int n;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorts indices of activities based on end time
void sort(int *t, int *s, int *idx) {
    int sorted;
    do {
        sorted = 0;
        for (int i = 0; i < n - 1; ++i) {
            printf("Comparing activities: (%d-%d) vs (%d-%d)\n", 
                   s[idx[i]], t[idx[i]], s[idx[i + 1]], t[idx[i + 1]]);
            if (t[idx[i]] > t[idx[i + 1]]) {
                swap(&idx[i], &idx[i + 1]);
                sorted = 1;
            }
        }
    } while (sorted);
}

// Scheduling function: Selects maximum number of non-overlapping activities
void schedule(int *s, int *t, int *idx) {
    printf("\nSelected Activities:\n");
    
    int last = 0;  // First activity is always selected
    printf("%d-%d\n", s[idx[last]], t[idx[last]]);
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (s[idx[i]] >= t[idx[last]]) {
            printf("%d-%d\n", s[idx[i]], t[idx[i]]);
            last = i;
            count++;
        }
    }
    
    printf("\nTotal activities selected: %d\n", count);
}

int main() {
	printf("Enter number of activities: ");
    scanf("%d", &n);

    int *s = (int *)malloc(n * sizeof(int));
    int *t = (int *)malloc(n * sizeof(int));
    int *idx = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        idx[i] = i;
        scanf("%d %d", &s[i], &t[i]);
    }

    // Sorting activities by finish time
    printf("\nSorting activities by finish time:\n");
    sort(t, s, idx);

    // Selecting activities
    schedule(s, t, idx);

    free(s);
    free(t);
    free(idx);

    return 0;
}
