#include<stdio.h>
int main (){
int r=0,d,n,m=0;
printf("Enter the number: ");
scanf("%d",&n);
while(n>0)
{
    d=n%10;
    r=r*10+d;
    n=n/10;
}
printf("The reverse of the number is: %d",r);
if(r==m)


    return 0;

}