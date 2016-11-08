#include <stdio.h>
#include <memory.h>

int main() {
    char stringSrs[256] = {0};
    char stringTrgt[256] = {0};
    fgets(stringSrs, 256, stdin);

    for (int i = 0, j = strlen(stringSrs) - 2; i < strlen(stringSrs) - 1; ++i, --j) {
        stringTrgt[i] = stringSrs[j];
    }

    printf("%s\n", stringTrgt);

    return 0;
}