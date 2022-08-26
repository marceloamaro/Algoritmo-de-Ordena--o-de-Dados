#include <stdio.h>

#define TAM 10

int buscaBinaria(int vet[TAM], int item){
    int inicio = 0;
    int fim = TAM - 1;
    while (inicio <= fim) {  /* Condi��o de parada */
        int i = (inicio + fim) / 2;  /* Calcula o meio do sub-vetor */
        if (vet[i] == item) {  /* Item encontrado */
            return i;
        }
        if (vet[i] < item) {  /* Item est� no sub-vetor � direita */
            inicio = i + 1;
        } else {  /* vector[i] > item. Item est� no sub-vetor � esquerda */
            fim = i;
        }
    }
    return -1;
}

int main(){
	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = buscaBinaria(vet, 5);
	printf("%d", n);
	return 0;
}


