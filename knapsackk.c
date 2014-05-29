#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int maximum(int a,int b);
int knap(int n,int m,int P[SQ], int W[SQ]);

int main()
{
	int n,m,i,j,W[SQ],P[SQ];

	printf("Enter the number of objects:\n");
	scanf("%d",&n);

	printf("Enter the object's weight:\n");
	for(i=1;i<=n;i++)
	{
		printf("W[%d]:",i);
		scanf("%d",&W[i]);
	}

	printf("Enter the profit's of the objets:\n");
	for(i=1;i<=n;i++)
	{
		printf("P[%d]:",i);
		scanf("%d",&P[i]);
	}

	printf("Please type in the capacity of the knapsack:\n");
	scanf("%d",&m);
	
	knap(n,m,P,W);

	return 0;
}

int maximum(int a,int b)
{
	return a>b?a:b;
}


int knap(int n,int m,int P[SQ], int W[SQ])
{
	int i,j,visited[SQ][SQ],x[SQ];
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			visited[i][j]=0;
			else if(j<W[i])
			visited[i][j]=visited[i-1][j];
			else	
			visited[i][j]=maximum(visited[i-1][j],visited[i-1][j-W[i]]+P[i]);
		}
	}

	printf("The optimal solution is:%d\n",visited[n][m]);
	
	for(i=1;i<=n;i++)
	x[i]=0;
	i=n;j=m;

	while(i!=0 && j!=0)
	{
		if(visited[i][j]!=visited[i-1][j])
		{
			x[i]=1;
			j=j-W[i];
		}
	i=i-1;
	}

	printf("Colalnial solution:\n");
	for(i=1;i<=n;i++)
	printf("X[%d]:%d\t",i,x[i]);
	printf("\n");

	return 0;
	
}
