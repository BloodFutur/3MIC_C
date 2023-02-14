#include "eleves.h"
#include "constantes.h"

int main() {
    struct eleve el;
    init_eleve(&el, "pierr", 98);
    affiche_eleve(&el);
    return 0;
}