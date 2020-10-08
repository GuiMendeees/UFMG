#include <stdio.h>
#include <stdlib.h>



int menor(int v[], int n){
    
       if (n==1) 
        return (v[0]);
       
       else {
               int aux;
               aux = menor (v, n-1);
               
               if (aux<v[n-1]) 
                return (aux);
                
               else 
               return (v[n-1]);
       }
       
}

int main(){
    

       int n,i;
       int *vetor;
       
       
       

	scanf("%d",&n);
	
	vetor = malloc(n * sizeof(int));
	
       for (i=0;i<n;i++) {
           
               scanf("%d",&vetor[i]);
       }
       
       
       printf("%d\n",menor(vetor,n));
       return 0;
}