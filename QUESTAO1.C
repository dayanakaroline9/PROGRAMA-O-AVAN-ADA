#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FUNÇÃO PARA CONVERTER SEQUENCIA BINARIA EM NUMERO DECIMAL
int converteBits(char **M, int nc, int l){
  long int numero = 0;
  for(int j = nc - 1; j >= 0; j--) {
    if(M[l][j] == 1) {
      numero += pow(2,nc-j);
    }
  }  
  return numero;
}

//FUNÇÃO PARA IMPRIMIR MATRIZ 
void imprimeMatriz (char **M, int l, int c){
  printf("\nMATRIZ[%d][%d]\n\n",l,c);
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      printf("%d",M[i][j]);
    }
    printf("\n");
  }
}

//FUNÇÃO PARA PREENCHER MATRIZ BINARIA DE FORMA ALEATÓRIA
void matrizBinaria (char **M, int l, int c){
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      M[i][j] =rand()%2;
    }
  }
  //MOSTRANDO MATRIZ PREENCHIDA
  imprimeMatriz(M,l,c);
}

int main(){

  char **matriz; 
  int linhas=8, colunas=8;
  
  //ALOCA MATRIZ
  matriz = (char**) malloc(linhas*sizeof(char*));
  
  //ALOCA LINHAS DA MATRIZ
  for(int i=0; i<linhas; i++){
    matriz[i] = (char*) malloc(colunas*sizeof(char));
  }

  //PREENCHE MATRIZ BINÁRIA
  matrizBinaria(matriz, linhas, colunas);

  //IMPRIME SEQUENCIA BINÁRIA E SEU VALOR EM DECIMAL
  printf("\nMATRIZ BINÁRIA\n\n");
  for(int i = 0; i < linhas; i++) {
      for(int j = 0; j < colunas; j++) {
          printf("%d", matriz[i][j]);
      }
      printf(" = %d\n",converteBits(matriz,colunas,i));
  }

  //MEMORIA ALOCADA É LIBERADA!!
  for(int i=0; i<linhas; i++){
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
