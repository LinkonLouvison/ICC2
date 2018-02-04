#include <stdio.h>
#define  MAX 10000


void bubble( int v[], int tam);

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
     bubble(vet,n_elementos);
    
    
    
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



 void bubble(int v[],int tam){
         int i,j,temp,flag;
         if(tam)
                 for(j=0;j<tam-1;j++){
                         flag=0;
                         for(i=0;i<tam-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }
