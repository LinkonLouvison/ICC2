#include<stdio.h>
#define tam_balde 1000
#define num_balde 10
#define MAX 1000
 
 typedef struct {
         int topo;
         int balde[tam_balde];
 }balde;
 
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
                             (b[j].topo)++;
                             break;
                     }
                     j--;
             }
     }
 
     for(i=0;i<num_balde;i++)
             if(b[i].topo)
                     bubble(b[i].balde,b[i].topo);
 
     i=0;
     for(j=0;j<num_balde;j++){
             for(k=0;k<b[j].topo;k++){
                     v[i]=b[j].balde[k];
                     i++;
             }
     }
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
		vet_real[i] = vet_real[i] * 10000;
		vet_inteiro[i] = (float)vet_real[i];
}




bucket_sort(vet_inteiro,n_elementos);










/* voltando eles para float  */

   	for(i = 0; i<n_elementos; i++){
   		vet_real[i] = (int)vet_inteiro[i];
		vet_real[i] = vet_real[i]/10000;
		
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

