#include <stdio.h>
#include <memory.h>

int main() {
    char string[256], subString[256];

    fgets(string, 256, stdin);
    fgets(subString, 256, stdin);

    printf("Индексы совпадений: ");

    int foundCount = 0;

    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == subString[0]) {
            for (int j = 0; j < strlen(subString); ++j, ++i) {
                if ((string[i] == subString[j]) || (string[i] == '\0')) {
                    printf("%d,", i);
                } else {
                    printf(" ");
                    foundCount++; i--;
                    break;
                }
            }
        }
    }
    if (!foundCount)
        printf("Подстроки не обнаружены");

    return 0;
}
