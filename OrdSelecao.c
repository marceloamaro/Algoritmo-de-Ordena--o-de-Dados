#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50 // Define o tamanho do vetor;

void fSelect_Sort(int *pVetor); // Declara a fun��o select sort;

int main()
{
    int vVetor[TAM]; // Declara o vetor
    int vAux;

    srand ( time(NULL) );
    for (vAux=0; vAux < TAM; vAux++)
    {
        vVetor[vAux] = (rand() % 89) + 10; // Preenche o vetor aleat�riamente;
        printf(" %d,",vVetor[vAux]);
    }

    fSelect_Sort(vVetor); // Chama a fun��o de Ordena��o;

    printf("\n\n");

    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %d,",vVetor[vAux]);
    }

    printf("\n\n ");
    system("pause");
    return 0;
}

void fSelect_Sort(int *pVetor)
{
    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for(vAux=0; vAux < TAM-1; vAux++) // Percorre todo o vetor at� TAM-1, pois a ultima posi��o n�o precisa testar pois ja estara ordenada;
    {
        vMenor = vAux; // Menor valor recebe a posi��o que est� passando;

        for (vTemp=vAux+1; vTemp < TAM; vTemp++) // Percorre o vetor da posi��o vAux+1 at� o final;
        {
            if (pVetor[vTemp] < pVetor[vMenor]) // Testa se a posi��o que est� passando � menor que o menor valor;
            {
                vMenor = vTemp; // vMenor recebe a posi��o do menor valor;
            }
        }

        if (vMenor != vAux) // Se a posi��o for diferente da que est� passando, ocorre a troca;
        {
            vTroca         = pVetor[vAux];
            pVetor[vAux]   = pVetor[vMenor];
            pVetor[vMenor] = vTroca;
        }
    }
}
