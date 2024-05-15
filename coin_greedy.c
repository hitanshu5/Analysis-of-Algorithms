#include<stdio.h>
void findMinCoins(int coins[], int n, int amount) {
    int i = n - 1; 
    printf("Coins used: ");

    while (amount > 0 && i >= 0) {
        
        while (coins[i] <= amount) {
            printf("%d ", coins[i]);
            amount -= coins[i]; 
        }
        i--; 
    }
    printf("\n");
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; 
    int n = sizeof(coins) / sizeof(coins[0]); 
    int amount;

    printf("Enter the amount: ");
    scanf("%d", &amount);
    findMinCoins(coins, n, amount);

    return 0;
}
