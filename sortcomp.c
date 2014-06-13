#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int C[SQ];

int sortcomp(int A[SQ],int B[SQ], int high);

int main()
{

	int n,A[SQ],B[SQ],i;

	printf("Enter the number of elements:\n");
	scanf("%d",&n);

	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}


	sortcomp(A,B,n-1);
	
	printf("The array is sorted:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:%d\n",i,C[i]);
	}

	return 0;
}

int sortcomp(int A[SQ], int B[SQ], int high)
{
	int i,j;


	for(i=0;i<=high;i++)
	{
		B[i]=0;
	}
	
	for(i=0;i<high;i++)
	{
		if((i+1)!=high+1)
		for(j=i+1;j<=high;j++)
		{
			if(A[i]<A[j])
			B[j]++;
			else
			B[i]++;
		}
	}
		
	for(i=0;i<=high;i++)
	{
		C[B[i]]=A[i];
	}
	
	return 0;
}

