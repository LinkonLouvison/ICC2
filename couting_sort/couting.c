#include <stdio.h>
#define  MAX 140000


int main(void) {    
  
	long int vet[MAX], B[MAX];
	 long int n_elementos;
	 long int i,j,max;
	
	//printf("entre com numero de elementos\n");
	scanf("%ld",&n_elementos); 
	
	
	//printf("entre com os elementos\n");
for(i = 0; i<n_elementos; i++){
	scanf("%ld",&vet[i]);
}
     
     
     max=vet[0];  
     for (i=1; i<n_elementos; i++)
         if (vet[i]>max)
            max=vet[i];
     long int X[max+1];
     

     for (i=0; i<max+1; i++)
         X[i]=0;


     for (i=0; i<n_elementos; i++)
         X[vet[i]]++;


     j=0;
     for (i=0; i<max+1; i++)
         while (X[i]!=0) {
               B[j]=i;
               j++;
               X[i]--;
         }


     for (i=0; i<n_elementos; i++)
         vet[i]=B[i];
    
    
    
    for (i=0; i<n_elementos; i++)
        printf("%ld ",vet[i]);
    return 0;    
}



