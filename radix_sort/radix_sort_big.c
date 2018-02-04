#include <stdio.h>
#include <stdlib.h>

#define  MAX 140000

void radix_sort( long long int[], long long int);

int main(void) {    
  
	long long vet[MAX];
	long long n_elementos;
	long long i;
	
	//printf("entre com numero de elementos\n");
	scanf("%lld",&n_elementos); 
	
	
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%lld",&vet[i]);
}
     
    radix_sort(vet,n_elementos);
    for (i=0; i<n_elementos; i++)
        printf("%lld ",vet[i]);
    return 0;    
}

void radix_sort(long long  int vetor[], long long int tamanho) {
    long long int i, *b, maior = vetor[0], exp =1;
   

    b = (long long int *)calloc(tamanho, sizeof(long long int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        long long int bucket[10] = { 0 };
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
