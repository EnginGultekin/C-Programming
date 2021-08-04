#include <stdio.h>
 
 float P(float,float);
 int main(){
 
 int num1;
 float num2; 
  scanf("%d %f",&num1,&num2);     // Enter one float and one integer value
  
  printf("%f\n",P(num1,num2));    // Send values 
}

 float P(float n,float x){

 if(n==0)
   return 1;

 if(n==1)
   return x;
  
   return (((float)(2*n-1)/n)*x*P(n-1,x)) - (((float)(n-1)/n)*P(n-2,x)); // Formul  for sequence
}


  /* Sequence  for a(integer) and b(may be float)

   (((2*a-1)/a)*b*P(a-1,b)) - (((a-1)/a)*P(a-2,b))

  */
