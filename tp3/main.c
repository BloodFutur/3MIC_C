#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pile.h"
#include "lexer.h"
#include "execute.h"
#include "command.h"


int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Il faut un parametre");
        exit(1);
    }

    struct Programme* instructions;
    instructions = lexer(argv[1]);


    for(int i=0; i < instructions->taille; i++) {
        printf("TOKEN : %s\n", instructions->tokens[i]);
    }



    struct Etat etat;

    Init(&(etat.pile));

    struct CommandList* cmdList = NULL;
    initTable(&cmdList);
    etat.cmdList = cmdList;

    etat.prog = instructions;
    etat.mode = EXECUTER;


    executer(&etat);



    return 0;
}