#include "execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void getLastTwo(struct NumberContainer* a, struct NumberContainer* b, struct Pile* pile) {
    *b = Top(pile);
    Pop(pile);
    *a = Top(pile);
    Pop(pile);
}

struct NumberContainer getNumber(char * n) {
    struct NumberContainer res;
    char * aux = n;
    int nbdot = 0;
    while(*(aux) != '\0') {
        if(*(aux) == '.') {
            nbdot++;
        }

        aux++;
    }
    if(nbdot == 0) {
        res.number.valInt = atoi(n);
        res.type = INT;
    } else if(nbdot == 1) {
        res.number.valFloat = atof(n);
        res.type = FLOAT;
    } else {
        fprintf(stderr, "Nombre inattendu");
        exit(1);
    }
    return res;
}

void printNumContainer(struct NumberContainer n) {
    if(n.type == INT) {
        printf("%d", n.number.valInt);
    } else {
        printf("%f", n.number.valFloat);
    }
}

void executer(struct Etat* etat) {
    struct NumberContainer a;
    for(int i=0; i < etat->prog->taille; i++) {
        switch(etat->mode){
            case EXECUTER:
                if(isdigit(etat->prog->tokens[i][0])) {
                    a = getNumber(etat->prog->tokens[i]);
                    Push(&(etat->pile), a);
                } else {
                    int res = 1;
                    res = findAndExecute(etat->cmdList, etat->prog->tokens[i], etat);
                    if( res == 1) {
                        fprintf(stderr, "unknown symbol: %s", etat->prog->tokens[i]);
                        exit(1);
                    }
                }
                break;
            case AFFICHER:
                if(!strcmp(etat->prog->tokens[i], "\"")) {
                    etat->mode = EXECUTER;
                } else {
                    printf("%s ", etat->prog->tokens[i]);
                }
                break;
            default:
                break;
        }
    }
}
