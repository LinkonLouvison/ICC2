#include <stdlib.h>
#include <stdio.h>
#include <time.h>


unsigned long long int fibonacci_iterativo (int n)
{
				  int i = 0;
				  int j = 1;
	
				  for (int k = 1; k < n; k++)
				  {	
					int t;
					t = i + j;
					i = j;
					j = t;
				  }

	return j;
	
};

unsigned long long int fibonacci_recursivo(int n)
{
				  if (n <= 2)
	
				     return 1;
								
				  else 
							
 return fibonacci_recursivo(n-2) + fibonacci_recursivo(n-1);
};

void imprimirRecursivo (int n)
{
	for (int i = 0; i < n; i++)
	{
		
		printf("%d  %llu\n",i+1 ,fibonacci_recursivo(i));
	
			
	}	
}
	
	void imprimirIterativo (int n)
{
	for (int i = 0; i < n; i++)
	{
		
		printf("%d   %llu\n",i+1 , fibonacci_iterativo(i));
			
	}	
	
	
	
	
	
}



int main(){
   int n ;
   
   printf("Entre com o numero de elementos da serie\n");
   scanf("%d",&n);   
   clock_t inicio, fim;
	inicio= clock();

   imprimirRecursivo(n);
   imprimirIterativo(n);
   fim= clock();
	printf("%lf",((double)(fim - inicio)/CLOCKS_PER_SEC));
   getchar();
}


