#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void findBArray(int A[], int B[], int N) {
    int i;
    B[0] = A[0];
    B[N] = A[N - 1];
    for (i = 1; i < N; i++) {
        B[i] = (A[i - 1] * A[i]) / gcd(A[i - 1], A[i]);
    }
}

int main() {
    int T, t, N, i;
    printf("nhap so bo test: ");
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        printf("nhap so phan tu cua day: ");
        scanf("%d", &N);
        printf("nhap cac phan tu cach nhau bang khoang trang\n");
        int A[N], B[N + 1];
        for (i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        findBArray(A, B, N);
        for (i = 0; i <= N; i++) {
            printf("%d ", B[i]);
        }
        printf("\n");
    }
    return 0;
}

