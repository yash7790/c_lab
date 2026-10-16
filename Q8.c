#include <stdio.h>

int multiplyCell(int A[10][10], int B[10][10],
                 int i, int j, int k, int n) {
    if (k == n)
        return 0;

    return A[i][k] * B[k][j] +
           multiplyCell(A, B, i, j, k + 1, n);
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10 ||
        r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10 ||
        c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            C[i][j] = multiplyCell(A, B, i, j, 0, c1);
    }

    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}