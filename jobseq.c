#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int J[SQ];

int JobSeq(int P[SQ], int D[SQ], int n);

int main()
{
	int D[SQ],P[SQ],i,n,ans; 

	printf("Enter the number of jobs:\n");	
	scanf("%d",&n);

	printf("Enter the profits of the jobs:\n");
	for(i=1;i<n;i++)
	{
		printf("P[%d]:",i);
		scanf("%d",&P[i]);
	}

	printf("Enter the deadlines:\n");
	for(i=1;i<n;i++)
	{
		printf("D[%d]:",i);
		scanf("%d",&D[i]);
	}

	ans=JobSeq(P,D,n-1);

	printf("\nThe max profit is:%d\n\n",ans);

	printf("J[i]:{  ");
	for(i=0;i<=n;i++)
	printf("%d  ",J[i]);
	printf("}\n\n");

	return 0;

}

int JobSeq(int P[SQ], int D[SQ], int n)
{
	int i,r,k,q;

	D[0]=J[0]=0;
	k=J[1]=1;
	
	for(i=2;i<=n;i++)
	{
		r=k;
		while( (D[J[r]]>D[i]) && (D[J[r]]!=r) )
		r=r-1;
		if( (D[J[r]]<=i) &&  (D[i]>r) )	
		{
			for(q=k;q>=r+1;k--)
			J[q+1]=J[q];
			J[r+1]=i;
			k++;
		}
	}

	return k;

}
	
