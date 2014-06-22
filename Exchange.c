#include<stdio.h>
#include<stdlib.h>

int Exchange(int *A, int *B)
{
	int temp;
		
	temp=*A;
	*A=*B;
	*B=temp;

	return 0;
}

