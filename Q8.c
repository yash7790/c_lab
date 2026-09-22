#include <stdio.h>

int main() {
    int n, i, j;
    float x, sum = 0.0, power, factorial, term;

    printf("Enter value of x: ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        // Calculate x^i
        power = 1;
        for (j = 1; j <= i; j++) {
            power = power * x;
        }

        // Calculate i!
        factorial = 1;
        for (j = 1; j <= i; j++) {
            factorial = factorial * j;
        }

        // Calculate the term
        term = power / factorial;

        // Alternate + and -
        if (i % 2 == 1) {
            sum = sum + term;
        } else {
            sum = sum - term;
        }
    }

    printf("Sum of series = %.4f\n", sum);

    return 0;
}