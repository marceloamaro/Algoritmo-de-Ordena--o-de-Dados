#include <stdio.h>
#include <stdlib.h>
 
// Define uma constante

#define MAX 10
 
// Prot�tipo da fun��o de ordena��o

void insertion_sort(int *a);
 
// Fun��o main

int main(int argc, char** argv)
{
 int i, vet[MAX];
 
 // L� MAX ou 10 valores

 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 // Ordena os valores
 
 insertion_sort(vet);
 
 // Imprime os valores ordenados
 
 printf("\n Valores ordenados \n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d\n", vet[i]);
 }
 system("pause");
 return 0;
}
 
// Fun��o de Ordena��o por Inser��o

void insertion_sort(int *a)
{
 int i, j, tmp;
  // pivor i come�a na posi�ao 1
 for(i = 1; i < MAX; i++)
 {
  tmp = a[i];
  for(j = i-1; j >= 0 && tmp < a[j]; j--)
  {
   a[j+1] = a[j];
  }
  a[j+1] = tmp;
 }
}

