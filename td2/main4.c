#include <stdio.h>

int Pipo(int i, int* j, int k) {
    *j = 4;
    i = 5;
    k += 10;
    return k;
}

// Print 4,4,12
int main(void) {
    int* a;
    int b=3;
    int c;

    a = &b;
    b = 2;

    c = Pipo(b, a, *a);
    printf("*a:%d\nb:%d\nc:%d\n", *a,b,c);
    return 0;
}