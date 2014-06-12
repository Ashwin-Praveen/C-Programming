#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int InsertionSort(int A[SQ], int high);

int main()
{

	int n,A[SQ],i;

	printf("Enter the number of elements:\n");
	scanf("%d",&n);

	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}

	InsertionSort(A,n-1);

	printf("\n\nThe array is sorted:\n\n");
	for(i=0;i<n;i++)
	printf("A[%d]:%d\n",i,A[i]);

	return 0;
}

int InsertionSort(int A[SQ], int high)
{
	int i,hole,value;

	for(i=1;i<=high;i++)
	{
		value=A[i];	
		hole=i;		

		while(hole!=0 && A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			hole--;
		}
		
		A[hole]=value;
	}

	return 0;
}
