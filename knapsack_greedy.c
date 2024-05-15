#include <stdio.h>
#define max 100
struct ITEM
{
    int profit;
    int weight;
};
int knapsackGreedy(struct ITEM items[max],int n,int capacity)
{
    int tot=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            double ratio1 = (double) items[j].profit / items[j].weight;
            double ratio2 = (double) items[j+1].profit / items[j+1].weight;
            if(ratio1 < ratio2)
            {
                struct ITEM temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(capacity >= items[i].weight)
        {
            tot += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            tot += (int)(capacity * ((double) items[i].profit / items[i].weight));
            break;
        }
    }
    return tot;
}
void main()
{
    struct ITEM items[max];
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter weights and profits of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }
    int maxProfit = knapsackGreedy(items, n, capacity);

    printf("Maximum profit using greedy approach: %d\n", maxProfit);
}