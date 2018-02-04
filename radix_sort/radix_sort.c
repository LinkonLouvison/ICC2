#include <stdio.h>
#include <stdlib.h>

#define  MAX 60000

void radix_sort( int[],int);

int main(void) {    
  
	int vet[MAX];
	int n_elementos;
	int i;
	
	//printf("entre com numero de elementos\n");
	scanf("%d",&n_elementos); 
	
	
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%d",&vet[i]);
}
     
    radix_sort(vet,n_elementos);
    for (i=0; i<n_elementos; i++)
        printf("%d ",vet[i]);
    return 0;    
}

void radix_sort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
