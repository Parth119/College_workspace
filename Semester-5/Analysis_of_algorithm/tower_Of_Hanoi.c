#include<stdio.h>
#include<time.h>
void Hanoi(int disk,char source,char dest,char aux)
{
    if(disk==1)
    {
        printf("\nMove Disk %d from rod  %c to %c",disk,source,dest);
    }
    else
    {
        Hanoi(disk - 1, source, aux, dest);
        printf("\nMove Disk %d from rod  %c to %c",disk,source,dest);
        Hanoi(disk - 1, aux, dest, source);
    }
}
int main()
{
    int n;
    time_t start,end;
    printf("\nEnter total number of Disk:");
    scanf("%d",&n);
    printf("Following are Move Sequence:");
    start=clock();
    Hanoi(n,'A','B','C');
    end=clock();
    printf("\nExecution time :%lf",(float)(end-start)/CLOCKS_PER_SEC);
}
