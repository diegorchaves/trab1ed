struct lista{
    int linha; 
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria (void);

Lista* ultimo (Lista* l);

Lista* lst_insere_fim (Lista* l, int i, int j, int v);

void lst_imprime (Lista* l);

void lst_libera (Lista* l);

int lst_busca(Lista* l, int i, int j);

Lista* preenche_matriz(int n, Lista* l);

void imprime_matriz(int n, Lista* l);