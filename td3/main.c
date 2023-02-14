#include <stdlib.h>
#include <stdio.h>

#define MAXNOM 20
#define MAXNOTES 20

struct Student {
    char name[MAXNOM];
    int year;
    int nbNotes;
    int notes[MAXNOTES];
};  


void SaisirFiche(struct Student* s) {
    printf("Saisir le nom: ");
    scanf("%s", s->name);
    printf("Saisir l'annee de naissance: ");
    scanf("%d", &s->year);
    printf("Saisir le nombre de notes: ");
    scanf("%d", &s->nbNotes);


    for(int i=0;i < s->nbNotes; i++) {
        printf("Saisir la note%d: ", i);
        scanf("%d", &s->notes[i]);
    }
}

void AfficherFiche(const struct Student* student) {
    printf("\nFiche :");
    printf("\nNom: %s", student->name);
    printf("\nAnnee de naissance: %d", student->year);
    printf("\nNotes: ");
    for(int i = 0; i < student->nbNotes; i++) {
        printf("%d ", student->notes[i]);
    }
    printf("\n");
}

double Moyenne(const struct Student* fiche) {
    if(fiche->nbNotes == 0) {
        printf("pas de notes, pas de moyenne");
        return 0.0;
    }
    double sum = 0.0;
    for(int i = 0; i < fiche->nbNotes; i++) {
        sum += fiche->notes[i];
    }
    return sum/fiche->nbNotes;
    
}

int main(int argc, char* argv[]) {

    struct Student s;
    SaisirFiche(&s);
    AfficherFiche(&s);
    printf("Moyenne étudiant: %f\n", Moyenne(&s));
    return 0;
}