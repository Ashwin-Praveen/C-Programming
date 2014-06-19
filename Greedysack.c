#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

float knapsack(int P[SQ], int W[SQ], int n,int M);
float compute(int n, int P[SQ]);

float X[SQ];

int main()
{
	int P[SQ],W[SQ],i,n,Solution,M;

	printf("Enter the number of elements:\n");  
	scanf("%d",&n);

	printf("Enter the size of the knapsack:\n");
	scanf("%d",&M);	

	printf("Enter the profits of the objects:\n");
	for(i=0;i<n;i++)
	{
		printf("P[%d]:",i);
		scanf("%d",&P[i]);
		X[i]=0;
	}

	printf("\n\nEnter the weights of the objects:\n");
        for(i=0;i<n;i++)
        {
                printf("W[%d]:",i);
                scanf("%d",&W[i]);
        }

	
	Solution=knapsack(P,W,n-1,M);

	printf("\nThe optimum solution is:%d\nX[i]= {   ",Solution);
	for(i=0;i<n;i++)
	{
		if(X[i]==1 || X[i]==0)
		printf("%d   ",(int)X[i]);
		else
		printf("%f   ",X[i]);
	}
	printf("}\n\n");
		

	return 0;

}

float knapsack(int P[SQ], int W[SQ], int n, int M)
{
	int Remaining,i;
	float Sol;
	
	Remaining=M;
	
	for(i=0;i<=n;i++)
	{
		if(W[i]>Remaining)
		break;
		else
		X[i]=1;
		Remaining=Remaining-W[i];
	}

	if(i<=n)
	X[i]=((float)Remaining)/((float)W[i]);

	Sol=compute(n,P);
	
	return Sol;
}

float compute(int n, int P[SQ])
{
	int i;
	float sum=0;
	
	for(i=0;i<=n;i++)
	{
		sum=sum+P[i]*X[i];
	}

	return sum;
}
