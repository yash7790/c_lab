#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float a, b;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 7) {
        printf("Thank you");
        return 0;
    }

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch(choice) {
        case 1:
            printf("Result = %.2f", a + b);
            break;

        case 2:
            printf("Result = %.2f", a - b);
            break;

        case 3:
            printf("Result = %.2f", a * b);
            break;

        case 4:
            if (b != 0)
                printf("Result = %.2f", a / b);
            else
                printf("Cannot divide by zero");
            break;

        case 5:
            printf("Result = %d", (int)a % (int)b);
            break;

        case 6:
            printf("Result = %.2f", pow(a, b));
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
