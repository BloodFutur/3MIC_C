#include "stdio.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a, b;
    a = 314;
    b = 1592;
    printf("a:%d\t| b:%d\n", a, b);
    swap(&a,&b);
    printf("swap(a,b)\na:%d\t| b:%d\n", a, b);

    return 0;
}