#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTen(char *ten) {
    int len = strlen(ten);
    char temp[len];
    int j = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (i == 0 || (i > 0 && ten[i - 1] == ' ')) {
            temp[j++] = toupper(ten[i]);
        } else {
            temp[j++] = tolower(ten[i]);
        }
    }
    temp[j] = '\0';

    char result[len];
    j = 0;
    int space = 0;
    for (i = 0; i < len; i++) {
        if (temp[i] != ' ') {
            result[j++] = temp[i];
            space = 0;
        } else if (!space) {
            result[j++] = ' ';
            space = 1;
        }
    }
    result[j] = '\0';

    if (result[0] == ' ') {
        memmove(result, result + 1, strlen(result));
    }
    if (result[strlen(result) - 1] == ' ') {
        result[strlen(result) - 1] = '\0';
    }

    strcpy(ten, result);
}

int main() {
    int soBoTest;
    scanf("%d\n", &soBoTest);
    int k;
    for (k = 0; k < soBoTest; k++) {
        char xau[81];
        fgets(xau, sizeof(xau), stdin);
        if (xau[strlen(xau) - 1] == '\n') {
            xau[strlen(xau) - 1] = '\0';
        }
        chuanHoaTen(xau);
        printf("%s\n", xau);
    }
    return 0;
}

