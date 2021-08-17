#include<stdio.h>
#include<time.h>

void main()
{
    int a[100],i,j,k,temp,n,ele,low,mid,high,flag;
    double tc;
    time_t start,end;

    printf("\nEnter the number of element to be inserted :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter [%d] Element :",i+1);
        scanf("%d",&a[i]);
    }

    printf("Sorted array :\n");
    start=clock();
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;

            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime complexity of Sorting the element is :%lf",tc);

    printf("\nEnter element to search :");
    scanf("%d",&ele);

    flag=0;
    low=0;
    high=n-1;
    start=clock();
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    while(low <= high)
    {
        mid=(low+high)/2;
        if(ele==a[mid])
        {
            printf("\nThe element %d found at %d position.",ele,mid+1);
            flag=1;
            break;
        }
        else if(ele < a[mid])
        {
            high= mid-1;
        }
        else
        {
            low= mid+1;
        }
    }

    if(flag==0)
    {
        printf("\nElement %d not found!",ele);
    }
    end=clock();

    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime efficiency of Binary sort :%lf",tc);
}