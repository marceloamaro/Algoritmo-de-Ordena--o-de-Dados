#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
void merge (int *V, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio + 1;
	temp = (int *) malloc(tamanho *sizeof(int));
	if(temp != NULL){
		for(i = 0; i < tamanho; i++){
			if(!fim1 && !fim2){
				if(V[p1] < V[p2])
					temp[i] = V[p1++];
				else
					temp[i] = V[p2++];
				if(p1>meio)
					fim1 = 1;
				if(p2 > fim)
					fim2 = 1;
			}else{
				if(!fim1)
					temp[i] = V[p1++];
				else
					temp[i] = V[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			V[k] = temp[j];
		}
	}
	free(temp);
}
void mergesort(int *V, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim)/2);
		mergesort(V, inicio, meio);
		mergesort(V, meio+1, fim);
		merge(V, inicio, meio, fim);
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
 mergesort(vet, 0, 9);
 
 // Imprime os valores ordenados
 // Print values in order ascendant
 printf("Valores ordenados\n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d", vet[i]);
  printf("\n");
 }
 
 return 0;
}