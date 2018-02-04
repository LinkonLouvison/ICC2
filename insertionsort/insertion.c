  
  
  #include <stdio.h>
#define  MAX 10000


void insertion(int vet[], int n);

int main(void) {    
  
	 int vet[MAX];
	  int n_elementos;
	  int i,ordem;
	
	
	//printf("entre com numero de elementos\n");
	scanf("%d",&n_elementos); 
	scanf("%d",&ordem); 
	
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%d",&vet[i]);
}
     insertion(vet,n_elementos);
    
    
    
	if(ordem == 0){
    	for (i=0; i<n_elementos; i++)
        	printf("%d ",vet[i]);
        }

	if(ordem == 1){
		for(i = n_elementos-1; i>=0; i--)
			printf("%d ", vet[i]);
		}
		
		
    return 0;    
}


void insertion(int vet[], int n) {
     int i, j, aux;
     for (i=1; i<n; i++) {
         aux=vet[i];
         j=i-1;
         while ((j>=0) && (aux<vet[j])) {
               vet[j+1]=vet[j];
               j--;
         }
         vet[j+1]=aux;
     }

}



