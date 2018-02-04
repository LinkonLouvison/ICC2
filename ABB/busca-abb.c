#include <stdio.h>
#include <stdlib.h>
#define MAX 10000



typedef struct bloco {
        int info;
        int numero_elementos;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} BST;




//protótipos das funções
void criar(BST*);
void finalizar(no**);
void percurso_pre_ordem(no **);
void inserir(no**, int*);
int buscar(no**,int*);






int main(void) {       
    BST A;
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








void criar(BST *A) {
     A->raiz=NULL;
}


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



int buscar(no **p, int *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}


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


