/*

	uses the topological ordering, using source removal method

*/




#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int temp[SQ],k=0;
int topological(int A[SQ][SQ], int n, int indegree[SQ]);

int main()
{
	int i,j,n,indegree[SQ],A[SQ][SQ];

	printf("Enter number of vertices:\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	indegree[i]=0;

	printf("Enter the matrix:\n");	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&A[i][j]);
			if(A[i][j]==1)
			indegree[j]++;
		}
	}
	
	topological(A,n,indegree);
		
	if(k!=n)
	printf("The ordering isn't possible\n");
	else
	printf("The ordering is possible\n");
	for(i=1;i<=n;i++)
	printf("%d\t",temp[i]);

	return 0;
}


int topological(int A[SQ][SQ], int n, int indegree[SQ])
{
	int i,j;

	for(i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			indegree[i]=1;
			temp[++k]=i;
			for(j=1;j<=n;j++)
			{
				if(A[i][j] && indegree[k]!=-1)
				indegree[j]--;
			}

			i=0;
		}
		
	}

	return 0;
}

