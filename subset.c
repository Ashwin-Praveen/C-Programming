#include<stdio.h>
#include<stdlib.h>
#define SQ 20 

int set(int n , int d, int S[SQ]);

int main()
{
	int i,S[SQ],n,d;

	printf("Enter the number of elemenst in the set:\n");
	scanf("%d",&n);
	
	printf("Enter the elemets of the set:\n");
	for(i=0;i<n;i++)
	{
		printf("S[%d]:",i);
		scanf("%d",&S[i]);
	}

	printf("Enter the sum:\n");
	scanf("%d",&d);
	
	set(n,d,S);

	return 0;
}

int set(int n, int d, int S[SQ])
{
	int k=0,i,found=0,sum=0,set[SQ],g=0;

	set[k]=1;
	
	for(i=1;i<n;i++)
	set[i]=30;

	while(1) 
	{
		if(k<n && set[k]==1)
		{
			if(sum+S[k]==d)
			{
				g++;
				found=1;
				printf("The %d solution:\t{",g);
				for(i=0;i<n;i++)
				if(set[i]==1)
				{
					printf("%d",S[i]);
					printf(",");
				}
				printf("0}");
				printf("\n");
			}
			else if(sum+S[k]<d)
			sum=sum+S[k];
			else
			set[k]=0;
		}
		else
		{
			k--;
			while(k>=0 && set[k]==0)
			k--;
			if(k<0)
			break;
			set[k]=0;
			sum=sum-S[k];
		}
		
		k++;
		set[k]=1;
	}

	if(!found)
	printf("There aren't any solutions:\n");

	return 0;
}
