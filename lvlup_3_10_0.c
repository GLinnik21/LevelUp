#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main() {
    char string[256];
    fgets(string, 256, stdin);

    //Find tabs
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == '\t')
            string[i] = (char)127;
    }
    //Find spaces
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ' && string[i + 1] == ' ')
            string[i] = (char)127;
    }
    char* newString = (char*)malloc(sizeof(char) * strlen(string));

    for (int i = 0, j = 0; i < strlen(string); ++i) {
        if (string[i] == (char)127) {
            continue;
        }
        newString[j] = string[i];
        ++j;
    }

    printf("%s", newString);
    return 0;
}
