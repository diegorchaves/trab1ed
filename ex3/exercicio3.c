#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main()
{   
    int n;
    char resposta;
   

    do{
        Lista* l;
        l = lst_cria();
        
        printf("Digite a ordem da matriz:\n");
        scanf("%d", &n);

        l = preenche_matriz(n, l);

        printf("Imprimindo Matriz:\n");
        imprime_matriz(n, l);

        printf("Elementos que violam a matriz identidade:\n");
        lst_imprime(l);

        lst_libera(l);

        printf("Recomecar? S ou N:\n");
        scanf(" %c", &resposta);
    }while(resposta != 'N');

    

    return 0;
}