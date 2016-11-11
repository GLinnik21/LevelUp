#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    char str[256] = {0};
    printf("Введите строку для удаления повторяющихся слов: ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = 0;

    //Replace \t sign with space
    for (int i = 0; i < 256; ++i) {
        if (str[i] == '\t')
            str[i] = ' ';
    }

    char *stringArr[256];

    //Get thr first token
    char *token = strtok(str, " ");

    int wordsFound = 0, symbolCount = 0;
    //Walk through other tokens
    while (token != NULL) {
        bool add = true;
        for (int i = 0; i < wordsFound; ++i) {
            if (strcmp(stringArr[i], token) == 0) {
                add = false;
                break;
            }
        }
        if (add) {
            stringArr[wordsFound] = (char *) malloc(sizeof(char) * strlen(token));
            stringArr[wordsFound] = token;
            wordsFound++;
            symbolCount += strlen(token) + 1;//+1 to allocate memory for ' ' sign
        }
        token = strtok(NULL, " ");
    }
    printf("Найдено слов: %d\n", wordsFound);

    char *newStr = (char *) malloc(sizeof(char) * symbolCount);

    for (int i = 0, k = 0; i < wordsFound; ++i) {
        for (int j = 0; j < strlen(stringArr[i]); ++j, ++k) {
            newStr[k] = stringArr[i][j];
        }
        newStr[k++] = ' ';
    }
    newStr[symbolCount - 1] = '\0';
    printf("%s", newStr);

    return 0;
}