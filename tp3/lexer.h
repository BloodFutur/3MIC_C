#ifndef LEXER_H
#define LEXER_H

#include "pile.h"
#include "command.h"

struct Programme {
    char **tokens;
    int taille;
};


int numberOfDelimiters(char *string);
struct Programme *lexer(char *chaine);

#endif