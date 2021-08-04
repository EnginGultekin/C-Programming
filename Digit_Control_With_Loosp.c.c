#include <stdio.h>
 

 int main(){

 int sum=0,num,digit,count=1;  
  scanf("%d",&num);             // enter number
 
  while(num>=1){ 

	digit = num%10;     // take last digit and divide number
        num/=10; 
        if(digit != 0){    // if not zero add to sum
	   		
	   sum += count; 	   
	} 
        count *= 2;  
  }
  
  printf("%d\n",sum);

 return 0; 
 
}

  /* Just example   

	0000x = 1
        000x0 = 2
	00x00 = 4
	0x000 = 8
        x0000 = 16 

        000xx = 1+2 = 3
	0xxxx = 1+2+4+8= 15
	xxxxx = 1+2+4+8+16 = 31  şeklinde yazabiliriz */ 
	










 
