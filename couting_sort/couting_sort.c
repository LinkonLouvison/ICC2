#include <stdio.h>
#define  MAX 60000

void couting_sort( int[],int);

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
     
    couting_sort(vet,n_elementos);
    for (i=0; i<n_elementos; i++)
        printf("%d ",vet[i]);
    getchar();
    return 0;    
}

void couting_sort( int v[], int n)
{
     int X[n], B[n], i, j;

     for (i=0; i<n; i++)  //inicializando arranjo auxiliar
         X[i]=0;

     for (i=1; i<n; i++)  //contando menores
         for (j=i-1; j>=0; j--)
             if (v[i]<v[j])
                X[j]++;
             else X[i]++;

     for (i=0; i<n; i++)  //montando arranjo final
         B[X[i]]=v[i];

     for (i=0; i<n; i++)  //copiando arranjo final para original
         v[i]=B[i];
}
