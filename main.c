#include <stdio.h>
#include <stdlib.h>

int vetor_memoria [1024];
int aloc = 1;

void iniciaZero(){
  for (int i = 0; i < 1024; i++){
    vetor_memoria[i] = 0;
  }
}

int disponivelAloc(int nbytes){
  int disponievl = 1;
  for (int i = 0; i < 1024; i++){
    disponievl = 1;
    for (int j = i; j < nbytes + i; j++){
      if(i + nbytes > 1024){
        printf("Error:");
      }

      if (vetor_memoria[j] == 1){
        disponievl = 0;
      }

      if(disponievl == 1 && j == nbytes +i -1){
        return i;
      }
    }
  }
}

void realizaAlocacao(int posicao, int nbytes){
  for (int i = posicao; i < posicao+nbytes; i++){
    vetor_memoria[i] = aloc;
  }
  aloc ++;
}

void *aloca(int nbytes) {
  int p = disponivelAloc(nbytes);
  realizaAlocacao(p, nbytes);

  p =  &vetor_memoria[p];
  return p;  
}

void *desaloca(int Hash){
  for (int i = 0; i < 1024; i++){
    if(vetor_memoria[i]==Hash){
      vetor_memoria[i] = 0;
    }
  }
}

void desalocar(void *p) {
  int *ponteiro;
  ponteiro = p;
  printf(*ponteiro);
  desalocaMemoriaPeloHash(*ponteiro);
  printf(*ponteiro);

}