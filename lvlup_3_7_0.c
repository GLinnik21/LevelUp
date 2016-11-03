#include <stdio.h>
#include <memory.h>



int main() {
    char stringSrs[256];
    char stringDest[512];

    fgets(stringDest, 256, stdin);
    fgets(stringSrs, 256, stdin);

    stringDest[strlen(stringDest) - 1] = 0;

    strcat (stringDest, stringSrs);

    printf("%s\n", stringDest);

    return 0;
}

