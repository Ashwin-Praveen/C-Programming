#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int Merge(int low,int mid, int high);
int Mergesort(int low, int high);

int A[SQ],C[SQ];

int main()
{
	int i,n;

	printf("Enter the number of elements:\n");
	scanf("%d",&n);

	printf("Enter the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}
		
	Mergesort(0,n-1);

	printf("Array is sorted:\n");
	for(i=0;i<n;i++)
	printf("A[%d]:%d\n",i,A[i]);

	return 0;
}

int Mergesort(int low, int high)
{
	int mid; 

	if(low<high)
	{
		mid=(low+high)/2;
		Mergesort(low,mid);
		Mergesort(mid+1,high);
		Merge(low,mid,high);
	}

	return 0;
}

int Merge(int low, int mid, int high)
{
	int k,i,j;

	i=k=low;
	j=mid+1;
	
	while(i<=mid && j<=high)
	{
		if(A[i]<A[j])
		C[k++]=A[i++];
		else
		C[k++]=A[j++];
	}
		
	while(i<=mid)
	C[k++]=A[i++];

	while(j<=high)
	C[k++]=A[j++];

	for(i=0;i<=high;i++)
	A[i]=C[i];

	return 0;
}


