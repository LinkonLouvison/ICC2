#include<stdio.h>
#define tam_balde 1000
#define num_balde 1000
#define MAX 10000
 
 typedef struct {
         int topo;
         int balde[tam_balde];
 }balde;
 
 
void bucket_sort(int v[],int tam);
void rearranjar_heap(int[],int,int);
void construir_heap(int[],int);
void heapsort(int[],int);



int main(void) {    
  
	float vet_real[MAX];
	int n_elementos, vet_inteiro[MAX];
	int i;
	
	
	
/*Entrada de dados  	*/
	scanf("%d",&n_elementos); 
	for(i = 0; i<n_elementos; i++){
		scanf("%f",&vet_real[i]);
		vet_real[i] = vet_real[i] * 100000;
		vet_inteiro[i] = (float)vet_real[i];
}
     
/* convertendo os números para inteiro */



bucket_sort(vet_inteiro,n_elementos);










/* voltando eles para float  */

   	for(i = 0; i<n_elementos; i++){
   		vet_real[i] = (int)vet_inteiro[i];
		vet_real[i] = vet_real[i]/100000;
		
}


/*
// imprimindo o vetor transformado como inteiro para o bucket-sort
     for (i=0; i<n_elementos; i++)
        printf("%d ",vet_inteiro[i]);
     printf("\n");
*/
    
    
    // saida dos elementos 
    for (i=0; i<n_elementos; i++)
        printf("%.4f ",vet_real[i]);
        
    getchar();
    return 0;    
}

void bucket_sort(int v[],int tam){
     balde b[num_balde];
     int i,j,k;
     for(i=0;i<num_balde;i++)
             b[i].topo=0;
 
     for(i=0;i<tam;i++){
             j=(num_balde)-1;
             while(1){
                     if(j<0)
                             break;
                     if(v[i]>=j*num_balde){
                             b[j].balde[b[j].topo]=v[i];
                             (b[j].topo)++;
                             break;
                     }
                     j--;
             }
     }
 
     for(i=0;i<num_balde;i++)
             if(b[i].topo)
             		   heapsort(b[i].balde,b[i].topo);
 
     i=0;
     for(j=0;j<num_balde;j++){
             for(k=0;k<b[j].topo;k++){
                     v[i]=b[j].balde[k];
                     i++;
             }
     }
 }
 
 
void rearranjar_heap(int v[], int i, int tamanho_do_heap)
{ 
  int esq, dir, maior, aux; 
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
    rearranjar_heap(v,maior,tamanho_do_heap); 
  } 
} 

void construir_heap(int v[], int n) 
{ 
  int i;
  for (i=n/2-1; i>=0; i--)
    rearranjar_heap(v,i,n);
} 

void heapsort(int v[], int n) 
{ 
  int i, aux, tamanho_do_heap;
  construir_heap(v,n);
  tamanho_do_heap=n;
  for (i=n-1; i>0; i--) 
  { 
    aux=v[0];
    v[0]=v[i];
    v[i]=aux;
    tamanho_do_heap--; 
    rearranjar_heap(v,0,tamanho_do_heap);
  }
} 
