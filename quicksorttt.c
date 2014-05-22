#include<stdio.h>
#include<stdlib.h>
#define SQ 20 
int A[SQ];

int Quicksort(int A[SQ], int start,int end);
int Partition(int A[SQ], int start , int end);

int main()
{
	int n,i;

	printf("Enter the number of elements of the array:\n"); 
	scanf("%d",&n);
	
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}

	Quicksort(A,0,n-1);

	printf("\n\nThe array is sorted:\n\n");
	for(i=0;i<n;i++)
	printf("A[%d]:%d\n",i,A[i]);

	return 0;
}

int Quicksort(int A[SQ],int start, int end)
{
	int PIndex;
	
	
	if(start<end)
	{
		PIndex=Partition(A,start,end);
		Quicksort(A,start,PIndex-1);
		Quicksort(A,PIndex+1,end);
	}

	return 0;

}

int Partition(int A[SQ], int start, int end)
{
	int pivot,temp,i,PIndex;

	pivot=A[end];
	PIndex=start;

	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			temp=A[i];
			A[i]=A[PIndex];
			A[PIndex]=temp;
			PIndex++;
		}
	}
	temp=A[PIndex];
	A[PIndex]=A[end];
	A[end]=temp;

	return PIndex;
}
