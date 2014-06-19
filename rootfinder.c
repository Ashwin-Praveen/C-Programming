#include<stdio.h>
#include<math.h>

//I used math.h for the degree of the root and not for the cube root itself

int main()
{

	float  b,q;
  	int n,number,po,set=1;

	printf("\nEnter the degree of the root you'd like to find\n\n(Example square root would be 2, and cube root 3):\n");
	scanf("%d",&po);

	printf("\nEnter the number whose root is to be found:\n");
	scanf("%d",&number);

	if(po>3)
	set=0;

	if(number<30001)
	for(b=set;b<32;b=b+0.000001)
	{

		//if you don't want me to use math.h ! you can use the next line instead, just un-comment it! and comment the q=pow(b,po);      

		// q=b*b*b;
        	q=pow(b,po);
                n=q;

              	if(number==n)
                {
                	printf("\nThe Answer:%f\n \n",b);
                	b=50;
                }

           }
	else
        printf("\nPlease enter a number under 30001,\nWhy do you need the cube root for such a huge number anyway?\n \n");

	return 0;
   

}


