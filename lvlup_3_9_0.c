#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 10

void swap(char **, char **);

int main() {
    setlocale(LC_ALL, "Russian");
    char *strings[ARRAY_SIZE];

    printf("Введите строки для сортировки: \n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        strings[i] = (char *) calloc(256, sizeof(char));
        printf("(%d): ", i + 1);
        fgets(strings[i], 256, stdin);
        strings[i][strlen(strings[i]) - 1] = 0;
    }

    bool swapped = false;

    int n = ARRAY_SIZE;
    do {
        swapped = false;
        for (int i = 1; i <= n - 1; ++i) {
            if (strcmp(strings[i - 1], strings[i]) > 0) {
                swap(&strings[i - 1], &strings[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%s\n", strings[i]);
    }


    return 0;
}

void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

