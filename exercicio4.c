#include <stdio.h>
#include <stdlib.h>

int ***alocaMatriz (int linhas, int colunas, int profundidade)
{
    int ***mat;
    int i, j;

    mat = (int***)malloc(linhas * sizeof(int**));
    if (mat == NULL)
    {
        printf ("Memoria insuficiente.\n");
        exit (1);
    }
    for (i = 0; i < linhas; i++)
    {
        mat[i] = (int**)malloc(colunas * sizeof(int*));
        if (mat[i] == NULL)
        {
            printf ("Memoria insuficiente.\n");
            exit (1);
        }
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            mat[i][j] = (int*)malloc(profundidade * sizeof(int));
            if (mat[i][j] == NULL)
            {
                printf ("Memoria insuficiente.\n");
                exit (1);
            }
        }
    }
    return mat;
}

void liberaMatriz (int linhas, int colunas, int ***mat)
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}

void preencheMatriz (int linhas, int colunas, int profundidade, int ***mat)
{
    int i, j, k;
    
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            for (k = 0; k < profundidade; k++)
            {
                printf ("Digite o elemento [%d][%d][%d]: ", i, j, k);
                scanf ("%d", &mat[i][j][k]);
            }
        }
    }
}
void imprimeMatriz (int linhas, int colunas, int profundidade, int ***mat)
{
    int i, j, k;
    
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            for (k = 0; k < profundidade; k++)
            {
                printf ("%d ", mat[i][j][k]);
            }
            printf ("\n");
        }
        printf ("\n");
    }
} 

int main ()
{
    int linhas, colunas, profundidade;
    int ***mat;

    printf ("Digite quantas linhas a matriz tem: ");
    scanf ("%d", &linhas);
    printf ("Digite quantas colunas a matriz tem: ");
    scanf ("%d", &colunas);
    printf ("Agora digite a profundidade da matriz: ");
    scanf ("%d", &profundidade);
    
    mat = alocaMatriz (linhas, colunas, profundidade);

    preencheMatriz (linhas, colunas, profundidade, mat);

    imprimeMatriz (linhas, colunas, profundidade, mat);

    liberaMatriz (linhas, colunas, mat);

    return 0;
}