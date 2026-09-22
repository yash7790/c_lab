#include <stdio.h>

int main() 
{
    int i,j,m;
    int n = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &m);

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= i; j++) 
        {
            printf("%d ", n);
            n++;
        }
        printf("\n");
    }

    return 0;
}