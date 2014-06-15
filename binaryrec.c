#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int mid;
int bin(int A[SQ], int key , int start, int end);

int main()
{
	int i,A[SQ],ans,n,key;

	printf("Enter the number of elements in the array:\n");
	scanf("%d",&n);

	printf("Enter the elements in the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}

	printf("ENter the key to be searched:\n");
	scanf("%d",&key);

	ans=bin(A,key,0,n-1);

	if(ans!=-1)
	printf("The element exists in the index:%d\n",i);
	
	else
	printf("Element not found\n");

	return 0;
}

int bin(int A[SQ], int key , int start, int end)
{
	
	if(start==end)
	{
		if(key==A[start])
		return mid;
		else 
		return -1;
	}

	else
	{
		mid=(start+end)/2;
		if(A[mid]<key)
		return bin(A,key,mid+1,end);
		else
		return bin(A,key,start,mid-1);
		
	}
}


