#include <stdio.h>
#define max 100
int isSubset(int arr[],int n,int target,int subset[],int index)
{
    int i;
    if(target == 0)
    {
        printf("SOLUTION EXISTS\n");
        printf("SUBSETS ARE: ");
        for(i=0;i<index;i++)
        {
            printf("%d ",subset[i]);
        }
        return 1;
    }
    if(n==0 || target < 0)
    {
        return 0;
    }
    if(arr[n-1] > target)
    {
        return isSubset(arr,n-1,target,subset,index);
    }
    subset[index] = arr[n-1];
    return isSubset(arr,n-1,target-arr[n-1],subset,index+1) || isSubset(arr,n-1,target,subset,index);
}
void main()
{
    int arr[max],n,subset[max],i;
    printf("ENTER TOTAL NUMBER OF ELEMENTS\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int target;
    printf("ENTER TARGET SUM\n");
    scanf("%d",&target);
    if(!isSubset(arr,n,target,subset,0))
    {
        printf("SOLUTION DOES NOT EXISTS");
    }
}