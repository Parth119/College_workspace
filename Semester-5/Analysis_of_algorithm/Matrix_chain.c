#include<stdio.h>
#include<time.h>
int ans[100];
int findMinCoin(int a[],int n,int amt)
{
    int i,count=0,R_amt=amt;
    for(i=0;i<n;i++)
    {
        while(R_amt>=a[i])
        {
            R_amt-=a[i];
   		    ans[count]=a[i];
            count++;
        }
        if(amt==0)
        {
            break;
        }
       
    }
    printf("\nNumber of Coins Required to pay an amount:%d",count);
    printf("\nSolution:");
    for(i=0;i<count;i++)
    {
        printf("%d ",ans[i]);
    }
    return count;
}
int main()
{
    int n,i,amt,j,count,temp;
    printf("Enter the number of coins:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the coins:");
    for(i=0;i<n;i++)
    {      
        scanf("%d",&a[i]);
    }
    printf("Enter the total amount:");
    scanf("%d",&amt);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
			{
            	temp=a[i];
            	a[i]=a[j];
            	a[j]=temp;
			}
        }
    }
    findMinCoin(a,n,amt);
    return 0;
}
