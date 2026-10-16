#include <stdio.h>
#include <limits.h>

long long secondLargest(int a[], int n, int i,
                        long long largest, long long second) {
    if (i == n)
        return second;

    if (a[i] > largest) {
        second = largest;
        largest = a[i];
    } else if (a[i] < largest && a[i] > second) {
        second = a[i];
    }

    return secondLargest(a, n, i + 1, largest, second);
}

int main() {
    int a[100], n;
    long long largest = LLONG_MIN;
    long long second;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] > largest)
            largest = a[i];
    }

    second = secondLargest(a, n, 0, LLONG_MIN, LLONG_MIN);

    if (second == LLONG_MIN)
        printf("Fewer than two distinct elements exist.\n");
    else
        printf("Second-largest distinct element = %lld\n", second);

    return 0;
}