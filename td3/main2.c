#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHMAX 40

struct S1 {
    int a;
    char* ch;
};

struct S2 {
    int a;
    char ch[CHMAX];
};

void printS1(struct S1 s, char* name) {
    printf("%s.a = %d\n", name, s.a);
    printf("%s.ch = %s\n", name, s.ch);
}

void printS2(struct S2 s, char* name) {
    printf("%s.a = %d\n", name, s.a);
    printf("%s.ch = %s\n", name, s.ch);
}

int main() {
    struct S1 v11, v12;
    struct S2 v21, v22;

    v11.a   = 3;
    v11.ch  = malloc(sizeof(char) * CHMAX);
    strcpy(v11.ch, "Hulk");
    v21.a   = 5;
    strncpy(v21.ch , "Gruik", CHMAX);

    v12 = v11;
    v22 = v21;
    
    printf("init\n");
    printS1(v11, "v11");
    printS1(v12, "v12");
    printS2(v21, "v21");
    printS2(v22, "v22");


    printf("\nchangements var\n");
    strcpy(v11.ch, "Titi");
    printS1(v11, "v11");
    printS1(v12, "v12");

    strncpy(v21.ch, "Toto", CHMAX);
    printS2(v21, "v21");
    printS2(v22, "v22");
    return 0;
}