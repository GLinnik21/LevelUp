#include <stdio.h>

typedef struct Number{
    int summ;
    int dif;
    int mult;
    float dev;
    const char* errMsg;
} Number;

Number func(int, int);

int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    Number number = func(a, b);
    printf("%d\n%d\n%d\n%f\n%s", number.summ, number.dif, number.mult, number.dev, number.errMsg);
    return 0;
}

Number func(int a, int b) {
    Number temp;
    temp.summ = a + b;
    temp.dif = a - b;
    temp.mult = a * b;
    if (b == 0) {
        temp.errMsg = "Error. Division by 0!";
        temp.dev = 0;
    } else {
        temp.errMsg = NULL;
        temp.dev = ((float)a) / ((float)b);
    }
    return temp;
}
