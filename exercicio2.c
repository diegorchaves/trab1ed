#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
} Lista;

typedef struct esparsa
{
    int linhas;
    int colunas;
    struct lista *prim;
} Esparsa;

Esparsa *criaEsparsa ()
{
    Esparsa *new;
    new = (Esparsa*)malloc(sizeof(Esparsa));
    if (new == NULL)
    {
        printf ("Erro ao alocar esparsa.\n");
        exit (1);
    }
    return new;
}

void leDadosEsparsa (Esparsa *esparsa)
{
    printf ("Digite o numero de linhas da matriz: ");
    scanf ("%d", &esparsa->linhas);
    printf ("Digite o numero de colunas da matriz: ");
    scanf ("%d", &esparsa->colunas);
}

Lista *novoNo (int linha, int coluna, int entrada, Lista *l, Esparsa *esparsa)
{
    Lista *novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->prox = NULL;
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->info = entrada;

    if (l == NULL)
    {
        l = novoNo;
    }
    else
    {
        Lista *p = l;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novoNo;
    }
    return l;
}

Lista *leEntradasMatriz (Lista *l, Esparsa *esparsa)
{
    int entrada;
    int i;
    int j;
    for (i = 0; i < esparsa->linhas; i++)
    {
        for (j = 0; j < esparsa->colunas; j++)
        {
            printf ("Digite a entrada [%d][%d] para a matriz: ", i, j);
            scanf ("%d", &entrada);

            if (entrada != 0)
            {
                l = novoNo (i, j, entrada, l, esparsa);
            }
        }
    }
    esparsa->prim = l;
    return l;
}

void imprimeEsparsa (Lista *l, Esparsa *esparsa)
{
    Lista *p = l;
    int i;
    int j;
    for (i = 0; i < esparsa->linhas; i++)
    {
        for (j = 0; j < esparsa->colunas; j++)
        {

            if (p != NULL && i == p->linha && j == p->coluna)
            {
                printf ("%d ", p->info);
                p = p->prox;
            }
            else
            {
                printf ("%d ", 0);
            }
        }
        printf ("\n");
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

void consulta (Lista *l, Esparsa *esparsa)
{
    int i, j;
    Lista *p;

    while (1)
    {
        p = l;
        printf ("Informe a linha para consultar (-1 para sair): ");
        scanf ("%d", &i);
        if (i == -1)
        {
            return;
        }
        else if (i >= esparsa->linhas)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        printf ("Informe a coluna para buscar (-1 para sair): ");
        scanf ("%d", &j);
        if (j == -1)
        {
            return;
        }
        else if (j >= esparsa->colunas)
        {
            printf ("Fora dos limites da matriz.\n");
            continue;
        }
        
        while (p != NULL && (p->linha != i || p->coluna != j))
        {
            p = p->prox;
        }

        if (p != NULL && p->linha == i && p->coluna == j)
        {
            printf ("Elemento [%d][%d] eh %d\n", i,j, p->info);
        }
        else
        {
            printf ("Elemento [%d][%d] eh %d\n", i,j, 0);
        }
    }
}

void somatorio (Lista *l)
{
    int linha, soma = 0;
    Lista *p = l;
    printf ("Informe a linha que deseja somar: ");
    scanf ("%d", &linha);

    while (p != NULL)
    {
        if (p->linha == linha)
        {
            soma += p->info;
        }
        p = p->prox;
    }
    printf ("A soma da linha %d eh %d\n", linha, soma);
}

void percentual (Lista *l, Esparsa *esparsa)
{
    float percentual;

    Lista *p;
    int tamanhoMatriz = esparsa->linhas * esparsa->colunas;
    int tamanhoLista = 0;

    for (p = l; p != NULL; p = p -> prox)
    {
        tamanhoLista++;
    }

    percentual = ((float)tamanhoLista/tamanhoMatriz) * 100.0;

    printf ("O percentual de valores nao nulos na matriz eh %.0f %%\n", percentual);
}

int main ()
{
    Esparsa *esparsa;
    Lista *l;

    esparsa = criaEsparsa ();

    leDadosEsparsa (esparsa);

    l = leEntradasMatriz (l, esparsa);

    imprimeEsparsa (l, esparsa);

    consulta (l, esparsa);

    somatorio (l);

    percentual (l, esparsa);

    free (esparsa);
    
    freeLista (l);

    return 0;
}
