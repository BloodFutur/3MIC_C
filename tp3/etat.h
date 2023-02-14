#ifndef ETAT_H
#define ETAT_H

#include "pile.h"
#include "lexer.h"

enum Mode {EXECUTER, AFFICHER};

struct Etat {
    struct Pile pile;
    struct Programme* prog;
    struct CommandList* cmdList;
    enum Mode mode;
};

#endif