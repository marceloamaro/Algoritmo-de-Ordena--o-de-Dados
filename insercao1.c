#include <stdio.h>
#include <string.h>

void insert(char *item, int count);

int main()
{
    char s[10];
    printf("Digite uma string:\n");
    scanf("%10[^\n]", s);
    printf("---------------------------------------------------\n");
    printf("String antes de ser ordenado por insercaoo: %s\n", s);
    insert(s, strlen(s));
    printf("\nString depois de ser ordenado por insercao: %s\n", s);
    return 0;
}

void insert(char *item, int count)
{
    int a, b;
    char t;
    for(a=1; a<count; ++a)
    {
        t = item[a];
        for(b=a-1; b>=0 && t<item[b]; b--)
        {
            item[b+1] = item[b];
        }
        item[b+1] = t;
    }
}
