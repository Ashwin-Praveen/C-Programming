#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int bin(int A[SQ], int n, int key);

int main()
{

	int n,i,A[SQ],key,ans;

	printf("Enter the number of elements in the array:\n");
	scanf("%d",&n);

	printf("Enter the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}

	printf("Enter the key:\n");
	scanf("%d",&key);

	ans=bin(A,n,key);

	if(ans!=-1)
	printf("The element is found in the index:%d\n",ans);

	else
	printf("Element not found\n");

	return 0;

}

int bin(int A[SQ], int n, int key)
{

	int start,end,mid;
	
	start=0;
	end=n-1;
	
	while(start<=end)
	{
		mid=(start+end)/2;
		if(A[mid]<key)
		start=mid+1;
		else if(A[mid]>key)
		end=mid-1;
		else
		return mid;
	}
	
	return -1;

}
