#include <stdio.h>
#include <stdlib.h>

struct matriz{

  int linha;
  int coluna;
  float* valor;

};

typedef struct matriz Matriz;

Matriz* cria(int m, int n){

  Matriz* mat = (Matriz*)malloc(sizeof(Matriz));

  if (mat == NULL){
    printf("Memoria insuficiente!\n");
    exit(1);
  }
    
  mat->linha = m;
  mat->coluna = n;
  mat->valor = (float*)malloc(m*n*sizeof(float));

  return mat;

}

void libera(Matriz* mat){

  free(mat->valor);
  free(mat);

}

float acessa(Matriz* mat, int i, int j) {

  int k;

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {
    printf("Acesso invalido!\n");
    exit(1);
  }

  k = i * mat->coluna + j;

  return mat->valor[k];

}

void atribui(Matriz* mat, int i, int j, float valor) {

  int k;

  if (i < 0 || i >= mat->linha || j < 0 || j >= mat->coluna) {
    printf("Atribuicao invalida!\n");
    exit(1);
  }

  k = i * mat->coluna + j;

  mat->valor[k] = valor;

}

int linhas(Matriz* mat){

  return mat->linha;

}

int colunas(Matriz* mat){

  return mat->coluna;

}

int main(){

    Matriz* matriz_do_luiz;

    matriz_do_luiz = cria(4 , 5);
    
}
