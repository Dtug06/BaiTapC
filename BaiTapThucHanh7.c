#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int count;
} WordInfo;

int isWordCharacter(char c) {
    return isalpha(c) || isdigit(c);
}

void toLowerStr(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int findWord(WordInfo words[], int wordCount, char *word) {
    int i;
    for (i = 0; i < wordCount; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    WordInfo words[MAX_WORDS];
    int wordCount = 0, maxLength = 0, i;

    while (scanf("%s", input) != EOF) {
        char currentWord[MAX_WORD_LENGTH] = "";
        int currentLength = 0;
        i = 0;

        while (input[i]) {
            if (isWordCharacter(input[i])) {
                currentWord[currentLength++] = input[i];
            }
            i++;
        }
        currentWord[currentLength] = '\0';

        if (currentLength > 0) {
            toLowerStr(currentWord);
            int index = findWord(words, wordCount, currentWord);
            if (index == -1) {
                strcpy(words[wordCount].word, currentWord);
                words[wordCount].length = currentLength;
                words[wordCount].count = 1;
                wordCount++;
            } else {
                words[index].count++;
            }
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }

    for (i = 0; i < wordCount; i++) {
        if (words[i].length == maxLength) {
            printf("%s %d %d\n", words[i].word, words[i].length, words[i].count);
        }
    }

    return 0;
}


