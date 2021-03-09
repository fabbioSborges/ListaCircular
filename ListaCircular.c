#include <stdlib.h>
#include "ListaCircular.h"

TListaCircular *CriarLista(){
  TListaCircular *nova = (TListaCircular*) malloc(sizeof(TListaCircular));
  if(nova == NULL){
    return NULL;
  }
  nova->prim = NULL;
  nova->tamanho = 0;
  return nova;
}

int ListaVazia(TListaCircular *lista){
  return lista->prim == NULL;
}

int InserirPrimeiraPosicao(TListaCircular *lista, TInfo info){
  TElem *novoElem = (TElem*) malloc(sizeof(TElem));
  if(novoElem == NULL){
    return 0;
  }
  novoElem->info = info;
  if(ListaVazia(lista)){
    novoElem->prox = novoElem;
    lista->prim = novoElem; 
    lista->tamanho++;
    return 1;
  }else{
    TElem *aux = lista->prim;
    while(aux->prox != lista->prim){
      aux = aux->prox;
    }
    aux->prox = novoElem;
    novoElem->prox = lista->prim;
    lista->prim = novoElem;
    lista->tamanho++;
  }
  return 0;
}


int InserirUltimaPosicao(TListaCircular *lista, TInfo info){
  TElem *novoElem = (TElem*) malloc(sizeof(TElem));
  if(novoElem == NULL){
    return 0;
  }
  novoElem->info = info;
  if(ListaVazia(lista)){
    novoElem->prox = novoElem;
    lista->prim = novoElem; 
    lista->tamanho++;
    return 1;
  }else{
    TElem *aux = lista->prim;
    while(aux->prox != lista->prim){
      aux = aux->prox;
    }
    novoElem->prox = aux->prox;
    aux->prox = novoElem;
    //novoElem->prox = lista->prim;
    lista->tamanho++;
  }
  return 0;
}


int tamanho(TListaCircular *lista){
  if(ListaVazia(lista)){
    return 0;
  }
  TElem *aux = lista->prim;
  int tamanho = 0;
  
  /*while((aux != lista->prim)){
    tamanho++;
    aux = aux->prox;
  }*/

  do{
    tamanho++;
    aux = aux->prox;
  }while((aux != lista->prim));
  
  return tamanho;
}