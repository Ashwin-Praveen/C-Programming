#include<stdio.h>
#define MAX 200

typedef struct {
	int coef,expo;
} polynomial;

int avail=0,startA,startB,finishA,finishB,finishD,startD;
polynomial term[MAX];

int compare(int expoA,int expoB) {
	if(expoA==expoB)
	   return 0;
	if(expoA>expoB)
	   return 1;
	else
	   return -1;
	}

int attach(int coeff,int expon) {
	term[avail].coef=coeff;
	term[avail++].expo=expon;
	return 1;
	}

int pAdd() {
	int NEWcoeff;
	startD=avail;
	while(startA<=finishA && startB<=finishB)
	{
	   switch(compare(term[startA].expo,term[startB].expo))
	   {
		case 1: attach(term[startA].coef,term[startA].expo);
		        startA++;
			break;
		case -1: attach(term[startB].coef,term[startB].expo);
			 startB++;
			 break;
		case 0: NEWcoeff=term[startA].coef+term[startB].coef;
			attach(NEWcoeff,term[startA].expo);
			startA++;
			startB++;
			break;
	   }

	}
	for(;startA<=finishA;startA++)
	attach(term[startA].coef,term[startA].expo);
	for(;startB<=finishB;startB++)
	attach(term[startB].coef,term[startB].expo);
	finishD=avail-1;
	return 0;
   }

int main() {

	int na,nb,i;
	printf("Enter the numer of terms in the polynomial, then the coefficients and, exponents resp.\n");
	scanf("%d",&na);
	for(i=0;i<na;i++)
	{
	   scanf("%d%d",&term[i].coef,&term[i].expo);
	   avail++;
	}
	finishA=avail-1;
	startB=avail;
	printf("Enter the number of terms in the polynomial, then the coefficients and, the exponents resp.\n");
	scanf("%d",&nb);
	for(i=startB;i<nb+startB;i++)
	{
	   scanf("%d%d",&term[i].coef,&term[i].expo);
	   avail++;
	}
	finishB=avail-1;
	pAdd();
	printf("The sum of the two polynomials are:\n");
	for(i=startD;i<=finishD;i++)
	{
 	   printf("%dx^%d",term[i].coef,term[i].expo);
	   printf("+");
	 }
        printf("0\nEnd");
return 0;

   }	   
