#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int left, int right) {
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int *) calloc(n, sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Max find: %d\n", findMax(arr, 0, n - 1));

    free(arr);
    return 0;
}
