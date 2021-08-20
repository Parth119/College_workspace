#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 5
int display_mst(int parent_arr[], int arr[V][V],int node)
{
    int i,sum=0;
    if(node!= 0)
    {
        printf("\nEdge:\tWeight\n");
        for(i=1;i<V;i++)
        {
            printf("%d edge (%d,%d) = %d\n",i,parent_arr[i],i,arr[i][parent_arr[i]]);
            sum=sum+arr[i][parent_arr[i]];
        }
        printf("\nMinimum cost = %d\n",sum);
    }
    else if(node == 0)
    {
        printf("\nEdge:\tWeight\n");
        for(i=1;i<V;i++)
        {
            printf("%d edge (%d,%d) = %d\n",i,(parent_arr[i]+1),i+1,arr[i][parent_arr[i]]);
            sum=sum+arr[i][parent_arr[i]];
        }
        printf("\nMinimum cost = %d\n",sum);
    }
    else
    {
        printf("\nInvalid data entered!");
    }
}
/* checks the smallest key from given graph */
int minKey(int key[],bool mstSet[])
{
    int min=INT_MAX,min_index,v;
    
    for(v=0;v<V;v++)
    {
        if((mstSet[v] == false) &&  key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void prim(int arr[V][V])
{
    int parent_arr[V];
    int key_arr[V];
    bool mstSet[V];
    int i,count,u,v,node;

    for(i=0;i<V;i++)
    {
        mstSet[i]=false;
        key_arr[i]=INT_MAX;
    }
    key_arr[0]=0;
    parent_arr[0]=-1;

    for(count=0;count<V-1;count++)
    {
        u=minKey(key_arr,mstSet);
        mstSet[u]=true;

        for(v=0;v<V;v++)
        {
            if(arr[u][v] && mstSet[v]==false && arr[u][v] < key_arr[v])
            {
                parent_arr[v]= u;
                key_arr[v]=arr[u][v];
            }
        }
    }
    printf("\nGiven problem has node 0 ?\nTrue: 0 and false: 1\nEnter your choice [0/1]:");
    scanf("%d",&node);
    display_mst(parent_arr, arr,node);
}
void main()
{
    int arr[V][V],i,j;
    printf("\nEnter the Elements in matrix :\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    prim(arr);
}