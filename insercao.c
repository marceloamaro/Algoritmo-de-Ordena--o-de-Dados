#include <stdio.h>
#include <string.h>

void inserction(char *p, int caracs);

int main()
{
    char s[10];
    printf("Digite uma string:\n");
    scanf("%10[^\n]", s);
    printf("--------------------------------------------------------------\n");
    printf("String antes de ser ordenada por Insercao\n\t%s\n", s);
    inserction(s, strlen(s));
    printf("String depois de ser ordenada por Insercao\n\t%s\n", s);
    return 0;
}

void inserction(char *p, int caracs)
{
    for(int i=0; i<caracs-1; i++)// controlador da posi��o atual do vetor
    {
        for(int j=i+1; j<caracs; j++)// controlador da posi��o sucessora da atual posi��o
        {
            if(p[j] < p[i])// compara��o da a posi��o atual com o seu sucessor. Caso V, declara uma
                           //vari�vel tempor�ria e faz as trocas
            {
                char t;
                t = p[i];
                p[i] = p[j];
                p[j] = t;
                if(i >= 1 && p[i] < p[i-1])//come�o da compara��o com o antecessor. Caso V, faz as trocas
                {
                    t = p[i-1];
                    p[i-1] = p[i];
                    p[i] = t;
                }
            }
        }
    }
}
