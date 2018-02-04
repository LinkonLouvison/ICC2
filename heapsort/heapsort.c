#include <stdio.h>
#define  MAX 150000
void max_heapify(long int[],long int,long int);
void build_heap(long int[],long int);
void heapsort(long int[],long int);

int main(void) {    
  
	long int vet[MAX];
	long  int n_elementos;
	long  int i,ordem;
	
	
	//printf("entre com numero de elementos\n");
	scanf("%ld",&n_elementos); 
	scanf("%ld",&ordem); 
	
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%ld",&vet[i]);
}
     heapsort(vet,n_elementos);
    
    
    
	if(ordem == 0){
    	for (i=0; i<n_elementos; i++)
        	printf("%ld ",vet[i]);
        }

	if(ordem == 1){
		for(i = n_elementos-1; i>=0; i--)
			printf("%ld ", vet[i]);
		}
		
		
    return 0;    
}



void max_heapify(long int v[],long int i,long int tamanho_do_heap)
{ 
  long int esq, dir, maior, aux; 
  esq=2*i+1; 
  dir=2*i+2; 
  if ((esq<tamanho_do_heap) && (v[esq]>v[i]))
    maior=esq;
  else maior=i; 
  if ((dir<tamanho_do_heap) && (v[dir]>v[maior]))
    maior=dir; 
  if (maior!=i)
  { 
    aux=v[i];
    v[i]=v[maior];
    v[maior]=aux;
    max_heapify(v,maior,tamanho_do_heap); 
  } 
} 

void build_heap(long int v[],long int n) 
{ 
  long int i;
  for (i=n/2-1; i>=0; i--)
    max_heapify(v,i,n);
} 

void heapsort(long int v[], long int n) 
{ 
  long int i, aux, tamanho_do_heap;
  build_heap(v,n);
  tamanho_do_heap=n;
  for (i=n-1; i>0; i--) 
  { 
    aux=v[0];
    v[0]=v[i];
    v[i]=aux;
    tamanho_do_heap--; 
    max_heapify(v,0,tamanho_do_heap);
  }
} 
