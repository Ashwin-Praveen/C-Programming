#include<stdio.h>

int Exchange(int *A, int *B);

int main()
{

	int a,b;

	printf("Enter two numbers to be swapped respectivety:\n");
	printf("A:");
	scanf("%d",&a);
	printf("B:");
	scanf("%d",&b);

	Exchange(&a,&b);
	
	printf("\n\n\nA:%d\nB:%d\n\n",a,b);

	return 0;

}

int Exchange(int *A, int *B)
{
	int temp;
		
	temp=*A;
	*A=*B;
	*B=temp;

	return 0;
}

