#include<stdio.h>
#define INF 9999
#define MAX 100
int n;
int w[MAX][MAX];
int d[MAX][MAX];
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void floyd_warshall()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=w[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main()
{
	printf("ENTER THE SIZE OF THE ARRAY : ");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS OF THE ARRAY : ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		scanf("%d",&w[i][j]);
		if(w[i][j]==0 && i!=j)
		{
			w[i][j]=INF;
		}
		else if(i==j)
		{
			w[i][j]=0;
		}
	}
	}
	floyd_warshall();
	printf("SHORTEST PATH : ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]==INF)
			{
				printf("-");
			}
			else
			{
				printf("%d ",d[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
