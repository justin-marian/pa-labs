#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k, n; // k sections, n length

// Function to visualize fence combinations
void fence_combinations(int *dp, int k, int n) {
    printf("\nGenerating all possible fences...\n");

    // Fence patterns (k sections, n length)
    char ***patterns = (char ***)malloc((n + 1) * sizeof(char **));
    
    for (int i = 0; i <= n; i++) {
        patterns[i] = (char **)malloc(dp[i] * sizeof(char *));
        for (int j = 0; j < dp[i]; j++) {
            patterns[i][j] = (char *)malloc((i + 2) * sizeof(char)); 
            memset(patterns[i][j], 0, (i + 2) * sizeof(char)); 
        }
    }

    int m = 0;

    // Initialize base cases (first k fences)
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            patterns[i][0][j] = '|';
        }
        patterns[i][0][i] = '\0';
    }

    // First full section of k
    for (int j = 0; j < k; j++) {
        patterns[k][0][j] = '|';
    }

    patterns[k][0][k] = '\0';
    strcpy(patterns[k][1], "=");

    int l;
    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - k];

        for (int j = 0; j < dp[i - 1]; j++) {
            strcpy(patterns[i][j], patterns[i - 1][j]);
            l = strlen(patterns[i - 1][j]);
            patterns[i][j][l] = '|';
            patterns[i][j][l + 1] = '\0';
        }

        m = dp[i - 1];

        for (int j = 0; j < dp[i - k]; j++) {
            strcpy(patterns[i][m], patterns[i - k][j]);
            l = strlen(patterns[i - k][j]);
            patterns[i][m][l] = '=';
            patterns[i][m][l + 1] = '\0';
            m++;
        }
    }

    printf("\nPossible %d-section fences of length %d:\n", k, n);
    for (int i = 0; i < dp[n]; i++) {
        printf("%s\n", patterns[n][i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < dp[i]; j++) {
            free(patterns[i][j]);
        }
        free(patterns[i]);
    }
    free(patterns);
}

// Function to count and compute fence variations
int fence_variations(int k, int n) {
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = dp[1] = 1;

    printf("\nComputing number of ways to build fences...\n");
    for (int i = 2; i <= n; i++) {
        if (i < k) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - k];
        }
        printf("dp[%d] = %d\n", i, dp[i]);
    }

    fence_combinations(dp, k, n);
    int result = dp[n];
    free(dp);
    return result;
}

int main() {
    printf("Enter max sections and fence length: ");
    scanf("%d %d", &k, &n);

    int total = fence_variations(k, n);  // combinations of fences
    printf("\nTotal possible %d-section fences of length %d: %d\n", k, n, total);
    
    return 0;
}
