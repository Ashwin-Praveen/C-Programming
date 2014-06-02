#include<stdio.h>

int main()
{
	float number,i=0,ans=1;

	printf("Enter the number whose cube root is to be found:\n");
	scanf("%f",&number);

	for(i=0;i<=15;i++)
	ans=(((ans*ans*ans)*2+number)/(3*ans*ans));

	printf("The answer:%f\n",ans);

	return 0;
}
