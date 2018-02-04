#include <stdio.h>
#define  MAX 120000

void merge(long int[],long  int,long int);
void intercala(long int[],long int,long int, long int);





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
     merge(vet,0, n_elementos-1);
    
    
    
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






void merge(long int v[],long int inicio,long int fim) {
     long int meio;
     if (inicio<fim) {     
        meio=(inicio+fim)/2;
        merge(v,inicio,meio);
        merge(v,meio+1,fim);
        intercala(v,inicio,meio,fim);
     }
}

void intercala(long int v[],long  int inicio,long int meio,long int fim) {
   long  int i, j, k, n1, n2;


     n1=meio-inicio+1;
     n2=fim-meio;
     

     long int L[n1+1], R[n2+1];
     

     for (i=0;i<n1;i++)
         L[i]=v[inicio+i];
     L[n1]=MAX;         
     for (j=0;j<n2;j++)
         R[j]=v[meio+j+1];
     R[n2]=MAX;         
     
     

     i=j=0;
     for (k=inicio;k<=fim;k++)
         if (L[i]<=R[j]) {
            v[k]=L[i];
            i++;
         }
         else {
              v[k]=R[j];
              j++;
         }    
}
