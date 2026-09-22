#include<stdio.h>
int main (){
int a=0,b=1,c,i,n=6;
for (i=1;i<=n;i++)
{
printf("%d\n",a);
c=a+b;
a=b;
b=c;    
}

return 0;


}