#include<stdio.h>
#include<climits>
#define MAX 100
typedef struct queue
{
    int arr[MAX];
	int front,rear;	
}q;
int isempty(queue *q)
{
	return q->front==-1;
}
void enqueue(queue *q,int value)
{
	if(q->rear==MAX-1)
	{
		printf("QUEUE IS FULL");
	}
	if(q->front==-1)
	{
		q->front=0;
	}
	q->rear++;
	q->arr[q->rear]=value;
}
int dequeue(queue *q)
{
     int a;
	 if(isempty(q))
	 {
	 	printf("QUEUE IS EMPTY");
	 	return -1;
	 }
	 else
	 {
	 	a=q->arr[q->front];
	 	q->front++;
	 	if(q->front>q->rear)
	 	{
	 		q->front=q->rear=-1;
		 }
		 return a;
	 }	
}
void bfs(int adj[MAX][MAX],int s)
{
	int white=0,gray=1,black=2;
	int NIL=-1;
	int u,v;
	queue q;
	q.front=q.rear=-1;
	int c[MAX],d[MAX],p[MAX];
	for(u=0;u<4;u++)
	{
		c[u]=white;
		d[u]=INT_MAX;
		p[u]=NIL;
	}
	c[s]=gray;
	enqueue(&q,s),d[s]=0;
	while(isempty(&q)==0)
	{
		u=dequeue(&q);
		printf("VISITED %d\n",u);
	for(v=0;v<4;v++)
	{
		if(adj[u][v]==1 && c[v]==white)
		{
			c[v]=gray;
			enqueue(&q,v);
			p[v]=u;
			d[v]=d[u]+1;
		}
	}
	c[u]=black;
    }
}
int main()
{
	int adj[MAX][MAX]={{0,1,1,0},{1,0,0,1},{1,1,0,1},{0,1,0,0}};
	int s=3;
	bfs(adj,s);
	return 0;
}
