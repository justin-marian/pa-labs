#include <stdio.h>
#include <stdlib.h>

// Binary search function
int binary_search(int *arr, int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);
        return binary_search(arr, mid + 1, right, x);
    }
    return -1;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, x;
    printf("Enter array size and number to search: ");
    scanf("%d %d", &n, &x);

    int *arr = (int *)calloc(n, sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int pos = binary_search(arr, 0, n - 1, x);

    if (pos == -1)
        printf("%d nu exista in vector.\n", x);
    else
        printf("%d este prezent la pozitia %d.\n", x, pos);

    free(arr);
    return 0;
}
