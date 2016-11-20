#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findStart(const char*, const char*);
int findMiddle(const char*, const char*);
int findEnd(const char*, const char*);

char **findWords(const char *, const char *);

int main() {

    char baseString[256] = {0};
    printf("Введите строку для поиска слов: ");
    fgets(baseString, 256, stdin);
    baseString[strlen(baseString) - 1] = 0;

    char searchString[256] = {0};
    printf("Введите формат поиска: ");
    fgets(searchString, 256, stdin);
    searchString[strlen(searchString) - 1] = 0;

    char **wordsArray = findWords(baseString, " ");
    char **searchKeys = findWords(searchString, "*");

    int wordCount = 0;
    while (wordsArray[wordCount] != NULL) {
        wordCount++;
    }

    for (int i = 0; i < wordCount; ++i) {
        int j = 0;
        if (strstr(searchString, searchKeys[0]) < strstr(searchString, "*")) {
            if (findStart(wordsArray[i], searchKeys[0])) {
                printf("Подходит! ");
            }
            j++;
        }
        for (; searchKeys[j] != NULL; ++j) {
            if (findMiddle(wordsArray[i], searchKeys[j])) {
                printf("%s Подходит!\n", wordsArray[i]);
            }
        }

    }
    return 0;
}

char **findWords(const char *string, const char *separator) {
    char *baseString = (char *) malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(baseString, string);

    //Replace \t sign with space
    for (int i = 0; i < 256; ++i) {
        if ((baseString[i] == '\t') && (separator[0] == ' '))
            baseString[i] = ' ';
    }

    char **wordsArray = (char **) calloc(256, sizeof(char *));

    //Get thr first token
    char *token = strtok(baseString, separator);

    int wordsFound = 0;
    //Walk through other tokens
    while (token != NULL) {
        wordsArray[wordsFound] = (char *) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(wordsArray[wordsFound], token);
        wordsFound++;
        token = strtok(NULL, separator);
    }

    return wordsArray;
}

int findStart(const char *string, const char *search) {
    if (strlen(search) > strlen(string))
        return 0;

    size_t searchLength = strlen(search);
    char *tmpString = (char *)malloc(sizeof(char) * searchLength);

    //Copy fist n chars from string. n = to number characters in search string
    strncpy(tmpString, string, searchLength);

    //Check if string begins with search
    if (strcmp(tmpString, search) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int findMiddle(const char *string, const char *search) {
    if (strlen(search) > strlen(string))
        return 0;

    size_t searchLength = strlen(search);
    char *tmpString = (char *) malloc(sizeof(char) * searchLength);

    for (int i = 1; i < strlen(string) - strlen(search); ++i) {
        strncpy(tmpString, &string[i], searchLength);
        if (strcmp(tmpString, search) == 0)
            return 1;
    }

    return 0;
}

int findEnd(const char *string, const char *search) {
    if (strlen(search) > strlen(string))
        return 0;

    size_t searchLength = strlen(search);
    char *tmpString = (char *)malloc(sizeof(char) * searchLength);

    //Copy last n chars from string. n = to number characters in search string
    strncpy(tmpString, &string[strlen(string) - searchLength], searchLength);

    //Check if string begins with search
    if (strcmp(tmpString, search) == 0) {
        return 1;
    } else {
        return 0;
    }
}

