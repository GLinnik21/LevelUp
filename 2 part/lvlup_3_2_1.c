#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char str[256] = {0};
    printf("Введите строку для нахождения количесва слов: ");
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

    int wordsFound = 0;
    //Walk through other tokens
    while (token != NULL) {
        stringArr[wordsFound] = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(stringArr[wordsFound], token);
        wordsFound++;
        token = strtok(NULL, " ");
    }
    printf("Найдено слов: %d\n", wordsFound);

    printf("Найденные слова:\n");
    for (int i = 0; i < wordsFound; ++i) {
        printf("%s\n", stringArr[i]);
    }
    return 0;
}