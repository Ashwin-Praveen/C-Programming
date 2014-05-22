#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int visited[SQ],adj[SQ][SQ],count=1,n;
int dfs(int i);

int main()
{
	int i,j;

	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%d",&adj[i][j]);
		
		visited[i]=0;
	}

	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		dfs(i);
	}
	
	printf("The count is:%d\n",count);
	
	if(n==count)
	printf("The graph given is connected\n");
	else 
	printf("The given graph isn't connectted!\n");

	return 0;
}

int dfs(int i)
{
	int j;

	visited[i]=1;

	for(j=1;j<=n;j++)
	{
		if(adj[i][j]==1 && !visited[j])
		{
			count=count+1;
			dfs(j);
		}
	}

	return j;
}

