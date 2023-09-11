#include <stdio.h>
#include <stdlib.h>

typedef struct diagonal
{
    int ordem;
    int *vetor;
} Diagonal;

Diagonal *alocaStruct ()
{
    Diagonal *p = (Diagonal*)malloc(sizeof(Diagonal));
    
    if (p == NULL)
    {
        printf ("Falha ao alocar a struct.\n");
        exit (1);
    }
    return p;
}

int *alocaVetor (int ordem)
{
    int *vet = (int*)malloc(sizeof(int)*ordem);
    if (vet == NULL)
    {
        printf ("Falha ao alocar o vetor.\n");
        exit (1);
    }
    return vet;
}

void leOrdem (int *ordem)
{
    printf ("Informe a ordem da matriz: ");
    scanf ("%d", ordem);
}

void leEntradas (Diagonal *diagonal)
{
    for (int i = 0; i < diagonal->ordem; i++)
    {
        printf ("Informe a entrada para [%d][%d]: ", i, i);
        scanf ("%d", &diagonal->vetor[i]);
    }
}

void imprimeMatriz (Diagonal *diagonal)
{
    for (int i = 0; i < diagonal->ordem; i++)
    {
        for (int j = 0; j < diagonal->ordem; j++)
        {
            printf ("%d ", (i == j) ? diagonal->vetor[i] : 0);
        }
        printf ("\n");
    }
}

void consultaMatriz (Diagonal *diagonal)
{
    int i, j;

    while (1)
    {
        printf ("Informe a linha para buscar (-1 para sair): ");
        scanf ("%d", &i);
        if (i == -1)
        {
            free (diagonal->vetor);
            free (diagonal);
            exit (1);
        }
        else if (i >= diagonal->ordem)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        printf ("Informe a coluna para buscar (-1 para sair): ");
        scanf ("%d", &j);
        if (j == -1)
        {
            free (diagonal->vetor);
            free (diagonal);
            exit (1);
        }
        else if (j >= diagonal->ordem)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        printf ("O valor de [%d][%d] eh %d\n", i, j, (i == j) ? diagonal->vetor[i] : 0);
    }
}

int main ()
{
    Diagonal *diagonal;

    diagonal = alocaStruct ();
    
    leOrdem (&diagonal->ordem);

    diagonal->vetor = alocaVetor (diagonal->ordem);

    leEntradas (diagonal);

    imprimeMatriz (diagonal);

    consultaMatriz (diagonal);

    return 0;
}