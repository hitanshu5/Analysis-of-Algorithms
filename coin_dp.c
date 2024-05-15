#include <stdio.h>
#include <limits.h>
 
#define MAX_DENOMINATIONS 100
#define MAX_AMOUNT 1000
 
int makeChange(int d[], int n, int N, int C[MAX_DENOMINATIONS][MAX_AMOUNT]) {
    int i, j;
    for (i = 0; i <= n; i++)
        C[i][0] = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= N; j++) {
            if (i == 1 && j < d[i])
                C[i][j] = INT_MAX;
            else if (i == 1)
                C[i][j] = 1 + C[1][j - d[1]];
            else if (j < d[i])
                C[i][j] = C[i - 1][j];
            else
                C[i][j] = (C[i - 1][j] < 1 + C[i][j - d[i]]) ? C[i - 1][j] : 1 + C[i][j - d[i]];
        }
    }
    return C[n][N];
}
 
void traceChange(int d[], int n, int N, int C[MAX_DENOMINATIONS][MAX_AMOUNT]) {
    int i = n, j = N;
    printf("Denominations used: ");
    while (j > 0) {
        if (C[i][j] == C[i - 1][j])
            i--;
        else {
            printf("%d ", d[i]);
            j -= d[i];
        }
    }
    printf("\n");
}
 
int main() {
    int d[MAX_DENOMINATIONS], n, N;
    int C[MAX_DENOMINATIONS][MAX_AMOUNT];
    printf("Enter the number of denominations: \n");
    scanf("%d", &n);
    printf("Enter the denominations: \n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    printf("Enter the target sum: ");
    scanf("%d", &N);
    int minCoins = makeChange(d, n, N, C);
    printf("Minimum number of coins required: %d\n", minCoins);
    traceChange(d, n, N, C);
    return 0;
}