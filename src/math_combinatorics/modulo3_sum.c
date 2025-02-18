#include <stdio.h>
#include <stdlib.h>

void modulo3Sum(int *arr, int **dp, int n) {
    for (int j = 0; j < 3; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int idxM = 0; idxM < 3; idxM++) {
            switch (arr[i] % 3) {
                case 0:
                    dp[i][idxM] = (idxM == 0) ? 
                        1 + 2 * dp[i - 1][0] : 
                        2 * dp[i - 1][idxM];
                    break;
                case 1:
                    dp[i][idxM] = (idxM == 0) ? 
                        dp[i - 1][0] + dp[i - 1][2]
                        : (idxM == 1) ? 
                        1 + dp[i - 1][0] + dp[i - 1][1] 
                        : ((i - 2 >= 0) ? dp[i - 2][2] + dp[i - 1][1] : dp[i - 1][1]);
                    break;
                case 2:
                    dp[i][idxM] = (idxM == 0) ? 
                        dp[i - 1][0] + dp[i - 1][1]
                        : (idxM == 1) ? 
                        dp[i - 1][2] + dp[i - 1][1] 
                        : 1 + dp[i - 1][0] + dp[i - 1][2];
                    break;
            }
        }
    }
}

int main() {
    int n;  // Number of elements 
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d numbers: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(3, sizeof(int));
    }

    modulo3Sum(arr, dp, n);

    printf("\nComputed Dynamic Programming Table:\n");
    for (int i = 0; i <= n; i++) {
        printf("dp[%d]: ", i);
        for (int idxM = 0; idxM < 3; idxM++)
            printf("%d ", dp[i][idxM]);
        printf("\n");
    }

    free(arr);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
