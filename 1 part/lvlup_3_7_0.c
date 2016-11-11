#include <stdio.h>
#include <memory.h>



int main() {
    char stringSrs[256] = {0};
    char stringDest[512] = {0};

    fgets(stringDest, 256, stdin);
    fgets(stringSrs, 256, stdin);

    stringDest[strlen(stringDest) - 1] = 0;
    stringDest[strlen(stringSrs) - 1] = 0;

    strcat (stringDest, stringSrs);

    printf("%s\n", stringDest);

    return 0;
}

