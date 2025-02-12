#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0 || n == 1) {
        printf("1");
        return 0;
    }
    
    int *dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 1) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i / 2] + dp[i - 2];
        }
    }
    
    printf("%d", dp[n]);
    free(dp);
    return 0;
}