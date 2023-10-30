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

Esparsa *criaEsparsa (Lista *l)
{
    Esparsa *new;
    new = (Esparsa*)malloc(sizeof(Esparsa));
    if (new == NULL)
    {
        printf ("Erro ao alocar esparsa.\n");
        exit (1);
    }
    new->prim = l;
    return new;
}

void leDadosEsparsa (Esparsa *esparsa)
{
    printf ("Digite o numero de linhas da matriz: ");
    scanf ("%d", &esparsa->linhas);
    printf ("Digite o numero de colunas da matriz: ");
    scanf ("%d", &esparsa->colunas);
}

Lista *novoNo (int linha, int coluna, int entrada, Esparsa *esparsa)
{
    Lista *novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->prox = NULL;
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->info = entrada;

    if (esparsa->prim == NULL)
    {
        return novoNo;
    }
    else
    {
        Lista *p = esparsa->prim;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novoNo;
    }
    return esparsa->prim;
}

Lista *leEntradasMatriz (Esparsa *esparsa)
{
    int entrada;
    int i;
    int j;
    
    do {
        printf ("Digite a entrada para a matriz (0 para encerrar a insercao): ");
        scanf ("%d", &entrada);

        if (entrada != 0)
        {
            printf ("Digite a posicao que quer inserir a entrada (linha coluna): ");
            scanf ("%d %d", &i, &j);
            if (i >= esparsa->linhas || j >= esparsa->colunas)
            {
                printf ("Fora dos limites da matriz.\n");
            }
            else
            {
                esparsa->prim = novoNo (i, j, entrada, esparsa);
            }
        }
    } while (entrada != 0);
            
    return esparsa->prim;
}

void imprimeEsparsa (Esparsa *esparsa)
{
    int i;
    int j;
    for (i = 0; i < esparsa->linhas; i++)
    {
        for (j = 0; j < esparsa->colunas; j++)
        {
            Lista *p = esparsa->prim;
            while (p != NULL && (i != p->linha || j != p->coluna))
            {
                p = p->prox;
            }
            if(p != NULL){
                printf ("%d ", p->info);
            }else
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

void consulta (Esparsa *esparsa)
{
    int i, j;
    Lista *p;

    while (1)
    {
        p = esparsa->prim;
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

void somatorio (Esparsa *esparsa)
{
    int linha, soma = 0;
    Lista *p = esparsa->prim;
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

void percentual (Esparsa *esparsa)
{
    float percentual;

    Lista *p;
    int tamanhoMatriz = esparsa->linhas * esparsa->colunas;
    int tamanhoLista = 0;

    for (p = esparsa->prim; p != NULL; p = p -> prox)
    {
        tamanhoLista++;
    }

    percentual = ((float)tamanhoLista/tamanhoMatriz) * 100.0;

    printf ("O percentual de valores nao nulos na matriz eh %.0f %%\n", percentual);
}

int main ()
{
    Esparsa *esparsa;
    Lista *l = NULL;

    esparsa = criaEsparsa (l);

    leDadosEsparsa (esparsa);

    esparsa->prim = leEntradasMatriz (esparsa);

    imprimeEsparsa (esparsa);

    consulta (esparsa);

    somatorio (esparsa);

    percentual (esparsa);

    free (esparsa);
    
    freeLista (l);

    return 0;
}
