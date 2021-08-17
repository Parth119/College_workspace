#include<stdio.h>
#define capacity 50
#define n 3

int max(int a, int b)
{
    return(a>b)?a:b; 
}
int knapsack(int wt[], int val[])
{
    int i,w;
    int k[n+1][capacity+1];
    for(i=0; i<=n; i++)
    {
        for(w=0; w<=capacity; w++)
        {
            if(i==0 || w==0)
            {
                k[i][w]=0;
            }
            else if(wt[i-1] <= w)
            {
                k[i][w]= max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else
            {
                k[i][w] = k[i-1][w];
            }
        }
    }
    return k[n][capacity];
}

void main()
{
    int i,weight_sum=0,value_sum=0;
    int val[n]={60,100,120};
    int wt[n]={10,20,30};

    printf("\nObject No: \t Weight: \t Value:\n");
    printf("---------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d \t\t %d \t\t %d\n",(i+1),wt[i],val[i]);
        weight_sum+=wt[i];
        value_sum+=val[i];
    }
    printf("---------------------------------------------------------\n");
    printf("Total Value: \t %d \t\t %d\n",weight_sum,value_sum);
    printf("\nMaximum Capacity: %d",capacity);

    printf("\nMaximum profit of Knapsack problem :%d",knapsack(wt,val));
}