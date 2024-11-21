#include <stdio.h>
#include <limits.h>

void demSo(int arr[], int n) {
    int dem[30001] = {0};
    int maxDem = 0;
    int i;
    for (i = 0; i < n; i++) {
        dem[arr[i]]++;
        if (dem[arr[i]] > maxDem) {
            maxDem = dem[arr[i]];
        }
    }
    for (i = 0; i < n; i++) {
        if (dem[arr[i]] == maxDem) {
            printf("%d ", arr[i]);
            dem[arr[i]] = 0; 
        }
    }
    printf("\n");
}

int main() {
    int soBoTest, t, n, i;
    scanf("%d", &soBoTest);
    for (t = 0; t < soBoTest; t++) {
        scanf("%d", &n);
        printf("Luu y: Phai liet ke cac phan tu cach nhau bang khoang trang\n");
        int arr[100];
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        demSo(arr, n);
    }
    return 0;
}

