#include <stdio.h>

int isSymmetric(int a[10][10], int n, int i, int j) {
    if (i == n)
        return 1;

    if (j == n)
        return isSymmetric(a, n, i + 1, 0);

    if (a[i][j] != a[j][i])
        return 0;

    return isSymmetric(a, n, i, j + 1);
}

int main() {
    int a[10][10], n;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    if (isSymmetric(a, n, 0, 0))
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}