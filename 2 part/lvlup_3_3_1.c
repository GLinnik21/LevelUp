#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(char **, char **);

int main() {
    char str[256] = {0};
    printf("Введите строку для сортировки слов в алфавитном порядке: ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = 0;

    //Replace \t sign with space
    for (int i = 0; i < 256; ++i) {
        if (str[i] == '\t')
            str[i] = ' ';
    }

    char *stringArr[256] = {0};

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

    bool swapped = false;

    int n = wordsFound;
    do {
        swapped = false;
        for (int i = 1; i <= n - 1; ++i) {
            if (strcmp(stringArr[i - 1], stringArr[i]) > 0) {
                swap(&stringArr[i - 1], &stringArr[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    for (int i = 0; i < wordsFound; ++i) {
        printf("%s\n", stringArr[i]);
    }

    return 0;
}

void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
