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

    char **stringArr = (char **) malloc(sizeof(void *) * 256);

    //Get thr first token
    char *token = strtok(str, " ");

    int wordsFound = 0;
    //Walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);
        stringArr[wordsFound] = token;
        wordsFound++;
        token = strtok(NULL, " ");
    }
    printf("Найдено слов: %d", wordsFound);
    return 0;
}