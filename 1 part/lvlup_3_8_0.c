#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

const char* strcut(char*, const char*);

int main () {
    char first[128];
    char second[128];
    fgets(first, 128, stdin);
    fgets(second, 128, stdin);
    const char* str = strcut(first, second);
    printf("%s", str);
    return 0;
}

const char* strcut(char* str, const char* find) {
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == find[0]) {
            for (int j = 0; j < strlen(find); ++j, ++i) {
                if ((str[i] == find[j]) || (str[i] == '\0')) {
                    str[i] = (char)127;
                } else {
                    i--;
                    break;
                }
            }
        }
    }
    char* newStr = (char*)malloc(sizeof(char) * 128);
    for (int i = 0, j = 0; i < strlen(str); ++i) {
        if (str[i] == (char)127) {
            continue;
        }
        newStr[j] = str[i];
        ++j;
    }
    return newStr;
}