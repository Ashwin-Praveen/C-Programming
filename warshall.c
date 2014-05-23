#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int warshall(int C[SQ][SQ], int n);

int main()
{
	int C[SQ][SQ], n,i,j;

	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&C[i][j]);

	warshall(C,n);
	
	printf("The solved matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
		
	return 0;

}

int warshall(int C[SQ][SQ], int n)
{
	int i,j,k;

	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	if(C[i][k]==1)
	for(j=1;j<=n;j++)
	C[i][j]=C[i][j]||C[k][j];


	return 0;
}
