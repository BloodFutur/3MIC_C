#include "stdio.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Programme pas content; 3 arguments attendus\n");
        return 1;
    }

    printf("prog name: %s\n", argv[0]);
    printf("arg1: %s\n", argv[1]);
    printf("arg2: %s\n", argv[2]);
    printf("arg3: %s\n", argv[3]);

    return 0;
}