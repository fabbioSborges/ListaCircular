typedef struct{
  int matricula;
  float media;
  float notas[3];

}TInfo;

typedef struct elem{
  TInfo info; 
  struct elem *prox;
}TElem;

typedef struct{
  TElem *prim;
  int tamanho;
}TListaCircular;

TListaCircular *CriarLista();
int ListaVazia(TListaCircular *lista);
int InserirPrimeiraPosicao(TListaCircular *lista, TInfo info);
void imprimirLista(TListaCircular *lista);
int InserirUltimaPosicao(TListaCircular *lista, TInfo info);
int RemovePrimeiro(TListaCircular *lista);
int RemoveUltimo(TListaCircular *lista);
int tamanho(TListaCircular *lista);
void imprimri(TListaCircular *lista);