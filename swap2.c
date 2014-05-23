#include "stdio.h"

int swap(int *q, int *w)                                                                                                                                                          
{
	int temp;
	
	temp=*q;
	*q=*w;
	*w=temp;

	printf("function %d  %d",*q,*w);

	return 0;
}




