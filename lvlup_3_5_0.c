#include <stdio.h>
#include <memory.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    char string[256] = {0}, subString[256] = {0};

    fgets(string, 256, stdin);
    fgets(subString, 256, stdin);
    string[(int)strlen(string) - 1] = 0;
    subString[(int)strlen(subString) - 1] = 0;

    printf("Индексы совпадений: ");

    int foundCount = 0;

    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == subString[0]) {
            for (int j = 0; j < strlen(subString) + 1; ++j, ++i) {
                if ((string[i] == subString[j]) && (string[i] != '\0')) {
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
