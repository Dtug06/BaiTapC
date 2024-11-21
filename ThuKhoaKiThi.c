#include <stdio.h>
#include <string.h>

struct ThiSinh {
    int ma;
    char ten[100];
    char ngaySinh[15];
    float diem1, diem2, diem3, tongDiem;
};

void swap(struct ThiSinh *a, struct ThiSinh *b) {
    struct ThiSinh temp = *a;
    *a = *b;
    *b = temp;
}

void sapXep(struct ThiSinh ds[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ds[i].tongDiem < ds[j].tongDiem || 
                (ds[i].tongDiem == ds[j].tongDiem && ds[i].ma > ds[j].ma)) {
                swap(&ds[i], &ds[j]);
            }
        }
    }
}

int main() {
    int soThiSinh;
    scanf("%d", &soThiSinh);
    struct ThiSinh dsThiSinh[soThiSinh];
    int i;
    for (i = 0; i < soThiSinh; i++) {
        dsThiSinh[i].ma = i + 1;
        scanf(" %[^\n]", dsThiSinh[i].ten);
        scanf(" %[^\n]", dsThiSinh[i].ngaySinh);
        scanf("%f %f %f", &dsThiSinh[i].diem1, &dsThiSinh[i].diem2, &dsThiSinh[i].diem3);
        dsThiSinh[i].tongDiem = dsThiSinh[i].diem1 + dsThiSinh[i].diem2 + dsThiSinh[i].diem3;
    }

    sapXep(dsThiSinh, soThiSinh);

    float maxDiem = dsThiSinh[0].tongDiem;
    for (i = 0; i < soThiSinh; i++) {
        if (dsThiSinh[i].tongDiem == maxDiem) {
            printf("%d %s %s %.1f\n", dsThiSinh[i].ma, dsThiSinh[i].ten, dsThiSinh[i].ngaySinh, dsThiSinh[i].tongDiem);
        } else {
            break;
        }
    }

    return 0;
}

