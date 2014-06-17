/*
	List of requirements: We need two inputs, namely the array to be converted and the n (n being the number of elements)
			      these elements should be pre entered in the main function and then sent!
	Purpose: To transfer the entered int(s) array into an int variable;
	
*/



#include<stdio.h>
#include<math.h>

long unsigned int ConvertArrayNum( int a[], int n)
{ 
        int m;
        long unsigned int i,sum;

        m=0;
        for(int q=n-1;q!=-1;q--)
        {
                i=(int)a[q];
                sum=sum+i*pow(10,m++);
        }

        i=sum;

//      printf("The entered number is : %lu\n\n",i);
//  	The above line can be used to check if the function is functioning properly

return i;

}
