#include <stdio.h>
#include<stdlib.h>
 
int main() 
{
	char cho;
	
	printf("Do you want to turn off the system?\nPress Y for yes and N for no: ");
	scanf("%c",&cho);

	if(cho == 'Y' || cho == 'y')	
	system("sudo shutdown -P now");
	return 0;

} 
