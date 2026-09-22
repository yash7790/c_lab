#include<stdio.h>
int main () {

int i,n,sum=0;
printf("enter the number:");
scanf("%d",&n);
for(i=1;i<=n/2;i++)
{
if(n%i==0)
{
    sum=sum+i;
}
}

if(sum==n)
{printf("%d is a perfect number",n);
    }
else
{
    printf("%d is the number is not a perfect number",n);

}
return 0;
}

    
