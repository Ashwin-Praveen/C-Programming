#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int sortdist(int A[SQ],int high);
int Exchange(int *A, int *B);
int LBB(int A[SQ], int high);
int UBB(int A[SQ], int high);

int B[SQ];

int main()
{
	int n,i,A[SQ];

	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		printf("A[%d]:",i);
		scanf("%d",&A[i]);
	}

	sortdist(A,n-1);

	printf("The elements are sorted:\n");
	for(i=0;i<n;i++)
	printf("A[%d]:%d\n",i,B[i]);

	return 0;

}

int sortdist(int A[SQ], int high)
{
	int D[SQ],i,j,UB,LB,X[SQ],Y[SQ];					

	for(i=0;i<=high;i++)
	X[i]=Y[i]=A[i];

	UB=UBB(X,high);					//computes upperbound
	LB=LBB(Y,high);					//and lower bound respectively

		
	for(i=0;i<=(UB-LB);i++)
	D[i]=0;

	for(j=0;j<=high;j++)
	{
		i=A[j]-LB;
		D[i]=D[i]+1;
	}

	
	for(i=1;i<=(UB-LB);i++)
	D[i]=D[i]+D[i-1];	

	for(j=0;j<=high;j++)
	{
		i=A[j]-LB;
		D[i]=D[i]-1;
		B[D[i]]=A[j];
	}

	return 0;
}



int UBB(int A[SQ], int high)
{
	int i;
	
	for(i=1;i<=high;i++)
	if(A[0]<A[i])
	Exchange(&A[0],&A[i]);

	return A[0];
}

int Exchange(int *A, int *B)
{
	int temp;

	temp=*A;
	*A=*B;
	*B=temp;
		
	return 0;
}

int LBB(int A[SQ], int high)
{
        int i;

        for(i=1;i<=high;i++)
        if(A[0]>A[i])
        Exchange(&A[0],&A[i]);

        return A[0];
}
