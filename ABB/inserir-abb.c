#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


typedef int elem;

typedef struct bloco {
        elem info;
        int numero_elementos;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} BST;






void criar(BST*);
void finalizar(no**);
void percurso_pre_ordem(no **);
void inserir(no**,elem*);






int main(void) {       
    BST A;
    int i,n_elementos, vet[MAX];
    
    
    
    
    criar(&A);
   
    // Entrada de dados 
   //printf("entre com numero de elementos\n");
	scanf("%d",&n_elementos); 
	
	
	//printf("entre com os elementos\n");
	for(i = 0; i<n_elementos; i++){
		scanf("%d",&vet[i]);
		inserir(&A.raiz,&vet[i]);
}
     
     
     
     
   
   percurso_pre_ordem(&A.raiz);
   
    
    
    finalizar(&A.raiz);
	getchar();
    return 0;
}







//função para criar/inicializar a árvore de busca binária
void criar(BST *A) {
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




void percurso_pre_ordem(no **p) {
    if (*p != NULL){
        printf("%d ",(*p)->info);
        percurso_pre_ordem(&(*p)->esq);
        percurso_pre_ordem(&(*p)->dir);
    }
}



//função de inserção de um elemento na árvore binária de busca; deve começar com p=raiz
void inserir(no **p, elem *x) {
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


