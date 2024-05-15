#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
struct JOB
{
    int id,deadline,profit;
};
void job_greedy(struct JOB job[10],int n)
{
    int i,j,slots[10] = {0};
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(job[j].profit < job[j+1].profit)
            {
                struct JOB temp = job[j];
                job[j] = job[j+1];
                job[j+1] = temp;
            }
        }
    }
    int p=0;
    for(i=0;i<n-1;i++)
    {
        for(j=job[i].deadline;j>=0;j--)
        {
            if(slots[j]==0)
            {
                slots[j] = job[i].id;
                p += job[i].profit;
                break;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        if(slots[i] != 0)
        {
            printf("JOB: %d\n",slots[i]);
        }
    }
    printf("%d",p);
}
void main()
{
    printf("enter no. of jobs\n");
    int n;
    struct JOB job[10];
    scanf("%d",&n);
    printf("enter id deadline and profit\n");
    for(int i=0;i<n;i++)
    {
        printf("[%d]: ",i+1);
        scanf("%d %d %d",&job[i].id,&job[i].deadline,&job[i].profit);
    }
    job_greedy(job,n);
}