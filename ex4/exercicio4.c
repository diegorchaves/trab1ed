#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{   
    int m;
    int n;
    int z;
    int ***mat;

    printf("Digite a profundidade. \n");
    scanf("%d", &m);
    printf("Digite as linhas. \n");
    scanf("%d", &n);
    printf("Digite as colunas. \n");
    scanf("%d", &z);

    mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat); 
    desaloca_matriz(m, n, mat); 

    return 0;
}
