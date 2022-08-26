#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};
ArvBin* cria(){
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}
void libera(struct NO* no){
    if(no == NULL){
        return;
    }
    libera(no->esq);
    libera(no->dir);
    free(no);
    no = NULL;
}
void libera_raiz(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    libera(*raiz);
    free(raiz);
}
int inserir(ArvBin *raiz , int v){
    if(raiz == NULL){
        return 0;
    }
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = v;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(v == atual->info){
                free(novo);
                return 0;
            }
            if(v > atual->info){
                atual = atual->dir;
            }
            else
            {
                atual = atual->esq;
            }
            
        }
        if(v > ant->info){
            ant->dir = novo;
        }
        else
        {
            ant->esq = novo;
        }
        
    }
    return 1;
}
void preOrdem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n" , (*raiz)->info);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}
void Ordem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem(&((*raiz)->esq));
        printf("%d\n" , (*raiz)->info);
        preOrdem(&((*raiz)->dir));
    }
}
void posOrdem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
        printf("%d\n" , (*raiz)->info);
    }
}
int remove_arv(ArvBin* raiz , int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            *raiz = remover(atual);
        }
        else{
            if(ant->dir == atual){
                ant->dir = remover(atual);
            }
            else
            {
                ant->esq = remover(atual);
            }
        }
        return 1;
    }
    ant = atual;
    if(valor > atual->info){
        atual = atual->dir;
    }
    else
    {
        atual = atual->esq;
    }
}
struct NO* remover(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int consultar(ArvBin *raiz , int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }
        else
        {
            atual = atual->esq;
        }
        
    }
    return 0;
}


int main(){
    ArvBin *b = cria();
    inserir(b,10);
    inserir(b,9);
    inserir(b,12);
    inserir(b,6);
    inserir(b,5);
    inserir(b,7);
    inserir(b,1);
    inserir(b,8);
    preOrdem(b);
    
    printf("Consultar \n");
    int a = consultar(b, 5);
    printf("%d", a);
    
}
