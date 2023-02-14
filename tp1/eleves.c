#include <stdio.h>
#include <string.h>
#include "eleves.h"

void init_eleve(struct eleve* el, char* nom, int promo) {
    strcpy(el->nom,nom);
    el->promo = promo;
}

void affiche_eleve(struct eleve* el) {
    printf("Eleve:\tnom\tpromo\n\t%s \t%d\n", el->nom, el->promo);
}