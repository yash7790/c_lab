#include <stdio.h>

int findMax(int a[], int n) {
    if (n == 1)
        return a[0];

    int max = findMax(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];

    return max;
}

int countOccurrences(int a[], int n, int max) {
    if (n == 0)
        return 0;

    return (a[n - 1] == max) +
           countOccurrences(a, n - 1, max);
}

int main() {
    int a[100], n, max, count;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = findMax(a, n);
    count = countOccurrences(a, n, max);

    printf("Maximum element = %d\n", max);
    printf("Number of occurrences = %d\n", count);

    return 0;
}