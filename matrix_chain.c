#include <stdio.h>
#include <limits.h>
int matrix(int arr[], int i, int j)
{
    int k, min = INT_MAX;
    if (i == j)
    {
        return 0;
    }
    for (k = i; k < j; k++)
    {
        int count = matrix(arr, i, k) + matrix(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (count < min)
        {
            min = count;
        }
    }
    return min;
}
void main()
{
    int arr[] = {4, 5, 7, 3, 2, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = matrix(arr, 1, n - 1);
    printf("Total cost is %d", ans);
}