#include <stdio.h>
#include <stdlib.h>
#define MAX 10000



typedef struct bloco {
        int info;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} ABB;




//protótipos das funções
void criar(ABB*);
void finalizar(no**);
void percurso_pre_ordem(no **);
void imprimir(no**);
void inserir(no**, int*);
int remover(no**,int*);
int buscar(no**,int*);






int main(void) {       
    ABB A;
    int i,n_elementos, vet[MAX], resposta, busca;
    
    
    
    
    criar(&A);
   
    // Entrada de dados 
   //printf("entre com numero de elementos\n");
	scanf("%d",&n_elementos); 
	
	
	//printf("entre com os elementos\n");
	for(i = 0; i<n_elementos; i++){
		scanf("%d",&vet[i]);
		inserir(&A.raiz,&vet[i]);
}
     
     // salvo o elemento que desejo buscar 
     scanf("%d",&busca);
     
     
     
     resposta = buscar(&A.raiz,&busca);
     
     if(resposta == 1){
     	printf("elemento encontrado");}
     else{
     	printf("elemento nao encontrado");}
     
   
   //percurso_pre_ordem(&A.raiz);
   
    
    
    finalizar(&A.raiz);
	getchar();
    return 0;
}







//função para criar/inicializar a árvore de busca binária
void criar(ABB *A) {
     A->raiz=NULL;
}

//função para finalizar árvore de busca binária; deve começar com p=raiz
void finalizar(no **p) {
     if (*p!=NULL) {
        finalizar(&(*p)->esq);
        finalizar(&(*p)->dir);
        free(*p);
     }
}



//função de percurso de pre-ordem na árvore = busca em profundidade
void percurso_pre_ordem(no **p) {
    if (*p != NULL){
        printf("%d ",(*p)->info);
        percurso_pre_ordem(&(*p)->esq);
        percurso_pre_ordem(&(*p)->dir);
    }
}


//imprime os elementos da árvore
void imprimir(no **p) {
     if (*p!=NULL) {
        printf("%d(",(*p)->info);
        imprimir(&(*p)->esq);
        printf(",");
        imprimir(&(*p)->dir);
        printf(")");
     }
     else printf("null");
}

//função de busca de um elemento na árvore binária de busca; deve começar com p=raiz
int buscar(no **p, int *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}

//função de inserção de um elemento na árvore binária de busca; deve começar com p=raiz
void inserir(no **p, int *x) {
     if (*p==NULL) {
        *p=(no*) malloc(sizeof(no));
        (*p)->info=*x;
        (*p)->esq=NULL;
        (*p)->dir=NULL;
     }
     else if (*x<(*p)->info)
          return(inserir(&(*p)->esq,x));
     else if (*x>=(*p)->info)
          return(inserir(&(*p)->dir,x));
     
}

//função que retorna o maior elemento de uma subarvore com raiz em p
int busca_maior(no **p) {
     no *aux;
     aux=*p;
     while (aux->dir!=NULL)
           aux=aux->dir;
     return(aux->info);
}

//função que remove um elemento de uma árvore
int remover(no **p, int *x) {
    no *aux;
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(remover(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(remover(&(*p)->dir,x));
    else {
         //caso 1: o nó não tem filhos
         if (((*p)->esq==NULL) && ((*p)->dir==NULL)) {
            free(*p);
            *p=NULL;
            return 1;
         }
         //caso 2a: só há o filho direito
         else if ((*p)->esq==NULL) {
              aux=*p;
              *p=(*p)->dir;
              free(aux);
              return 1;
         }
         //caso 2b: só há o filho esquerdo
         else if ((*p)->dir==NULL) {
              aux=*p;
              *p=(*p)->esq;
              free(aux);
              return 1;
         }
         //caso 3: há os dois filhos
         else {
              (*p)->info=busca_maior(&(*p)->esq);
              return(remover(&(*p)->esq,&(*p)->info));
         }
    }
}
