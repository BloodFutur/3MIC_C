#include <stdlib.h>
#include <stdio.h>

int EcritFichier(FILE* fich_lect, char* nom_fich_ecrit, int nb_lignes) {
    FILE * fich_ecrit;
    fich_ecrit = fopen(nom_fich_ecrit, "w");
    const int max = 500;
    char ligne[max] ;
    
    int l = 0;
    char* res_fgets = ligne;
    while(l < nb_lignes && res_fgets != NULL) {
        res_fgets = fgets(ligne, max, fich_lect);
        if(res_fgets != NULL) {
            fputs(ligne, fich_ecrit);
        }

        l++;
    }

    fclose(fich_ecrit);

    if(res_fgets == NULL) {
        fprintf(stderr, "Erreur de la lecture\n");
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    FILE* fich_lect;

/*     printf("\nInserer le nom du fichier de lecture: ");
    char* nom_lect = malloc(sizeof(char) * 100);
    scanf("%s", nom_lect);
    fich_lect = fopen(nom_lect, "r");
    if(fich_lect == NULL) {
        fprintf(stderr, "Fichier nom introuvable\n");
        return 1;
    }


    printf("\nInserer le nom du fichier d'ecriture: ");
    char* nom_ecrit = malloc(sizeof(char) * 100);
    scanf("%s", nom_ecrit); */

    if(argc != 4) {
        fprintf(stderr, "Il faut 3 parametres\n");
        return 1;
    }

    char* nom_lect  = argv[1];
    char* nom_ecrit = argv[2];
    int nb_lignes   = atoi(argv[3]);

    fich_lect = fopen(nom_lect, "r");
    if(fich_lect == NULL) {
        fprintf(stderr, "Fichier nom introuvable\n");
        return 1;
    }

    int res = EcritFichier(fich_lect, nom_ecrit, nb_lignes);
    fclose(fich_lect);

    return res;
}