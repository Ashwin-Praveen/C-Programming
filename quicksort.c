#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int Exchange(int *a, int *b);
int Quicksort(int A[SQ], int low, int high);
int Partition(int A[SQ], int low, int high);

int A[SQ];

int main()
{
	int i,n;

	printf("Enter the number of elements:\n");
	scanf("%d",&n);

	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]",i);
		scanf("%d",&A[i]);
	}

	Quicksort(A,0,n-1);
	
	printf("The elements are sorted:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:%d\n",i,A[i]);
	}

	return 0;
}

int Quicksort(int A[SQ], int low, int high)
{
	int j;
	
	if(low<high)
	{
		j=Partition(A,low,high);
		printf("\n\nThe partition index:%d\n\n",j);

		Quicksort(A,low,j-1);
		Quicksort(A,j+1,high);
	}

	return 0;
}

int Partition(int A[SQ], int low, int high)
{
	int pivot,i,j,temp;

	pivot=A[low];
	i=low+1;
	j=high;

	while(i<=j)
	{
		while(i<=high && pivot>=A[i])
		i++;
	
		while(pivot<A[j])
		j--;
		
		if(i<j)
		Exchange(&A[i],&A[j]);
		
		else
		Exchange(&A[j],&A[low]);
	
	}

	return j;

}

int Exchange(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;

	return 0;
}
