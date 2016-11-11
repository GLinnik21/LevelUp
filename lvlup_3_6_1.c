#include <stdio.h>
#include <string.h>

void swap(char *, char *);

int main() {
    char str[256] = {0};
    printf("Введите строку для реверса: ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = 0;

    for (int i = 0, j = strlen(str) - 1; i < strlen(str) / 2; ++i, --j) {
        swap(&str[i], &str[j]);
    }

    printf("Реверснутая строка: %s", str);

    return 0;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}