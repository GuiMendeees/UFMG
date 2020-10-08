
#include <stdio.h>

#include <math.h>



float Calcular_vf (float vzero, float acel, float temp){
    
	return (vzero+(acel*temp));

}



float calcular_distancia (float vzero, float temp, float acel){
    
	return ((vzero*temp)+((acel/2)*pow(temp,2)));

}



int main(){
    

float a,v,t,vf,s ;

    

	scanf("%f %f %f", &v, &a, &t );
    
   

	vf = Calcular_vf (v,a,t);
   
		printf ("Velocidade final: %.2f\n", vf);
    
   
	
	s = calcular_distancia (v,t,a);
   
		printf ("Distancia percorrida: %.2f\n", s);
    


return 0;
    

}