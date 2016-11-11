#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findStart(const char*, const char*);
int findMiddle(const char*, const char*);
int findEnd(const char*, const char*);

int main() {
    /*char baseString[256] = {0};
    printf("Введите строку для форматированного поиска слов: ");
    fgets(baseString, 256, stdin);
    baseString[strlen(baseString) - 1] = 0;

    //Replace \t sign with space
    for (int i = 0; i < 256; ++i) {
        if (baseString[i] == '\t')
            baseString[i] = ' ';
    }

    char *wordsArray[256];

    //Get thr first token
    char *token = strtok(baseString, " ");

    int wordsFound = 0;
    //Walk through other tokens
    while (token != NULL) {
        wordsArray[wordsFound] = (char *) malloc(sizeof(char) * strlen(token));
        wordsArray[wordsFound] = token;
        wordsFound++;
        token = strtok(NULL, " ");
    }*/

    findStart("qwerty", "qwe");

    return 0;
}

int findStart(const char *string, const char *search) {
    if (strlen(search) > strlen(string))
        return 0;

    size_t searchLength = strlen(search);
    char *tmpString = (char *)malloc(sizeof(char) * searchLength);

    //Copy fist n chars from string. n = to number characters in search string
    strncpy(tmpString, string, searchLength);

    //Check if string begins with search
    if (strcmp(tmpString, string) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int findMiddle(const char *string, const char *search) {
    if (strlen(search) > strlen(string))
        return 0;
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
    if (strcmp(tmpString, string) == 0) {
        return 1;
    } else {
        return 0;
    }
}
