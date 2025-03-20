#include<stdio.h>
#define MAX 100
int t=0;
int adj[MAX][MAX],c[MAX],p[MAX],d[MAX],f[MAX];
void dfs_visit(int u,int n)
{
	int white=0,gray=1,black=2;
	int v;
	c[u]=gray;
	d[u]=++t;
	for(v=0;v<n;v++)
	{
		if(adj[u][v]==1 && c[v]==white)
		{
			p[v]=u;
			dfs_visit(v,n);
		}
	}
	c[u]=black;
	f[u]=++t;
}
void dfs(int n)
{
	int u;
	int white=0,NIL=-1;
	for(u=0;u<n;u++)
	{
		c[u]=white;
		p[u]=NIL;
	}
	for(u=0;u<n;u++)
	{
		if(c[u]==white)
		{
			dfs_visit(u,n);
		}
	}
}
int main()
{
	int n,i,j;
	printf("ENTER THE SIZE : ");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS OF THE ARRAY : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	dfs(n);
	for(i=0;i<n;i++)
	{
		printf("VERTEX %d \n DISCOVERY TIME %d \n FINISH TIME %d \n",i,d[i],f[i]);
	}
	return 0;
}
