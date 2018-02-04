#include <stdio.h>
#define  MAX 120000

long int separa (long int [],long  int ,long  int );
void quick (long int [],long  int ,long  int ); 


int main(){
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
     quick(vet,0, n_elementos-1);
    
    
    
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



long int separa (long int vet[],long  int p,long  int r){
  long  int c = vet[p], i = p+1, j = r, t;
   while ( i <= j) {
      if (vet[i] <= c) ++i;
      else if (c < vet[j]) --j; 
      else {
         t = vet[i], vet[i] = vet[j], vet[j] = t;
         ++i; --j;
      }
   }
   vet[p] = vet[j], vet[j] = c;
   return j; 
}

void quick (long int vet[],long  int p,long  int r) {
   long int i;
   while (p < r) {          
      i = separa (vet, p, r); 
      quick (vet, p, i-1);
      p = i + 1;            
   }
}
