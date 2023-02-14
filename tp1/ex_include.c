#include <stdio.h>
#include <stdlib.h>

void Affiche(char* ch) {
    printf("str: %s\n", ch);
}

int Fact(int n) {
    if (n <= 1) {
        return 1;
    }
    return n*Fact(n-1);
}

void Date() {
    system("date");
}