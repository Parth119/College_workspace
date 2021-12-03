#include<stdio.h>
#include<time.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void heapify(int arr[], int n, int i) 
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
  

    if (largest != i) 
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
  
  
void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) 
    {
      swap(&arr[0], &arr[i]);  
      heapify(arr, i, 0);
    }
}
  
  
void printAr(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
  
    
void main() 
{
    int n;
    clock_t start,end;
    float runtime;
    printf("Enter size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d :",i+1);
        scanf("%d",&arr[i]);
    }
   

    start=clock();

    heapSort(arr, n);
  
    printf("Sorted array is \n");
    printAr(arr, n);

    end=clock();
    runtime=(float)(end-start)/(CLOCKS_PER_SEC);
    printf("\ntime analysis: %f",runtime);
}
