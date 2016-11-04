#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

void swap(char*, char*);

int main() {
    char string[256];
    fgets(string, 256, stdin);
    int n = strlen(string);
    bool swapped = false;

    do {
        swapped = false;
        for (int i = 1; i <= n - 1; ++i) {
            if ((int)string[i - 1] > (int)string[i]) {
                swap(&string[i - 1], &string[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    printf("%s", string);

    return 0;
}

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

