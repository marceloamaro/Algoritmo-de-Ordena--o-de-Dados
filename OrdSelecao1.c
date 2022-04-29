#include <stdio.h>

void selection_sort (int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    /* O minimo � o primeiro n�mero n�o ordenado ainda */
    min = i;

    for (j = i+1; j < max; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) {
   min = j;
   
      }
    }
    /* Se o minimo for diferente do primeiro numero n�o ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
    }
  }
  /* Imprime o vetor ordenado */
  printf("\nValores ordenados:\n");
  for (i = 0; i < max; i++) {
    printf ("%d ",vetor[i]);
  }
  printf ("\n");
}

main () {
  int max, i;
  /* L� o m�ximo de algarismos do vetor*/
  printf("Digite o tamanho do vetor:  ");
  scanf ("%d",&max);
  
  int  vetor[max];
  /* L� os algarismos do vetor */
  printf("Digite os valores do vetor:\n ");
  for (i = 0; i < max; i++) {
    scanf ("%d",&vetor[i]);
  }
  
  selection_sort (vetor, max);
  
}
