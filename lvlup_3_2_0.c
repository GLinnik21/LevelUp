#include <stdio.h>

typedef struct {
    int summ;
    int dif;
    int mult;
    float dev;
    const char* errMsg;
} Number;

Number func(int, int);

int main () {
    printf("%f", func(10, 6).dev);
    return 0;
}

Number func(int a, int b) {
    Number temp;
    temp.summ = a + b;
    temp.dif = a - b;
    temp.mult = a * b;
    if (b == 0) {
        temp.errMsg = "Error. Devision by 0!";
    } else {
        temp.errMsg = NULL;
        temp.dev = ((float)a) / ((float)b);
    }
    return temp;
}
