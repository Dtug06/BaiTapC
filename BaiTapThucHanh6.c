#include <stdio.h>

void nhapMaTran(int matrix[][50], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void inMaTran(int matrix[][50], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void chuyenDoiHang(int matrix[][50], int n, int a, int b) {
    int temp, j;
    for (j = 0; j < n; j++) {
        temp = matrix[a][j];
        matrix[a][j] = matrix[b][j];
        matrix[b][j] = temp;
    }
}

int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    int matrix[50][50];
    nhapMaTran(matrix, m, n);
    scanf("%d %d", &a, &b);
    a--; 
    b--; 
    chuyenDoiHang(matrix, n, a, b);
    inMaTran(matrix, m, n);
    return 0;
}

