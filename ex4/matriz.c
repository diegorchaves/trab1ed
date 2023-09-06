#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

int*** aloca_matriz (int m, int n, int z){
    int*** mat;

    mat = (int***)malloc(m*sizeof(int**));

    for(int i = 0; i < m; i++){
        mat[i] = (int**)malloc(n*sizeof(int*));
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = (int*)malloc(z*sizeof(int));
        }
    }

    return mat;
}

void imprime_matriz (int m, int n, int z, int*** mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
           for(int k = 0; k < z; k++){
             printf("%d ", mat[i][j][k]);
           }
          printf("\n");
        }
        printf("\n");
    }
}

void preenche_matriz(int m, int n, int z, int*** mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < z; k++){
                printf("digite um valor: ");
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void desaloca_matriz (int m, int n, int*** mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            free(mat[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
            free(mat[i]);
    }

    free(mat);
}
