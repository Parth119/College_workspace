#include<stdio.h>
#include<time.h>
void display(int arr[],int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void selection(int a[], int n)
{
    int i,j,m,temp;
    for(i=0; i<n-1; i++)
    {
        m=i;
        for(j=i+1 ; j<n; j++)
        {
            if(a[m] > a[j])
            {
                m=j;
            }
        }
        if(m!=i)
        {
            temp = a[m];
            a[m] = a[i];
            a[i] = temp;
        }
    }
    display(a,n);
}
void main()
{
    int n,i=0,j=0,bst[10000],avg[10000],wst[10000];
    time_t start,end;
    double tc;

    printf("Enter number of element :");
    scanf("%d",&n);

    // best case
    for(i=0; i<=n; i++)
    {
        bst[i]=i;
    } 
    j=0;
    //worst case
    for(i=n;i>=0;i--)
    {
        wst[j]=i;
        j++;
    }
    j=0;
    //average case
    for(i=(n/2);i<=n;i++)
    {
        avg[j]=i;
        j++;
    }
    for(i=0;i<(n/2);i++)
    {
        avg[j]=i;
        j++;
    }
    printf("\nBest case:");
    display(bst,n);

    printf("\nAverage case:");
    display(avg,n);

    printf("\nWorst case:");
    display(wst,n);

    printf("\n\nSorting:");
    
    printf("\nBest case:");
    start=clock();
    selection(bst,n);
    end=clock();
    //printf("\n\nstart= %ld\n", start);
    //printf("end= %ld\n", end);
    //printf("clock per sec= %ld\n",CLOCKS_PER_SEC);
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);


    printf("\n\nAverage case:");
    start=clock();
    selection(avg,n);
    end=clock();
    //printf("\n\nstart= %ld\n", start);
    //printf("end= %ld\n", end);
    //printf("clock per sec= %ld\n",CLOCKS_PER_SEC);
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);
    
    printf("\n\nWorst case:");
    start=clock();
    selection(wst,n);
    end=clock();
    //printf("\n\nstart= %ld\n", start);
    //printf("end= %ld\n", end);
    //printf("clock per sec= %ld\n",CLOCKS_PER_SEC);
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency is %lf",tc);

}