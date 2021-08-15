#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1= m - l + 1;
    int n2= r - m;

    int L[n1], R[n2];

    for(i=0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(j=0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i=0;
    j=0;
    k=l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k]= R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k]= R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int  l, int r)
{
    if(l < r)
    {
        int m= l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void main()
{
    int i, n, j, bst[1000], avg[1000], wst[1000];
    time_t start,end;
    double tc;
    printf("Enter the number of element :");
    scanf("%d",&n);
    // best case
    for(i=0;i<n;i++)
    {
        bst[i]=i+1;
    }
    // avg case
    j=0;
    for(i=(n/2); i<=n; i++)
    {
        avg[j]=i;
        j++;
    }
    for(i=1; i<(n/2); i++)
    {
        avg[j]=i;
        j++;
    }
    // worst case
    j=0;
    for(i=n; i>0; i--)
    {
        wst[j]=i;
        j++;
    }
    printf("\nBest Case :\n");
    display(bst,n);

    printf("\nAverage Case :\n");
    display(avg,n);

    printf("\nWorst Case :\n");
    display(wst,n);

    printf("\n\nSorting-----------------------------------");
    printf("\nBest Case :\n");
    start=clock();
    mergeSort(bst, 0, n-1);
    display(bst,n);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime Efficiency is %lf",tc);

    printf("\n\nAverage Case :\n");
    start=clock();
    mergeSort(avg, 0, n-1);
    display(avg,n);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime Efficiency is %lf",tc);

    printf("\n\nWorst Case :\n");
    start=clock();
    mergeSort(wst, 0, n-1);
    display(wst,n);
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("\nTime Efficiency is %lf",tc);
}