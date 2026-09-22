#include<stdio.h>
int main() {

int binary = 0, place = 1, remainder;
int n;
printf("enter a number :");
scanf("%d", &n);

while(n > 0) {
remainder = n % 2;
binary = binary + remainder * place;
place = place * 10;
n = n/2;
}

printf("binnary for = %d", binary);

    return 0;
}