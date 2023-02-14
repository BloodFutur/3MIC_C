#ifndef EXECUTE_H
#define EXECUTE_H

#include "pile.h"
#include "lexer.h"

void getLastTwo(struct NumberContainer* a, struct NumberContainer* b, struct Pile* pile);
struct NumberContainer getNumber(char * n);
void printNumContainer(struct NumberContainer n);
void executer(struct Etat* etat);

#endif