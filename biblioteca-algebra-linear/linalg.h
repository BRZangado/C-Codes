/*

  * Universidade de Brasília
  * Disciplina: Algoritmos de programação de computadores - 2017/1
  * Turma: FF
  * Aluno: Bruno Rodrigues Santos - 16/0114934
  *
  * Projeto em sala 03: Biblioteca de funções de Álgebra Linear
  *
  *Este projeto trate-se de uma biblioteca composta por várias
   funções de Álgebra Linear, como, por exemplo, soma, subtração e
   multiplicção de matrizes.




*/

#ifndef LINALG_H
#define LINALG_H
#include <stdio.h>


struct matriz{ // criação da estrutura para matrizes

  unsigned int num_linhas, num_colunas;
  double matriz[100][100];


};

typedef struct matriz Matrix;
const Matrix error = {0,0};


Matrix scanm(unsigned int linhas, unsigned int colunas){ // função para leitura de matrizes

  Matrix m;
  m.num_linhas = linhas;
  m.num_colunas = colunas;
  int i, j;

  for(i = 0; i < linhas; i++){

    for(j = 0; j < colunas; j++){
      
      scanf("%lf", &m.matriz[i][j]);

    }
  }
  
  return m;

}

void printm(Matrix A){ // função para imprimir matrizes

  
  int i, j;

  for(i = 0; i < A.num_linhas; i++){ 

    for(j = 0; j < A.num_colunas; j++){ 

      printf("%.0lf ", A.matriz[i][j]);

    }
    printf("\n");
  }

}


Matrix sum(Matrix matriz_a,Matrix matriz_b){  // função para soma de matrizes
  
  Matrix matriz_resultado;
  matriz_resultado.num_linhas = matriz_a.num_linhas;
  matriz_resultado.num_colunas = matriz_a.num_colunas;
  int i, j;

  if(matriz_a.num_linhas == matriz_b.num_linhas && matriz_a.num_colunas == matriz_b. num_colunas){ // verifica se a soma é possível

    for(i=0; i < matriz_a.num_linhas; i++){

      for(j=0; j < matriz_a.num_colunas; j++){

        matriz_resultado.matriz[i][j] = matriz_a.matriz[i][j] + matriz_b.matriz[i][j];
            

      }

    }

    return matriz_resultado;

  }

  else{

    return error;
  }



}


Matrix subtract(Matrix matriz_a, Matrix matriz_b){  // função para subtração de matrizes

  Matrix matriz_resultado;
  matriz_resultado.num_linhas = matriz_a.num_linhas;
  matriz_resultado.num_colunas = matriz_a.num_colunas;
  int i, j;

  if(matriz_a.num_linhas == matriz_b.num_linhas && matriz_a.num_colunas == matriz_b. num_colunas){ // verifica se a subtração é possível

    for(i=0; i < matriz_a.num_linhas; i++){

      for(j=0; j < matriz_a.num_colunas; j++){

        matriz_resultado.matriz[i][j] = matriz_a.matriz[i][j] - matriz_b.matriz[i][j];
            

      }

    }

    return matriz_resultado;

  }

  else{

    return error;
  }

}

Matrix dot(Matrix matriz_a, Matrix matriz_b){ // função para multiplicação de matrizes

  Matrix matriz_resultado;
  matriz_resultado.num_linhas = matriz_a.num_linhas;
  matriz_resultado.num_colunas = matriz_a.num_colunas;
  
  int i, j, k, m;;
  
  if(matriz_a.num_colunas == matriz_b.num_linhas){ // verifica se a multiplicação é possível
    
    for(i = 0; i< matriz_resultado.num_linhas; i++){
      for(j = 0; j < matriz_resultado.num_colunas; j++){
        
        int x = 0;
        
        for(k = 0, m = 0; k<matriz_b.num_colunas; k++, m++){
          x+=matriz_a.matriz[i][m]*matriz_b.matriz[m][j];
        }
        
        matriz_resultado.matriz[i][j] = x;
        
      }
    }
    return matriz_resultado;
  }
  
  else{
    return error;
  }

} 


Matrix multiply(Matrix matriz_a, double constante){ // função para multiplicação de matrizes por constante

  Matrix matriz_resultado;
  matriz_resultado.num_linhas = matriz_a.num_linhas;
  matriz_resultado.num_colunas = matriz_a.num_colunas;
  int i, j;

  for(i=0; i < matriz_a.num_linhas; i++){

      for(j=0; j < matriz_a.num_colunas; j++){

        matriz_resultado.matriz[i][j] = matriz_a.matriz[i][j] * constante;
            

      }

    }

  return matriz_resultado;

}


Matrix transpose(Matrix matriz_a){ // função para gerar matriz transposta de uma matriz qualquer

  Matrix matriz_transposta;
  matriz_transposta.num_linhas = matriz_a.num_linhas;
  matriz_transposta.num_colunas = matriz_a.num_colunas;
  int i, j;

  for(i=0; i < matriz_a.num_linhas; i++){

    for(j=0; j < matriz_a.num_colunas; j++){

      matriz_transposta.matriz[i][j] = matriz_a.matriz[j][i];


    }

  }

  return matriz_transposta;

}

int is_symmetric(Matrix A){  // função para verificação de simetria de uma qualquer

	int i, j, x = 1;

	for(i = 0; i < A.num_linhas; i++){ 
	  
   		for(j = 0; j < A.num_colunas; j++){  

   			if(A.matriz[i][j] != A.matriz[j][i]){

   				x = 0;
   				break;

   			}

   		}
    
  	}

  	if(x == 0){
  	  printf("Matriz não simétrica\n");
  	}
  	else{
  	  
  	  printf("Matriz simétrica\n");
  	}
}



#endif