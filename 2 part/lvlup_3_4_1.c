#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SizeAndIndex {
    int size;
    int index;
} SizeAndIndex;

void swap(char **, char **);

int main() {
    char str[256] = {0};
    printf("Введите строку: ");
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
    SizeAndIndex MAX = {0, 0}, MIN = {256, 0};
    printf("Найденные слова:\n");
    //Walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);
        stringArr[wordsFound] = (char *) malloc(sizeof(char) * strlen(token));
        stringArr[wordsFound] = token;

        //Find max and min string length
        if (strlen(token) > MAX.size) {
            MAX.size = (int) strlen(token);
            MAX.index = wordsFound;
        } else if (strlen(token) < MIN.size) {
            MIN.size = (int) strlen(token);
            MIN.index = wordsFound;
        }

        wordsFound++;
        token = strtok(NULL, " ");
    }

    swap(&stringArr[MAX.index], &stringArr[MIN.index]);
    printf("\nМеняем местами MAX(%s) и MIN(%s)...\n", stringArr[MAX.index], stringArr[MIN.index]);
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