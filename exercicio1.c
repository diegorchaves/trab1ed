/*
1) ler a ordem da matriz
2) alocar o vetor
3) ler as entradas da diagonal principal e armazenar no vetor
4) imprimir a matriz
5) permitir a consulta de um elemento (ler linha e coluna onde ele se encontra)
6) se usuario digitar "-1", dar free e encerrar o programa */

#include <stdio.h>
#include <stdlib.h>

int *alocaVetor (int ordem)
{
    int *vetor = (int*)malloc(ordem * sizeof(int));
    if (vetor == NULL)
    {
        printf ("Erro ao alocar o vetor.\n");
        exit (1);
    }
    return vetor;
}

void leOrdem (int *ordem)
{
    printf ("Informe a ordem da matriz: ");
    scanf ("%d", ordem);
}

void leEntradas (int *vetor, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        printf ("Informe a entrada para [%d][%d]: ", i, i);
        scanf ("%d", &vetor[i]);
    }
}

void imprimeMatriz (int *vetor, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf ("%d ", (i==j) ? vetor[i] : 0);
        }
        printf ("\n");
    }
}

void consultaMatriz (int *vetor, int ordem)
{
    int i, j;

    while (1)
    {
        printf ("Informe a linha para buscar (-1 para sair): ");
        scanf ("%d", &i);
        if (i == -1)
        {
            exit (1);
        }
        else if (i >= ordem)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        printf ("Informe a coluna para buscar (-1 para sair): ");
        scanf ("%d", &j);
        if (j == -1)
        {
            exit (1);
        }
        else if (j >= ordem)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        printf ("O valor de [%d][%d] eh %d\n", i, j, (i == j) ? vetor[i] : 0);
    }
}

int main ()
{
    int ordem;
    int *vetor;
    
    leOrdem (&ordem);

    vetor = alocaVetor (ordem);

    leEntradas (vetor, ordem);

    imprimeMatriz (vetor, ordem);

    consultaMatriz (vetor, ordem);

    free (vetor);
}