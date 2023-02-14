#include <stdlib.h>
#include <stdio.h>

struct Cell;
struct Cell {
    int val;
    struct Cell* next;
};

struct File {
    struct Cell* first;
    struct Cell* last;
    int nbElements;
};

void CreerFileVide(struct File* f) {
    f->first = NULL;
    f->last = NULL;
    f->nbElements = 0;
}

void AjouterFile(struct File* f, int element) {
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->val = element;
    cell->next = NULL;

    if(f->nbElements == 0) {
        f->first = cell;
        f->last = cell; 
    } else if(f->nbElements == 1) {
        f->first->next = cell;
        f->last->next = cell;
        f->last = cell;
    } else {
        f->last->next = cell;
        f->last = cell;
    }

    f->nbElements += 1;
}

void EnleverFile(struct File* f) {
    if(f->nbElements == 0) {
        printf("La file est deja vide");
    } else if(f->nbElements == 1) {
        struct Cell* cell = f->first;
        free(cell);
        f->first = NULL;
        f->last = NULL;
        f->nbElements -= 1;
    } else {
        struct Cell* cell = f->first;
        f->first = cell->next;
        free(cell); 
        f->nbElements -= 1;
    }

}

void AfficherDebut(struct File* f) {
    if(f->first == NULL) {
        printf("\nFile vide");
    } else {
        printf("\nDebut: %d", f->first->val);
    }
}

void AfficherFin(struct File* f) {
    if(f->last == NULL) {
        printf("\nFile vide");
    } else {
        printf("\nFin: %d", f->last->val);
    }
}

void AfficherLesTous(struct File* f) {
    if(f->first == NULL) {
        printf("\nFile vide");
    } else {
        struct Cell* it;
        it = f->first;
        printf("\nFile :");
        while(it != NULL) {
            printf(" %d", it->val);
            it = it->next;
        } 
    }
}

int NbElements(struct File* f) {
    return f->nbElements;
}

int IsEmpty(struct File* f) {
    if(f->first == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void AfficherMenu() {
    printf("Menu de manipulation de File");
    printf("\n---------------------------");
    printf("\n- Ajouter un element (a)");
    printf("\n- Supprimer element (s)");
    printf("\n- Nombre elements (n)");
    printf("\n- File vide ? (v)");
    printf("\n- Montrer File (m)");
    printf("\n- Quitter (q)\n");
}


void ActionsUser(struct File* f) {

    char input;
    scanf("%c", &input);
    while (input != 'q') {
        switch (input) {
        case 'a':
            printf("\nElement a inserer : ");
            int elmnt = scanf("%d", &elmnt);
            AjouterFile(f, elmnt);
            break;
        case 's':
            EnleverFile(f);
            break;
        case 'n':
            printf("\nNombre elements dans file : %d", NbElements(f));
            break;
        case 'v':
            if(IsEmpty(f)) {
                printf("\nLa file est vide");
            } else {
                printf("nLa file est pas vide");
            }
            break;
        case 'm':
            AfficherLesTous(f);
            break;
        case 'q':
            return;
        default:
            AfficherMenu();
            ActionsUser(f);
            break;
        }
    }

}

int main() {

    struct File* f = malloc(sizeof(struct File));
    AfficherMenu();
    ActionsUser(f);
    printf("\n");
    return 0;
}