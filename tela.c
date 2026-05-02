#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tela.h"
#include "desenharLinha.h"
#include "viewPort.h"
#include "poligono.h"

//criar a tela
int **criaTela(int larg, int alt){
  //Na tela, a coordenada x cresce da esquerda para a direita
  //A coordenada y cresce de cima para baixo. A origem fica no canto superior-esquerdo
  int **tela, i, j;
  //Alocando a tela totalmente limpa
  tela = (int **) malloc(alt * sizeof(int *));
  for(i=0; i<alt; i++) {
    tela[i] = (int *) malloc(larg * sizeof(int));
    for(j=0; j<larg; j++) tela[i][j] = 0;
  }
  return tela;
}


//imprimir na tela
void imprimeTela(int **tela){
  int i, j;
  //Imprime a tela no terminal
  printf(" X|0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999|\n");
  printf("Y |0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789|\n");
  printf("--+----------------------------------------------------------------------------------------------------+\n");
  for(i=0; i<nLinha; i++) {
    printf("%2d|", i);
    for(j=0; j<nColuna; j++)
      if(tela[i][j]) printf("*");
      else printf(" ");
    printf("|\n");
  }  printf("--+----------------------------------------------------------------------------------------------------+\n");
}



//limpar tela
void limparTela(int **tela){
    for(int i=0;i<nLinha;i++){
        for(int j=0;j<nColuna;j++){
            tela[i][j] = 0;
        }
    }
}
