#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int dij(int n,int src, int dist[SQ], int visited[SQ], int C[SQ][SQ]);

int main()
{
	int i,j,n,visited[SQ], dist[SQ], C[SQ][SQ],src;

	printf("Enter the number of vertices:\n ");
	scanf("%d",&n);
	
	printf("Enter the matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&C[i][j]);

	printf("Enter the source vertex:\n");
	scanf("%d",&src);

	dij(n,src,dist,visited,C);

	return 0;
}

int dij(int n,int src, int dist[SQ], int visited[SQ], int C[SQ][SQ])
{
	int i,count=1,min,u;

	for(i=1;i<=n;i++)
	{
		dist[i]=C[src][i];
		visited[i]=0;
	}
	
	while(count!=n)
	{
		min=99;
		
		for(i=1;i<=n;i++)
		{
			if(dist[i]<min && visited[i]!=1)
			{
				min=dist[i];
				u=i;
			}
		}

		for(i=1;i<=n;i++)
		{
			if(C[src][i]+min<dist[i] && visited[i]!=1)
			dist[i]=C[src][i]+min;
		}

		count++;
		visited[u]=1;
	}

	for(i=1;i<=n;i++)
	printf("%d-->%d:%d\n",src,i,dist[i]);
	printf("\n");

	return count;
}
