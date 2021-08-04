#include <stdio.h>

 int main()
 {
  
 	int sayi,num,sum=0;
	scanf("%d",&sayi);        // The amount of numbers you want to sum
	 
 	for(int counter=1; counter<=sayi; counter++)
 	{
		scanf("%d",&num);   // and enter these numbers
		sum += num;
 	}
 
	 printf("%d",sum);

 return 0;

 }
