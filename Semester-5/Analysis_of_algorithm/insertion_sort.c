#include<stdio.h>
#include<time.h>
#define max 1000

void display(int a[], int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insertion(int number[], int count)
{
    int temp,i,j;
    for(i=1;i<count;i++)
   {
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0))
      {
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
   {
        printf(" %d",number[i]);
   }
}
void main()
{

    int i, j,worst[max],best[max],avg[max],count;
    time_t start, end;
    double tc;

    printf("Enter Number you want :");
    scanf("%d",&count);

    //For best case:
    printf("\nBest case :");
    for(i=0;i<count;i++)
    {
       best[i] = i;
    }
    display(best,count);


    //For Average case:
    printf("\nAverage case :");
    j = 0;
    for(i=(count/2);i>=0;i--)
    {
        avg[j] = i;
        j++;
    }
    for(i=((count/2)+1);i<count;i++)
    {
        avg[j] = i;
        j++;
    }
    display(avg,count);
    //For worst case:
    printf("\nWorst case :");
    j=0;
    for(i=count;i>0;i--)
    {
        worst[j] = i-1;
        j++;
    }
    display(worst,count);

    printf("\n\nSorting:");
    printf("\nBest Case:\n");
    start=clock();
    insertion(best,count);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);

    printf("\n\nAverage Case:\n");
    start=clock();
    insertion(avg,count);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);

    printf("\n\nWorst Case:\n");
    start=clock();
    insertion(worst,count);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);
}