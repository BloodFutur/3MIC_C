#include <stdlib.h>
#define TAILLE 10

/*
 * Rempli chaine avec A,B,C,D,E,F,G,H,I,0x00
 *        tab avec 1,2,3,4,5,6,7,8,9
 */
int main(void)  {
    char* chaine = malloc(TAILLE * sizeof(char));
    int* tab = malloc(TAILLE * sizeof(int));
    int i;

    for(i=0;i<TAILLE-1;i++) {
        tab[i]=i+1;
        chaine[i]=(char)(i+65);
    }

    chaine[TAILLE-1]=0;

    for(i=0;i<TAILLE; i++) {
        printf("%d\t%c\n", tab[i], chaine[i]);
    }
    free(chaine);
    free(tab);
    return 0;
}