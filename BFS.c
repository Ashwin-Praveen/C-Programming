


//	Algorithm to compute all the reachable nodes in a directed graph from the source vertex using-
//	- the breadth first algorithm




#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int A[SQ][SQ],Q[SQ],visited[SQ],n,i,j,f=0,r=-1,t;

int bfs(int v);

int main()
{
	int v;
	
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	Q[i]=0,visited[i]=0;

	printf("Enter the matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
	}

	printf("Enter the source vertex:\n");
	scanf("%d",&v);
	
	bfs(v);

	printf("The reachable nodes are:\n");
	for(i=1;i<=n;i++)
	{
		if(visited[i])
		printf("%d\t",i);
	}

	return 0;
}


int bfs(int v)
{	
	for(i=1;i<=n;i++)
	if(A[v][i] && !visited[i])
	Q[++r]=i;
	if(f<=r)
	visited[Q[f]]=1,bfs(Q[f++]);

	return 0;
}

