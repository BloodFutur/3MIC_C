#include "command.h"
#include <stdlib.h>
#include <string.h>
#include "pile.h"
#include <stdio.h>

int addInt(int a, int b) {
    return a+b;
}

float addFloat(float a, float b) {
    return a+b;
}

int multiplyInt(int a, int b) {
    return a*b;
}

float multiplyFloat(float a, float b) {
    return a*b;
}

int subtractInt(int a, int b) {
    return a-b;
}

float subtractFloat(float a, float b) {
    return a-b;
}

int divideInt(int a, int b) {
    return a/b;
}

float divideFloat(float a, float b) {
    return a/b;
}

struct NumberContainer computeOperators(int (*opInt)(int,int), float (*opFloat)(float, float), struct NumberContainer a, struct NumberContainer b) {

    struct NumberContainer res;

    if(a.type == INT) {
        if(b.type == INT) {
            res.type = INT;
            res.number.valInt = opInt(a.number.valInt, b.number.valInt);
        } else {
            res.type = FLOAT;
            res.number.valFloat = opFloat((float)a.number.valInt, b.number.valFloat);
        }
    } else {
        res.type = FLOAT;
        if(b.type == INT) {
            res.number.valFloat = opFloat(a.number.valFloat, (float)b.number.valInt);
        } else {
            res.number.valFloat = opFloat(a.number.valFloat, b.number.valFloat);
        }
    }

    return res;
}

void add(struct Etat* state) {
    struct NumberContainer a,b,c;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);
    c = computeOperators(addInt,addFloat, a,b);
    Push(&state->pile, c);
}

void subtract(struct Etat* state) {
    struct NumberContainer a,b,c;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);
    c = computeOperators(subtractInt,subtractFloat, b,a);
    Push(&state->pile, c);
}

void multiply(struct Etat* state) {
    struct NumberContainer a,b,c;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);
    c = computeOperators(multiplyInt,multiplyFloat, a,b);
    Push(&state->pile, c);
}

void divide(struct Etat* state) {
    struct NumberContainer a,b,c;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);
    c = computeOperators(divideInt,divideFloat, a,b);
    Push(&state->pile, c);
}

void dup(struct Etat* state) {
    Push(&state->pile, Top(&state->pile));
}

void rot(struct Etat* state) {
    struct NumberContainer a,b,c;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);

    c = Top(&state->pile);
    Pop(&state->pile);

    Push(&state->pile, b);
    Push(&state->pile, a);
    Push(&state->pile, c);
}

void swap(struct Etat* state) {
    struct NumberContainer a,b;
    a = Top(&state->pile);
    Pop(&state->pile);

    b = Top(&state->pile);
    Pop(&state->pile);

    Push(&state->pile, a);
    Push(&state->pile, b);
}

void drop(struct Etat* state) {
    Pop(&state->pile);
}

void point(struct Etat* state) {
    printNumContainer(Top(&state->pile));
    printf("\n");
    Pop(&state->pile);
}

void pointS(struct Etat* state) {
    printNumContainer(Top(&state->pile));
    printf("\n");
}

void displayMode(struct Etat* state) {
    state->mode = AFFICHER;
}

void executeMode(struct Etat* state) {
    state->mode = EXECUTER;
}

void CR(struct Etat* state) {
    printf("\n");
}

void addTable(struct CommandList** cmdList, char* commandName, void (*func)(struct Etat*)) {
    struct CommandList* cmd = malloc(sizeof(struct CommandList));
    cmd->next = *cmdList;
    strncpy(cmd->commandName, commandName, MAX_CMD_NAME);
    cmd->func = func;

    *cmdList = cmd;
    //printf("%s\n", (*cmdList)->commandName);
}

int findAndExecute(struct CommandList* cmdList, char* commandName, struct Etat* state) {
    struct CommandList* cmd = cmdList;
    while(cmd != NULL) {
        //printf("%s", cmd->commandName);
        if( !strcmp(cmd->commandName, commandName) ) {
            cmd->func(state);
            return 0;
        } 
        cmd = cmd->next;
    } 
     
    return 1;
}

void displayTable(struct CommandList* cmdList) {
    struct CommandList* aux = cmdList;
    printf("\nAffichage table\n");
    while(aux != NULL) {
        printf("%s ", aux->commandName);
        aux = aux->next;
    }
    printf("\nFin affichage table\n");

}

void initTable(struct CommandList** cmdList) {
    addTable(cmdList, "DUP", dup);
    addTable(cmdList, "ROT", rot);
    addTable(cmdList, "SWAP", swap);
    addTable(cmdList, "DROP", drop);
    addTable(cmdList, ".", point);
    addTable(cmdList, ".S", pointS);
    addTable(cmdList, "+", add);
    addTable(cmdList, "-", subtract);
    addTable(cmdList, "*", multiply);
    addTable(cmdList, "/", divide);
    addTable(cmdList, ".\"", displayMode);
    addTable(cmdList, "\"", executeMode);
    addTable(cmdList, "CR", CR);


    //displayTable(*cmdList);
}

void destroyTable(struct CommandList* cmdList) {
    struct CommandList* aux = cmdList;
    if(cmdList != NULL) {
        while(cmdList->next != NULL) {
            cmdList = cmdList->next;
            free(aux);
            aux = cmdList;
        }
        free(cmdList);
    }
}