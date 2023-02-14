#ifndef PILE_H
#define PILE_H

enum NumberType {INT, FLOAT};

union Number {
    int valInt;
    float valFloat;
};

struct NumberContainer {
    union Number number;
    enum NumberType type;
};

struct List;
struct List{
    struct NumberContainer value;
    struct List * next;
};

struct Pile{
    struct List* list;
    int size;
};

void Init(struct Pile* pile);
void Push(struct Pile* pile, struct NumberContainer element);
void Pop(struct Pile* pile);
void Display(struct Pile* pile);
struct NumberContainer Top(struct Pile* pile);
int Size(struct Pile* pile);

#endif