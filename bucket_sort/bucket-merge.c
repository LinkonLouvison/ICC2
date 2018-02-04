#include<stdio.h>
#define tam_balde 1000
#define num_balde 10
#define MAX 1000



//struct para representar cada balde do algoritmo, 
 typedef struct {
         int topo;
         int inicio;
         int balde[tam_balde];
 }balde;
 
 
void mergesort(int[], int, int);
void intercala(int[], int, int, int);
void bucket_sort(int v[],int tam);


int main(void) {    
  
	float vet_real[MAX];
	int n_elementos, vet_inteiro[MAX];
	int i;
	
	
	
/*Entrada de dados  	*/
	scanf("%d",&n_elementos); 
	for(i = 0; i<n_elementos; i++){
		scanf("%f",&vet_real[i]);
}
     
/* convertendo os números para inteiro */

   	for(i = 0; i<n_elementos; i++){
		vet_real[i] = vet_real[i] * 100000;
		vet_inteiro[i] = (float)vet_real[i];
}




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
                     if(v[i]>=j*10){
                             b[j].balde[b[j].topo]=v[i];
                             b[0].balde[b[0].inicio]=v[i];
                             (b[j].topo)++;
                             break;
                     }
                     j--;
             }
     }
 
     for(i=0;i<num_balde;i++)
             if(b[i].topo)
                     mergesort(b[i].balde,b[i].inicio,b[i].topo);
 
     i=0;
     for(j=0;j<num_balde;j++){
             for(k=0;k<b[j].topo;k++){
                     v[i]=b[j].balde[k];
                     i++;
             }
     }
 }
 


void mergesort(int v[], int ini, int fim) {
     int meio;
     if (ini<fim) {     //se há mais de um elemento
        meio=(ini+fim)/2;
        mergesort(v,ini,meio);
        mergesort(v,meio+1,fim);
        intercala(v,ini,meio,fim);
     }
}

void intercala(int v[], int ini, int meio, int fim) {
     int i, j, k, n1, n2;

     //calculando tamanho dos subarranjos
     n1=meio-ini+1;
     n2=fim-meio;
     
     //declarando subarranjos que serão intercalados
     int L[n1+1], R[n2+1];
     
     //iniciando subarranjos a partir de v
     for (i=0;i<n1;i++)
         L[i]=v[ini+i];
     L[n1]=9999;         //inserindo sentinela
     for (j=0;j<n2;j++)
         R[j]=v[meio+j+1];
     R[n2]=9999;         //inserindo sentinela
     
     //intercalando arranjos
     i=j=0;
     for (k=ini;k<=fim;k++)
         if (L[i]<=R[j]) {
            v[k]=L[i];
            i++;
         }
         else {
              v[k]=R[j];
              j++;
         }    
}
