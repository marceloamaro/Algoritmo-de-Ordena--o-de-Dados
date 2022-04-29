#include<stdio.h>
#include<string.h>

void bolha(char *item, int total_elem) {
int a,b;
char t;

for(a=1;a<total_elem;++a)
for(b=total_elem-1;b>=a;--b)
  {
    if(item[b-1]>item[b])
      {
        /* se item[b-1]>item[b] troca os elementos*/
       t=item[b-1];
       item[b-1]=item[b];
       item[b]=t;
     } //fim do if
 } //fim do for
 
 }//fim da função void bolha
int main()
{
 int numeros[80];
 printf("Digite os numeros para ordenar: \n");
 gets(numeros);
 bolha(numeros,strlen(numeros));
 printf(" Numeros ordenadas : %s",numeros); 
 
 return 0;
}
