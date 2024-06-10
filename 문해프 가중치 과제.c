#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    
    int N;
    scanf("%d", &N);

    int *weights = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &weights[i]);
    }

    
    if (N == 1) {

        printf("%d\n", weights[1]);
        free(weights);
        return 0;
    }

    int *dp = (int *)malloc((N + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = weights[1];
    
    if (N > 1) {
        dp[2] = weights[1] + weights[2];
    }

    for (int i = 3; i <= N; i++) {
        dp[i] = MAX(dp[i - 2], dp[i - 3] + weights[i - 1]) + weights[i];
    }

    printf("%d\n", dp[N]);

    free(weights);
    free(dp);
    return 0;
}
