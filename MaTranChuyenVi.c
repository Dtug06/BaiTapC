#include <stdio.h>

void nhapMaTran(int a[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void inMaTran(int a[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTich(int a[][100], int b[][100], int c[][100], int n, int m) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[j][k];
            }
        }
    }
}

void chuyenVi(int a[][100], int b[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
}

int main() {
    int t, test, n, m;
    scanf("%d", &t);
    for (test = 1; test <= t; test++) {
        scanf("%d %d", &n, &m);
        int a[100][100], b[100][100], c[100][100];

        nhapMaTran(a, n, m);
        chuyenVi(a, b, n, m);
        tinhTich(a, b, c, n, m);

        printf("Test %d:\n", test);
        inMaTran(c, n, n);
    }

    return 0;
}

