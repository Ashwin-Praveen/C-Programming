#include<stdio.h>
#include<stdlib.h>
#define SQ 10

int main()
{
	int queen(int n,int count);
	int place(int x[SQ],int k);
	int display(int x[SQ], int n);

	int n ,ans;

	printf("Enter the number of queens to be inputted:\n");
	scanf("%d",&n);
	printf("\n");
	ans=queen(n,0);
	printf("Number of solutions for %d queens is %d \n",n,ans);
	
	return 0;
}

int queen(int n,int count)
{
	int k,x[SQ];
	k=1,x[k]=0;
	
	while(k!=0)
	{
		x[k]++;			//Place the Kth queen in the next column
		while((place(x,k)!=1) && x[k]<=n)
		{
			x[k]++;		//Place the qeen in the next column
		}	
		if(x[k]<=n)		//Is the queen succesfully placed?
		{
			if(k==n)	//If all the queens are placed
			{
				count++;
				display(x,n);
				printf("\n\n\n");
			}
			else
			{
				k++;		//select the next place
				x[k]=0;		//but don't place
			}
		}
		else 
		{
			k--;			//backtrack and select preview queen 
		}
	}					//Placing the queen at appropriate position

	return count;

}


int place(int x[SQ],int k)
{
	int i;
	
	for(i=1;i<k;i++)
	{
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
		{
			return 0;
		}
	}
	return 1;
}

int display(int x[SQ],int n)
{
	char chess[SQ][SQ];
	int i,j;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	chess[i][j]='X';
	for(i=1;i<=n;i++)
	chess[i][x[i]]='Q';
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c\t",chess[i][j]);
		}	
		printf("\n");
	}

	return 0;
}

