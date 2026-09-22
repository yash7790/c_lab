#include <stdio.h>

int main() {
    int choice, n, original, rem, reverse, sum, count;
    int i, isPrime, digits, armstrongSum;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Check Palindrome\n");
        printf("2. Check Armstrong Number\n");
        printf("3. Check Prime Number\n");
        printf("4. Find Sum of Digits\n");
        printf("5. Count the number of Digits\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);

                original = n;
                reverse = 0;

                while (n > 0) {
                    rem = n % 10;
                    reverse = reverse * 10 + rem;
                    n = n / 10;
                }

                if (original == reverse)
                    printf("Palindrome Number\n");
                else
                    printf("Not a Palindrome Number\n");

                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);

                original = n;
                armstrongSum = 0;
                digits = 0;

                while (n > 0) {
                    digits++;
                    n = n / 10;
                }

                n = original;

                while (n > 0) {
                    rem = n % 10;

                    int power = 1;
                    for (i = 1; i <= digits; i++) {
                        power = power * rem;
                    }

                    armstrongSum = armstrongSum + power;
                    n = n / 10;
                }

                if (armstrongSum == original)
                    printf("Armstrong Number\n");
                else
                    printf("Not an Armstrong Number\n");

                break;

            case 3:
                printf("Enter a number: ");
                scanf("%d", &n);

                if (n < 2) {
                    printf("Not a Prime Number\n");
                    break;
                }

                isPrime = 1;

                for (i = 2; i <= n / 2; i++) {
                    if (n % i == 0) {
                        isPrime = 0;
                        break;
                    }
                }

                if (isPrime)
                    printf("Prime Number\n");
                else
                    printf("Not a Prime Number\n");

                break;

            case 4:
                printf("Enter a number: ");
                scanf("%d", &n);

                sum = 0;

                while (n > 0) {
                    rem = n % 10;
                    sum = sum + rem;
                    n = n / 10;
                }

                printf("Sum of digits = %d\n", sum);

                break;

            case 5:
                printf("Enter a number: ");
                scanf("%d", &n);

                count = 0;

                if (n == 0)
                    count = 1;
                else {
                    while (n != 0) {
                        n = n / 10;
                        count++;
                    }
                }

                printf("Number of digits = %d\n", count);

                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}