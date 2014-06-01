#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int primalg(int C[SQ][SQ], int n);

int main()
{
	int C[SQ][SQ],n,i,j,cost;

	printf("Enter the number of vertices:\n");	
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{	
			scanf("%d",&C[i][j]);
			if(C[i][j]==0)
			C[i][j]=99;
		}
	}

	cost=primalg(C,n);

	printf("The cost of the minimum spanning tree is:%d\n",cost);
	
	return 0;
}

int primalg(int C[SQ][SQ], int n)
{
	int i,j,k,u,v,min,mincost=0;
	int visited[SQ];

	visited[1]=1;
	for(k=2;k<=n;k++)
	visited[k]=0;

	for(k=1;k<=n-1;k++)
	{
		min=99;
		u=1;
		v=1;

		for(i=1;i<=n;i++)
		{	
			if(visited[i]==1)
			for(j=1;j<=n;j++)
			{
				if(C[i][j]<min)
				{
					min=C[i][j];
					u=i;
					v=j;
				}
			}
		}
	
		mincost=mincost+C[u][v];
		visited[v]=1;

		printf("%d--->%d:%d\n",u,v,C[u][v]);
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(visited[i]&&visited[j])
				C[i][j]=C[j][i]=99;
			}
		}
	
	}

	return mincost;

}
