#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int left, int mid, int right) {
    int size = right - left + 1;
    int *temp = (int *)calloc(size, sizeof(int));

    if (!temp) {
        printf("Memory allocation failed in merge()\n");
        exit(1);
    }

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= mid) {
        temp[k++] = v[i++];
    }
    while (j <= right) {
        temp[k++] = v[j++];
    }

    // Copy sorted elements back to v[]
    for (int i = left, k = 0; i <= right; i++, k++) {
        v[i] = temp[k];
    }

    free(temp);
}

void merge_sort(int *v, int left, int right) {   
   if (left < right) {
      int mid = left + (right - left) / 2;
      merge_sort(v, left, mid);
      merge_sort(v, mid + 1, right);
      merge(v, left, mid, right);
   } 
}

int main() { 
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *v = (int *)calloc(n, sizeof(int));
    if (!v) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    merge_sort(v, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);
    return 0;
}
