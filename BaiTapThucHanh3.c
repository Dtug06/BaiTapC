#include <stdio.h>

void inMang(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepDoiChoTrucTiep(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("Buoc %d: ", i + 1);
        inMang(arr, n);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[100];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sapXepDoiChoTrucTiep(arr, n);
    return 0;
}

