#include <stdio.h>

static int var1=0;
int var2=3;
int var3=6;

void f(int var2) {
    static int i=0;
    int j=9;
    int var1;

    i++;
    j--;
    var1=5;
    var2=6;
    var3=8;
    printf("\nvar1:%d \nvar2:%d \nvar3:%d \ni:%d \nj:%d\n", var1, var2, var3, i, j);
}

/*
    var1 = 0
    var2 global = 3
    var3 = 6
    i    = 3
    j    = 8
*/
int main(void) {
    int var2;

    var2=5;
    f(var2);
    f(var1);
    f(var3);
    printf("\nvar1:%d \nvar2:%d \nvar3:%d \n", var1, var2, var3);

    return 0;
}