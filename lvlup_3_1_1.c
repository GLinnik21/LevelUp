#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[256] = {0};
    printf("Введите строку для нахождения количесва слов: ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = 0;

    //Get thr first token
    char *token = strtok(str, " ");

    int wordsFound = 0;
    //Walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);
        wordsFound++;
        token = strtok(NULL, " ");
    }
    printf("Найдено слов: %d", wordsFound);
    return 0;
}
