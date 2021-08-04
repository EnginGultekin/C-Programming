#include <stdio.h>
 

 int main(){

 int sum,num,e,a,b,c,d;    // For kullanmadan almış olduğumuz sayının hanalerinin 0 olup olmadığı
  scanf("%d",&num);       // kontrolünü yapıyoruz
 
  d = num%10;    // Birler basamağı kontrolü eğer 0 değilse 1 
   num/=10;

  c = num%10;   // onlar basamağı kontrolu eğer 0 değilse 2
   num/=10;

  b = num%10;   // yüzler basamağı kontrolü  eğer 0 değilse 4
   num/=10;

  a = num%10;  // ... 
   num/=10;

  e = num%10;
   num/=10;  

 
  if(d==0)
    d=0;

 else
    d=1*1; 

  if(c==0)
    c=0;

 else
    c=2*1;

  if(b==0)
    b=0;

 else 
    b=2*2;
 
  if(a==0)
    a=0;

 else
    a=2*2*2;

  if(e==0
    e=0;                
                  
 else           
   e=2*2*2*2;

   sum = e+a+b+c+d; // en sonunda değiştirmiş olduğumuz basamakları tek tek toplarız ve kontro sağlanır 
   printf("%d",sum);
 
}

  /*    0000x = 1
        000x0 = 2
	00x00 = 4
	0x000 = 8
        x0000 = 16 

        000xx = 1+2 = 3
	0xxxx = 1+2+4+8= 15
	xxxxx = 1+2+4+8+16 = 31  şeklinde yazabiliriz */ 
	










 
