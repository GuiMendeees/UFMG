
#include <stdio.h>
#include <math.h>



float pi = 3.1415;


float calcular_perimetro (float r){
    return (2*pi*r); 
    

}
    

float calcular_area (float r){
    
	return (pi*(pow (r,2)));
    

}
    


float calcular_volume (float r){
    
	return (4*pi*(pow (r,3))/3);
    

}
    



int main(){
    

float r, v;

    
	printf("Raio: ");
    
	scanf("%f", &r);
   
	
	v = calcular_perimetro(r);
    
	printf("Perimetro: %.2f\n", v);
  

  
    	v = calcular_area(r);
    
	printf("Area: %.2f\n", v);
    
    
	
	v = calcular_volume(r);
    
	printf("Volume: %.2f\n", v);
    
    
    
    
    


return 0;

}