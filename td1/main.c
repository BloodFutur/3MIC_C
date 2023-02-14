#include <stdio.h>

#define SIZE 10

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int * tab, int size) {
    int trie = 0;
    int i = 1;
    while (!trie && i < size) {
        trie = 1;
        for(int j=0; j < size - i; j++) {
            if(tab[j+1] < tab[j]) {
                trie = 0;
                swap(&(tab[j+1]), &(tab[j]));
            }
        }
        ++i;
    }

}

void printTab(int* tab, int size) {
    for(int i=0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int multiplyBy2(int a) {
    return a << 1;
}

int melange(int a, int b) {
    unsigned int c;
    c = 0x0000FFFF & (a >> (sizeof(unsigned int) * 4));
    c = c | ( 0xFFFF0000 & ((~b) << (sizeof(unsigned int) * 4)));
    return c;
}

void test_melange(int a, int b) {
    unsigned int c = melange(a,b);
    printf("\nTest mélange : \n");
    printf("a: 0x%08x \n", a);
    printf("b: 0x%08x \n", b);
    printf("c: 0x%08x \n", c);
}

int is_10th_bit_different(int a, int b) {
    return a == (b ^ (1 << 9));
}

void test_is_10th_bit_different(int a, int b) {
    unsigned int res = is_10th_bit_different(a,b);
    printf("\nTest 10th bit : \n");
    printf("a: 0x%08x \n", a);
    printf("b: 0x%08x \n", b);
    printf("Result : %d\n", res);
}

int bitcount(int n) {
    int size = sizeof(n);
    
}

int main() {
    int tab[SIZE];
    int i;
    for(i=0; i < SIZE; i++) {
        tab[i] = 20 - i;
    }

    printTab(tab, SIZE);
    bubbleSort(tab, SIZE);
    printTab(tab, SIZE);


    int mult2 = 5;
    printf("%d*2=%d \n", mult2, multiplyBy2(mult2));
    
    test_melange(0xFFFFFFFF, 0x00000000);
    test_is_10th_bit_different(0xFFFFFFFF, 0xFFFFFDFF);
    test_is_10th_bit_different(0xFFFFFFFF, 0xFFFFFFFF);
    test_is_10th_bit_different(0xFFF0FFFF, 0xFFFFFFFF);
    test_is_10th_bit_different(0xFFFFFFF0, 0xFFFFFDFF);




    return 0;
}