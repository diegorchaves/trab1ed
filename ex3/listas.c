#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

Lista* lst_cria (void)
{
    return NULL;
}

Lista* ultimo (Lista* l){
    Lista* p;
    Lista* ant = NULL;

    for (p = l; p != NULL; p = p->prox){
        ant = p;
    }

    return ant;
}

Lista* lst_insere_fim (Lista* l, int i, int j, int v)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = i;
    novo->coluna = j;
    novo->info = v;
    novo->prox = NULL;

    if(l == NULL){
        return novo;
    }

    ultimo(l)->prox = novo;

    return l;
}

void lst_imprime (Lista* l)
{   
    if(l == NULL){
        printf("Nenhum elemento viola.\n");
    }else{
       Lista* p;
       for (p = l; p != NULL; p = p->prox){
        printf("linha: %d, coluna: %d, valor: %d\n",p->linha+1, p->coluna+1, p->info);
       } 
    }
    
}

void lst_libera (Lista* l)
{
	Lista* p = l;
	while (p != NULL) {
		l = p->prox; 
		free(p); 
	    p = l; 
	}
}

int lst_busca(Lista* l, int i, int j){
    Lista* p;

    for (p = l; p != NULL; p = p->prox){
        if(p->linha == i && p->coluna == j){
            return p->info;
        }
    }

    if(i == j){
      return 1;
    }else{
      return 0;
    }
}

Lista* preenche_matriz(int n, Lista* l){
    int v;
    Lista* p = l;

    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Digite um valor\n");
            scanf("%d", &v);

            if((i == j && v != 1) || (i != j && v != 0)){
                p = lst_insere_fim(p, i, j, v);
            }
        }
    }

    return p;
}

void imprime_matriz(int n, Lista* l){
    int v;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v = lst_busca(l, i, j);
            printf(" %d", v);
        }
        printf("\n");
    }
}
