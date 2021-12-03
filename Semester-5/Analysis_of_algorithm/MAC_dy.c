#include <stdio.h>
#include <limits.h>
void make_a_change_dynamic(int num,int d[],int rate);
int min(int x,int y);
int main()
{
    int num, rate, i;
    int d[4];
    printf("Enter total number of coins : ");
    scanf("%d",&num);
    printf("Enter the denomination of the coins : ");
    for(i=1;i<=num;i++) 
    {
        scanf("%d",&d[i]);
    }
    printf("Enter the total amount : ");
    scanf("%d",&rate);
    make_a_change_dynamic(num,d,rate);
    return 0;
}

void make_a_change_dynamic(int num,int d[],int rate) 
{
    int c[10][10], i=0, j=0, pointer, count=0;
    for(i=1;i<=num;i++) 
        c[i][0] = 0;
    	for(i=1;i<=num;i++) 
        {
        	for(j=1;j<=rate;j++) 
            { 
            	if(i==1 && j<d[i]) 
                	c[i][j] = INT_MAX;
            	else if(i==1) 
                	c[i][j] = 1 + c[1][j-d[1]];
            	else if(j<d[i]) 
                	c[i][j] = c[i-1][j];
            	else
                	c[i][j] = min(c[i-1][j], (1 + c[i][j-d[i]]));
        	}
    	}
    	printf("Amount:   ");
    	for(j=0;j<=rate;j++) 
        	printf("%2d  ",j);
    	printf("\n---------------------------------------------------------\n");
    	for(i=1;i<=num;i++) 
        {
        	printf("d%d = %d    ",i,d[i]);
        	for(j=0;j<=rate;j++) 
            {
            	printf("%2d  ",c[i][j]);
        	}
        	printf("\n");
    	}
    	printf("\nAnswer:\nNumber of coins required to pay an amount %d : %d",rate,c[num][rate]);
    	printf("\n coin_denomination    no_of_coin");
    	printf("\n------------------------------------------\n");
   	    i=num, j=rate;
    	while(c[i][j] != c[1][0]) 
        { 
        	if(c[i][j] == c[i-1][j]) 
            {
            	i=i-1;
            	j=j;
        	}
        	else 
            {
            	count++;
            	printf("     %d                  %d\n",d[i],1);
            	i=i;
            	j=j-d[i];
        	}
    	}
    	printf("---------------------------------\n");
    	printf("     %d                  %d",rate,count);
}

int min(int x,int y) 
{
    return((x<y)?x:y);
}
