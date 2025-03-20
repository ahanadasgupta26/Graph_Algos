#include<stdio.h>
#include<climits>
#define MAX 100
int n,size=0;
int d[MAX];
int p[MAX];
int Q[MAX];
void initialize_single_source(int s)
{
	int v;
	int NIL=-1;
    for(v=0;v<n;v++)
	{
		d[v]=INT_MAX;
		p[v]=NIL;
	}	
	d[s]=0;
}
void relax(int u,int v,int w[MAX][MAX])
{
	if(d[v]>(d[u]+w[u][v]))
	{
		d[v]=d[u]+w[u][v];
		p[v]=u;
	}
}
int extract_min(int Q[],int *size) 
{
    int min=Q[0];
    Q[0]=Q[*size-1];
    (*size)--;
    return min;
}
void decrease_key(int v,int new_dist) 
{
    d[v]=new_dist;
}
void insert_min_heap(int Q[],int *size,int v) 
{
    Q[*size]=v;
    (*size)++;
}
void dijkstra(int g[MAX][MAX],int w[MAX][MAX],int s)
{
	int u,v;
	initialize_single_source(s);
	for(int i=0;i<n;i++) 
	{
        insert_min_heap(Q,&size,i);
    }
	while(size>0) 
	{
        u=extract_min(Q,&size);
        for(v=0;v<n;v++) 
		{
            if(w[u][v]!=0) 
			{
                relax(u,v,w);
                decrease_key(v,d[v]);
            }
        }
    }
    for (int i=0;i<n;i++) 
	{
        printf("VERTEX : %d\nDistance : %d\n\n",i,d[i]);
    }
}
int main() 
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int g[MAX][MAX],w[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i=0;i<n;i++) 
	{
        for (int j=0;j<n;j++) 
		{
            scanf("%d",&w[i][j]);
            if (w[i][j]==0) 
			{
                g[i][j]=0;
            } 
			else 
			{
                g[i][j]=1;
            }
        }
    }
    int s;
    printf("Enter source vertex: ");
    scanf("%d",&s);
    dijkstra(g,w,s);
    return 0;
}
