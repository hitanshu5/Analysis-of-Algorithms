#include <stdio.h>
#include <stdbool.h>
#define max 10
bool isSafe(int board[][max],int row,int col,int n)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
bool queen(int board[][max],int row,int n)
{
    if(row==n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,row,i,n))
        {
            board[row][i]=1;
            if(queen(board,row+1,n))
            {
                return true;
            }
            board[row][i]=0;
        }
    }
    return false;
}
void print_sol(int board[max][max],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("ENTER NUMBER OF QUEENS (4,6,8)\n");
    scanf("%d",&n);
    if(n!=4 && n!=6 && n!=8)
    {
        printf("ENTER CORRECT NUMBER OF QUEENS\n");
        return 1;
    }
    int board[max][max] = {0};
     if(!queen(board,0,n))
    {
        printf("SOLUTION DOES NOT EXIST\n");
        return 1;
    }
    
        print_sol(board,n);
    return 0;
    
}