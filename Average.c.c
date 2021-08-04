#include  <stdio.h>

  int main()
 {
  
 	int num,sum=0;
	float average=0;
	scanf("%d",&num);

	for(int counter=1; num != 9999; counter++)   // if enter "9999" the loop end
	{

                sum+=num;
		average=(float)(sum)/(counter);

 		scanf("%d",&num);  // enter numbers
		
	}

 	printf("%f\n",average);

 return 0;
 }
