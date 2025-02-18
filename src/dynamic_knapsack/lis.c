#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INVALID_INDEX -1

// Find the Longest Increasing Subsequence (LIS)
int* lengthOfLIS(int* v, int n, int *len) {
    // No elements -> return NULL
    if (n == 0) {
        *len = 0;
        return NULL;
    }

    int *lis_len = (int *)calloc(n, sizeof(int));
    int *lis_idx = (int *)calloc(n, sizeof(int));

    // Each element is an LIS of length 1 initially
    for (int i = 0; i < n; i++) {
        lis_len[i] = 1;
        lis_idx[i] = INVALID_INDEX;
    }

    int max_len = 1, max_idx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j] && lis_len[j] + 1 > lis_len[i]) {
                lis_len[i] = lis_len[j] + 1; 
                lis_idx[i] = j;
            }
        }
        if (lis_len[i] > max_len) {
            max_len = lis_len[i];
            max_idx = i;
        }
    }

    // Backtracking to construct the LIS sequence
    int *lis = (int*)calloc(max_len, sizeof(int));
    int idx = max_idx, new_len = max_len - 1;

    while (idx != INVALID_INDEX) {
        // Store values, not indices
        lis[new_len--] = v[idx];
        idx = lis_idx[idx];
    }

    free(lis_len);
    free(lis_idx);
    *len = max_len;
    
    return lis;
}

int main() {
    printf("Longest Increasing Subsequence - LIS\n");

    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_len = 0;
    int *sarr = lengthOfLIS(arr, n, &max_len);

    printf("\nLength: %d\n", max_len);
    printf("LIS: ");

    for (int i = 0; i < max_len; i++) {
        printf("%d ", sarr[i]);
    }
    printf("\n");

    free(arr);
    free(sarr);

    return 0;
}
