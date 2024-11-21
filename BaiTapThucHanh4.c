#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char number[10];
    int count;
} NumberCount;

int isNonDecreasing(char* str) {
    int i;
    for (i = 1; i < strlen(str); i++) {
        if (str[i] < str[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int compare(const void* a, const void* b) {
    NumberCount* numA = (NumberCount*)a;
    NumberCount* numB = (NumberCount*)b;
    if (numA->count != numB->count) {
        return numB->count - numA->count;
    }
    return strcmp(numA->number, numB->number);
}

int main() {
    char input[1000000];
    NumberCount numbers[100000];
    int count = 0;
    int numCount = 0;
    int i;

    while (scanf("%s", input) != EOF) {
        if (isNonDecreasing(input)) {
            int found = 0;
            for (i = 0; i < numCount; i++) {
                if (strcmp(numbers[i].number, input) == 0) {
                    numbers[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(numbers[numCount].number, input);
                numbers[numCount].count = 1;
                numCount++;
            }
        }
    }

    qsort(numbers, numCount, sizeof(NumberCount), compare);

    for (i = 0; i < numCount; i++) {
        printf("%s %d\n", numbers[i].number, numbers[i].count);
    }

    return 0;
}

