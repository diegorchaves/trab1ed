#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
} Lista;

Lista *criaNovoNo (int linha, int coluna, Lista *l, int entrada)
{
    Lista *novoNo = (Lista*)malloc(sizeof(Lista));
    if (novoNo == NULL)
    {
        printf ("Memoria insuficiente.\n");
        exit (1);
    }
    novoNo->prox = NULL;
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->info = entrada;

    if (l == NULL)
    {
        return novoNo;
    }
    else
    {
        Lista *p = l;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novoNo;
        return l;
    }
}

Lista *leEntradasMatriz (Lista *l, int ordem)
{
    int entrada;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf ("Digite a entrada [%d][%d] da matriz: ", i, j);
            scanf ("%d", &entrada);
            if ((i == j) && (entrada != 1))
            {
                l = criaNovoNo (i, j, l, entrada);
            }
            else if ((i != j) && (entrada != 0))
            {
                l = criaNovoNo (i, j, l, entrada);
            }
        }
    }
    return l;
}

void imprimeMatriz (Lista *l, int ordem)
{
    Lista *p = l;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (p != NULL && p->linha == i && p->coluna == j)
            {
                printf ("%d ", p->info);
                p = p->prox;
            }
            else
            {
                printf ("%d ", (i == j) ? 1 : 0);
            }
        }
        printf ("\n");
    }
}

void imprimeViolacoes (Lista *l)
{
    Lista *p = l;
    if (p == NULL)
    {
        printf ("Eh uma matriz identidade.\n");
    }
    else
    {
        while (p != NULL)
        {
            printf ("O elemento [%d][%d] eh %d e viola a propriedade de matriz identidade.\n", p->linha, p->coluna, p->info);
            p = p->prox;
        }
    }
}

void freeLista (Lista *l)
{
    Lista *p = l, *ant;
    while (p != NULL)
    {
        ant = p;
        p = p->prox;
        free (ant);
    }
}

int main ()
{
    int ordem;
    Lista *l = NULL;

    printf ("Digite a ordem da matriz: ");
    scanf ("%d", &ordem);

    l = leEntradasMatriz (l, ordem);

    imprimeMatriz (l, ordem);

    imprimeViolacoes (l);

    freeLista (l);

    return 0;
}