#include <stdio.h>
#include <stdlib.h>

#define DIM1 3
#define DIM2 2

void Saisie(int tab[DIM1][DIM2])
{
    for (int i = 0; i < DIM1; i++)
    {
        for (int j = 0; j < DIM2; j++)
        {
            printf("l%dc%d:", i, j);
            scanf("%d", &(tab[i][j]));
        }
    }
}

void Saisie2(int **tab, int dim1, int dim2)
{
    for (int i = 0; i < dim1; i++)
    {
        tab[i] = malloc(sizeof(int) * dim2);
        for (int j = 0; j < dim2; j++)
        {
            scanf("%d", tab[i] + j);
        }
    }
}

void Saisie2p(int **tab, int dim1, int dim2)
{
    for (int i = 0; i < dim1; i++)
    {
        tab[i] = malloc(sizeof(int) * dim2);
        for (int j = 0; j < dim2; j++)
        {
            scanf("%d", *(tab + i) + j);
        }
    }
}

void Affiche(int *tab, int dim1, int dim2)
{
    printf("\n");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            printf("%d ", tab[j * dim1 + i]);
        }
        printf("\n");
    }
}

void Affiche2(int **tab, int dim1, int dim2)
{
    printf("\n");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            printf("%5d ", tab[i][j]);
        }
        printf("\n");
    }
}

void Affiche2p(int **tab, int dim1, int dim2)
{
    printf("\n");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            printf("%5d ", *(*(tab + i) + j));
        }
        printf("\n");
    }
}

void Init(int ***tab, int dim1, int dim2)
{
    *tab = malloc(sizeof(int*) * dim1);
    for (int i = 0; i < dim1; i++)
    {
        (*tab)[i] = malloc(sizeof(int) * dim2);
        for (int j = 0; j < dim2; j++)
        {
            printf("%d,%d", i,j);
            scanf("%d", (*tab)[i]+j);
        }
    }
}

int main()
{
    int tab[DIM1][DIM2];
    Saisie(tab);

    // int *M[dim1];

    // Saisie(*tab, dim1, dim2);
    // Affiche(*tab, dim1, dim2);

    // Saisie2(M, dim1, dim2);
    // Affiche2(M, dim1, dim2);

    // Saisie2p(M, dim1, dim2);
    // Affiche2p(M, dim1, dim2);

    // int **M1;
    // Init(&M1, dim1, dim2);
    // Affiche2p(M1, dim1, dim2);
    
    return 0;
}