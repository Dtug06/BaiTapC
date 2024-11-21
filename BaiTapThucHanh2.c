#include <stdio.h>

void sapXepTangDan(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    printf("nhap cac phan tu cach nhau bang khoang trang\n");
    int arr[n], chan[n], le[n];
    int soChan = 0, soLe = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            chan[soChan++] = arr[i];
        } else {
            le[soLe++] = arr[i];
        }
    }

    sapXepTangDan(chan, soChan);
    sapXepTangDan(le, soLe);

    for (i = 0; i < soChan; i++) {
        printf("%d ", chan[i]);
    }
    for (i = 0; i < soLe; i++) {
        printf("%d ", le[i]);
    }
    printf("\n");

    return 0;
}

