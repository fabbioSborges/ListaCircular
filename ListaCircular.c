#include <stdlib.h>
#include <stdio.h>
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

int RemovePrimeiro(TListaCircular *lista){
  if(ListaVazia(lista)){
    return 0;
  }
  if(lista->prim->prox == lista->prim){
    free(lista->prim);
    lista->prim = NULL;
    return 1;
  }
  TElem *aux = lista->prim;
  while(aux->prox != lista->prim){
    aux = aux->prox;
  }
  TElem *remove = lista->prim;
  aux->prox = remove->prox;
  lista->prim = remove->prox;
  free(remove);
  return 1;
  
}


int RemoveUltimo(TListaCircular *lista){
  if(ListaVazia(lista)){
    return 0;
  }
  if(lista->prim->prox == lista->prim){
    free(lista->prim);
    lista->prim = NULL;
    return 1;
  }
  TElem *remove, *ant = lista->prim;
  while(remove->prox != lista->prim){
    ant = remove;
    remove = remove->prox;
  }
  ant->prox = remove->prox;
  free(remove);
  return 1;
  
}

void imprimri(TListaCircular *lista){
  if(!ListaVazia(lista)){
    int i = 1;
    TElem *aux = lista->prim;
    do{
      printf("--------Elemento %d----------", i);
      printf("Matricula: %d\n", aux->info.matricula);
      i++;
      aux = aux->prox;
    }while((aux != lista->prim));
  }
  
}