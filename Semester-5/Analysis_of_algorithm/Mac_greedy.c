#include<stdio.h>
#define max  100

int ans[max];

int findMinCoins(int coins[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {

        while(value >= coins[i])
        {

            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
        {
            break;
        }

    }

    return count;
}

int main()
{
    int coins[max],size;
    int value, i;

    printf("Enter Total value :");
    scanf("%d",&value);
    printf("Enter the number of coins You want :");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
        printf("Enter %d coin value:",i+1);
        scanf("%d",&coins[i]);
    }
    //int size = sizeof(coins)/sizeof(coins[0]);

    int MinCount = findMinCoins(coins,size,value);

    printf("Total Coins Needed = %d\n",MinCount);

    printf("Coins are:\t");
    for(i = 0; i < MinCount; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}
