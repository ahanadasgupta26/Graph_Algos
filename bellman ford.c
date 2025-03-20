#include<stdio.h>
#include<climits>
#define MAX 100
int n;
int d[MAX];
int p[MAX];
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
bool bellman_ford(int w[MAX][MAX],int s) 
{
    initialize_single_source(s);
    for(int i=0;i<n-1;i++) 
	{
        for(int u=0;u<n;u++) 
		{
            for(int v=0;v<n;v++) 
			{
                if(w[u][v]!=INT_MAX) 
				{
                    relax(u,v,w);
                }
            }
        }
    }
    for(int u=0;u<n;u++) 
	{
        for(int v=0;v<n;v++) 
		{
            if(w[u][v]!=INT_MAX && d[v]>d[u]+w[u][v]) 
			{
                return false;
            }
        }
    }
    return true;
}
int main() 
{
    int g[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            scanf("%d",&g[i][j]);
            if(g[i][j]==0 && i!=j) 
			{
                g[i][j]=INT_MAX;
            }
        }
    }
    int source;
    printf("Enter the source vertex: ");
    scanf("%d",&source);
    if(bellman_ford(g,source)) 
	{
        printf("No negative weight cycle found. Shortest distances from source %d:\n",source);
        for(int i=0;i<n;i++) 
		{
            printf("Vertex %d: Distance = %d\n",i,d[i]);
        }
    } 
	else 
	{
        printf("Negative weight cycle detected.\n");
    }
    return 0;
}
