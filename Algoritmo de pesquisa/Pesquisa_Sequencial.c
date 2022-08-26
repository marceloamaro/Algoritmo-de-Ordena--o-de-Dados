#include <stdio.h>

int busca_sequencial(int n, int v[], int x){
	int k;
	for (k = n - 1; k >= 0 && v[k] != x; k--)
		;
	return k;
}

int main(){
	int vet[10] = {2, -1, 3, -5, -10, 8, 9, 7, -20, -8};
	int n = busca_sequencial(10, vet, 5);
	printf("%d", n);
	return 0;
}


