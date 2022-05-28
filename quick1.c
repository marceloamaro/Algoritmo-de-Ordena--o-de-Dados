#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

int particiona(int *V, int inicio, int final){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = V[inicio];
	while(esq < dir){
		while(V[esq] <= pivo)
			esq++;
		while(V[dir] > pivo)
			dir--;
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

void quicksort(int *V, int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona(V, inicio, fim);
		quicksort(V, inicio, pivo-1);
		quicksort(V, pivo+1, fim);
	}
}

int main(int argc, char** argv){
 int i, vet[MAX];
 
 // Lê MAX ou 10 valores
 // Read MAX or 10 values
 for(i = 0; i < MAX; i++){
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 // Ordena os valores
 // Order values
 quicksort(vet,0,9);
 
 // Imprime os valores ordenados
 // Print values in order ascendant
 printf("Valores ordenados\n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d", vet[i]);
  printf("\n");
 }
 system("pause");
 return 0;
}