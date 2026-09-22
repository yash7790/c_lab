#include<stdio.h>
int main(){
int n,i,isprime=1,l,u,c=0;
printf("enter your upper limit:");
scanf("%d",&u);

printf("enter your lower limit:");
scanf("%d",&l);

for(n=l;n<=u;n++)
 {
   if(n<2)
   {
    continue;
   }
   else
   {
     isprime=1; 
     for (i=2;i<=n/2;i++)
    {
          if(n%i==0) 
           {
            isprime=0;
            break;
           }
    }
         if(isprime==1)
         {
           printf("the number %d is a prime number\n",n);
            c=c++;
         }
        else
       {
         printf("the number %d is not a prime number\n",n);
        }
       printf("%d",c);  
    }
    
    }
 return 0;
 }
