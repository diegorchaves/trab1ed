#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"



int main()
{   
    int m;
    int n;
    int z;
    int ***mat;

    printf("Digite as linhas. \n");
    scanf("%d", &m);
    printf("Digite as colunas. \n");
    scanf("%d", &n);
    printf("Digite as profundidade. \n");
    scanf("%d", &z);

    mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);  

    return 0;
}