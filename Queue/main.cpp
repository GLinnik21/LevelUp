#include <stdio.h>
#include "Queue.h"

int main() {
    Queqe *queqe = init();
    int a = 1;
    while (a) {
        scanf("%d", &a);
        add(&queqe, a);
    }
    printf("Values:\n");
    printQueqe(queqe);

    printf("Taking value from the start: %d\n", take(&queqe));

    printf("Values:\n");
    printQueqe(queqe);

    printf("Watching what's on the top: %d\n", watch(queqe));

    printf("Clearing:\n");
    clearQueqe(&queqe);

    return 0;
}



