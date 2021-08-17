#include<stdio.h>
#include<time.h>
#define size 100
void main()
{
    int arr[size],i,flag=0,n,ele,pos=0;
    time_t start,end;
    double tc;
    printf("\nEnter number of element to be inserted :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the %d Element :",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element to be searched :");
    scanf("%d",&ele);

    start=clock();
   
    for(i=0;i<n;i++)
    {
       
        if(arr[i]==ele)
        {
            flag=1;
            pos=i;
        }
    }
    if(flag==1)
    {
        printf("\nThe %d element found at position %d.",ele,(pos+1));
    }
    else
    {
        printf("\nThe element %d is not found in given list!",ele);
    }
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime efficiency is %lf",tc);
}