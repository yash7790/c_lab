#include <stdio.h>

int columnSum(int a[10][10], int rows, int col, int row) {
    if (row == rows)
        return 0;

    return a[row][col] + columnSum(a, rows, col, row + 1);
}

int findMinColumn(int a[10][10], int rows, int cols,
                  int col, int minCol, int minSum) {
    if (col == cols)
        return minCol;

    int sum = columnSum(a, rows, col, 0);

    if (col == 0 || sum < minSum) {
        minSum = sum;
        minCol = col;
    }

    return findMinColumn(a, rows, cols,
                         col + 1, minCol, minSum);
}

int main() {
    int a[10][10], rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    int minCol = findMinColumn(a, rows, cols, 0, 0, 0);

    printf("Column with minimum sum = %d\n", minCol + 1);
    printf("Minimum sum = %d\n",
           columnSum(a, rows, minCol, 0));

    return 0;
}