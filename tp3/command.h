#ifndef COMMAND_H
#define COMMAND_H

#include "etat.h"

#define MAX_CMD_NAME 5

struct CommandList {
    struct CommandList* next;
    char commandName[MAX_CMD_NAME];
    void (*func)(struct Etat*);
};

void addTable(struct CommandList** cmdList, char* commandName, void (*func)(struct Etat*));
int findAndExecute(struct CommandList* cmdList, char* commandName, struct Etat* state);
void initTable(struct CommandList** cmdList);
void destroyTable(struct CommandList* cmdList);

#endif