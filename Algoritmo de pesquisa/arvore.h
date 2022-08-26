typedef struct NO* ArvBin;

ArvBin* cria();

void libera(struct NO* no);

void libera_raiz(ArvBin* raiz);

int inserir(ArvBin *raiz , int v);

void preOrdem(ArvBin *raiz);

void Ordem(ArvBin *raiz);

void posOrdem(ArvBin *raiz);

int remove_arv(ArvBin* raiz , int valor);

struct NO* remover(struct NO* atual);

int consultar(ArvBin *raiz , int valor);


