#include <stdio.h>
#include <stdlib.h>

int occurrences(int *arr, int left, int right, int x) {
    if (left == right) {
        return (arr[left] == x) ? 1 : 0;
    }

    int mid = left + (right - left) / 2;
    return occurrences(arr, left, mid, x) + occurrences(arr, mid + 1, right, x);
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

    int occs = occurrences(arr, 0, n - 1, x);

    if (occs == 0)
        printf("%d nu exista in vector.\n", x);
    else
        printf("%d este prezent de %d ori in vector.\n", x, occs);

    free(arr);
    return 0;
}
