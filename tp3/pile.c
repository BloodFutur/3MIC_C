#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


void Init(struct Pile* pile) {
    pile->list = NULL;
    pile->size = 0;
}

void Push(struct Pile* pile, struct NumberContainer element) {
    if(pile->size == 0) {
        pile->list = malloc(sizeof(struct List));
        pile->list->value = element;
        pile->list->next  = NULL;
    } else {
        struct List* list = malloc(sizeof(struct List));
        list->value = element;
        list->next  = pile->list;
        pile->list = list;
    }
    pile->size += 1;
}

void Pop(struct Pile* pile) {
    if(pile->size != 0) {
        struct List* aux = pile->list;
        pile->list = pile->list->next;
        pile->size -= 1;
        free(aux);
    }
}

void Display(struct Pile* pile) {
    struct List* aux = pile->list;
    while(aux != NULL) {
        if(aux->value.type == INT) {
            printf("%d ", aux->value.number.valInt);
        } else {
            printf("%f ", aux->value.number.valFloat);
        }
        aux = aux->next;
    }
    printf("\n");
}

struct NumberContainer Top(struct Pile* pile) {
    if(pile->size == 0) {
        fprintf(stderr, "Pile vide");
        exit(1);
    }
    return pile->list->value;
}

int Size(struct Pile* pile) {
    return pile->size;
}