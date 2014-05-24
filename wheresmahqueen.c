#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int queen(int n,int count);
int place(int x[SQ], int k);
int display(int x[SQ], int n);

int main()
{
	int ans,n;
		
	printf("Enter the number of queens:\n");
	scanf("%d",&n);
	printf("\n");

	ans=queen(n,0);

	printf("\n\nThe number of solutions:%d\n\n",ans);
	
	return 0;
}

int queen(int n,int count)
{
	int i,j;
	int k,x[SQ];
	
	k=1,x[k]=0;

	while(k!=0)
	{
		x[k]++;
		while(place(x,k)!=1 && k<=n)
		{
			x[k]++;
		}

		if(x[k]<=n)	
		{
			if(k==n)
			{
				count++;
				printf("\n\n");
				display(x,n);
				printf("\n\n");
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		k--;

	}

	return count;

}

int place(int x[SQ],int k)
{

	int i;
	for(i=1;i<k;i++)
	{
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
		return 0;
	}

	return 1;
}

int display(int x[SQ], int n)
{
	int i,j;
	char chess[SQ][SQ];

	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	chess[i][j]='X';
	
	for(i=1;i<=n;i++)
	chess[i][x[i]]='Q';

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c ",chess[i][j]);	
		}
		printf("\n");
	}

	return 0;
}
