#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

int main(void) {
  TInfo info;
  TListaCircular *minhaLista= CriarLista();

  if(ListaVazia(minhaLista)){
    printf("Lista vazia\n\n");
  }

   printf("Tamanho: %d\n", tamanho(minhaLista));


  info.matricula = 10;
  info.media = 5.6;
  InserirPrimeiraPosicao(minhaLista, info);

  info.matricula = 11;
  info.media = 5.6;
  InserirPrimeiraPosicao(minhaLista, info);

  info.matricula = 12;
  info.media = 5.6;
  InserirPrimeiraPosicao(minhaLista, info);

  imprimri(minhaLista);

  RemoveUltimo(minhaLista);

  printf("Tamanho: %d\n\n", tamanho(minhaLista));
  imprimri(minhaLista);

  
  return 0;
}