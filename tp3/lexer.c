#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int numberOfDelimiters(char *string) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
            count++;
    }
    return count;
}

struct Programme *lexer(char *chaine) {
    char *token, *str;
    str = strdup(chaine);
    int i = 0;
    int arraysize = (numberOfDelimiters(str) + 1);
    char **programme = (char **)malloc(sizeof(char *) * arraysize);
    while ((token = strsep(&str, " ")))
    {
        programme[i] = token;
        i++;
    }
    struct Programme *retour = (struct Programme *)malloc(sizeof(struct Programme));
    retour->tokens = programme;
    retour->taille = i;
    return retour;
}