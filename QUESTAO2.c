#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void desenhaElipse(int ***M, int p, int l, int c){
  //calculando o centro da elipse
  float xc=p/2, yc=l/2, zc=c/2;
  
  //preenchendo a matriz X[planos][linhas][colunas] para planos=i, linhas=j e colunas=k;
  for(int i=0; i<p; i++){
    for(int j=0; j<l; j++){
      for(int k=0; k<c; k++){
        //calculando area da elipse pela formula padrão
        float R = pow(((float)(i-zc)/(zc)),2) + 
                  pow(((float)(j-xc)/(xc)),2) + 
                  pow(((float)(k-yc)/(yc)),2);
        //se o valor de R for menor ou igual a 1
        if(R<=1){
             M[i][j][k]=1; //guarda 1 na posição x[z][x][y] da matriz
          }else{
             M[i][j][k]=0; //guarda 0 se R for maior que 1
          }
        
      }
    }
  }
}

int main(){
  int ***matriz;
  int planos,linhas, colunas, p; 

  //ENTRADA DE DIMENSÕES DA MATRIZ
  printf("Digite o tamanho da matriz: \nPlanos: ");
  scanf("%d",&planos);
  printf("Linhas: ");
  scanf("%d",&linhas);
  printf("Colunas: ");
  scanf("%d",&colunas);
  
  //Alocando matriz 
  matriz = (int***) malloc(planos*sizeof(int**));

  //Alocando linhas
  for(int i=0; i<(planos); i++){
    matriz[i]= (int**) malloc(linhas*sizeof(int*));
  }

  //Alocando colunas
  for(int i=0; i<planos ;i++){
    for(int j=0; j<linhas; j++){
    matriz[i][j]= (int*) malloc(colunas*sizeof(int));
    }
  }

  //Desenha Elipse
  desenhaElipse(matriz, planos, linhas ,colunas);

  //Escolha do plano a ser exibido 
  printf("Digite qual o plano no eixo ”z” você deseja apresentar na tela: \n");
  scanf("%d",&p);
  printf("Plano[%d] : \n",p);
  
  for(int j=0; j<planos; j++){
    for(int k=0; k<linhas; k++){
      printf("%d ",matriz[p][j][k]); 
      //p fixo com o valor do plano passado pelo usuario
    }
    printf("\n");
  }
  
  
  //Memoria alocada liberada!!
  for(int i=0; i<planos ;i++){
    for(int j=0; j<linhas; j++){
      free(matriz[i][j]); //libera colunas
    }
  }
  for(int i=0; i<planos; i++){
    free(matriz[i]); //libera linhas
  }
  free(matriz); //libera matriz
  return 0;
}
