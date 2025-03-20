#include<stdio.h>
#define M 100
typedef struct stack 
{
    int items[M];
    int top;
}stack;
enum color {white, gray, black};
void push(stack *st, int value) 
{
    if (st->top<M-1) 
	{
        st->items[++(st->top)]=value;
    } 
	else 
	{
        printf("Stack overflow\n");
    }
}
void display(stack st) 
{
    int i;
    for (i=st.top;i>=0;i--) 
	{
        printf("%d ",st.items[i]);
    }
    printf("\n");
}
void dfs_visit(int adj[][M],int u,enum color c[],int p[],int d[],int f[],int n,stack *st)
{
	int v;
	int time=0;
	c[u]=gray;
	printf("%d\n",u);
	d[u]=++time;
	for(v=0;v<n;++v)
	{
		if(adj[u][v]==1)
		{
			if(c[v]==white)
			{
				p[v]=u;
				dfs_visit(adj,v,c,p,d,f,n,st);
			}
		}
	}
    f[u]=++time;  
	c[u]=black;      
    push(st,u);
}
void topo(int adj[][M],enum color c[],int p[],int d[],int f[],int n)
{
	int u;
	stack st;
	st.top = -1;
	for(u=0;u<n;++u)
	{
		c[u]=white;
		p[u]=-1;
	}
	for(u=0;u<n;++u)
	{
		if(c[u]==white)
		{
			dfs_visit(adj,u,c,p,d,f,n,&st);
		}
	}
	printf("TOPOLOGICAL SORT: ");
	display(st);
}
int main() 
{
    int n, i, j;
    int adj[M][M];
    enum color c[M];
    int p[M], d[M], f[M];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }
    topo(adj, c, p, d, f, n);
    return 0;
}
