#include <stdio.h>
#include <stdlib.h>

#define  MAX 140000


int main(void) {    
  
	long long int vet[MAX];
	long long int n_elementos;
	long long int i;
	long long int maior,aux[MAX],exp;
	
	//entrada de dados
	//printf("entre com numero de elementos\n");
	scanf("%lld",&n_elementos); 
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%lld",&vet[i]);
}
     
     
     
     
/*           Radix-Sort                                    */
    
    maior = vet[0];
    exp = 1;
    for (i = 0; i < n_elementos; i++) {
        if (vet[i] > maior)
    	    maior = vet[i];
    }
 
    while (maior/exp > 0) {
        long long int bucket[10] = { 0 };
    	for (i = 0; i < n_elementos; i++)
    	    bucket[(vet[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = n_elementos - 1; i >= 0; i--)
    	    aux[--bucket[(vet[i] / exp) % 10]] = vet[i];
    	for (i = 0; i < n_elementos; i++)
    	    vet[i] = aux[i];
    	exp *= 10;
    }

    
    
    
    //saida de dados 
    for (i=0; i<n_elementos; i++)
        printf("%lld ",vet[i]);
    return 0;    
}

   
