#include<stdio.h>
#include<climits>
#define MAX 100
int key[MAX];
int pi[MAX];
bool mst_flag[MAX];
int Q[MAX];       
int map[MAX]; 
int NIL=-1;
int heap_size = 0; 
void insert_to_minheap(int vertex)
{
    Q[heap_size] = vertex;
    map[vertex] = heap_size;
    heap_size++;
}
int extract_min()
{
    if (heap_size <= 0)
        return -1;
    int min_index = 0;
    for (int i = 1; i < heap_size; i++)
    {
        if (key[Q[i]] < key[Q[min_index]])
            min_index = i;
    }
    int min_vertex = Q[min_index];
    heap_size--;
    if (min_index != heap_size)
    {
        Q[min_index] = Q[heap_size];
        map[Q[min_index]] = min_index;
    }
    return min_vertex;
}
void decrease_key(int vertex, int new_key)
{
    key[vertex] = new_key;
}
void mst_prim(int g[MAX][MAX],int n,int r)
{
	int u;
	int v;
	for(u=0;u<n;u++)
	{
		key[u]=INT_MAX;
		mst_flag[u]=false;
		insert_to_minheap(u);
	}
	key[r]=0;
	pi[r]=NIL;
	while(heap_size>0)
	{
		u=extract_min();
		mst_flag[u]=true;
		for(v=0;v<n;v++)
	{
		{
			if(g[u][v]!=0 && mst_flag[v]==false && g[u][v]<key[v])
			{
				pi[v]=u;
				key[v]=g[u][v];
				decrease_key(v,g[u][v]);
			}
		}
	}
	}
}
int main()
{
    int g[MAX][MAX],n,r,cost=0;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : \n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&r);
    mst_prim(g,n,r);
    printf("\nMinimum Spanning Tree:\n");
    if (pi[r]==NIL)
    {
        printf("Edge: %d - %d, Weight: 0\n",r,r);
        cost+=0;
    }
    for (int i=0;i<n;i++)
    {
        if (pi[i]!=NIL)
        {
            printf("Edge: %d - %d, Weight: %d\n", pi[i],i,key[i]);
            cost=cost+key[i]; 
        }
    }
    printf("Total Minimum Cost: %d\n",cost); 
    return 0;
}
