// Criptografia RSA - Guilherme Mendes de Oliveira - AEDS I


// Funçao de entrada dos numeros primos

long int VerificaPrimos (long primo){
	long int i;
	long int divisores = 0; //(Contador de Divisor)
	long int ValidaPrimo;


	for (i=1;i <= primo; i++){
		if (primo % i == 0)
		divisores++; // Conta numero de divisores
}
	if (divisores == 2)
		return 1; // É primo
	else {
		return 0; // Não é primo
	}

}

long int CalculaN (long int primo1, long int primo2){

		long int n;

		n = (primo1*primo2);
		//printf("%lu\n",n);
}

long int CalculaQ (long int primo1, long int primo2){

		long int totiente;

		totiente = ((primo1-1)*(primo2-1));
		//printf("%lu\n",q);
}

long int AchaCoPrimo (long int i, long int totiente ){ // i candidato a coprimo --- q é o totiente

    long int resto;

    do {

     	resto = totiente % i;
        totiente = i;
        i = resto;

 }
 	while (resto != 0);
	return i;

}


long int CalculaE (long int totiente, long int primo1, long int primo2){

long int  i, e;
	for(i = 2; i < totiente; i++){

		if(totiente%i != 0 && VerificaPrimos(i) && i != primo1 && i != primo2){ // Considerei que o e teria que ser primo porque ele só teria de divisor ele mesmo e se não fosse divisor o totiente serveria
			e = i;
			break;
		}
	}

	return e;
}


long int CalculaD (long int e, long int totiente) {// Numero que multiplicado por e seu resultado mod totiente = 1
	long int d;
	long int i;
		for (i = 0; i < totiente; i++){
			if ((i*e) %totiente ==1)
				d=i;
		}

	return d;

}

long double Criptografia (long int e/*Chave*/,long int n, int Valor /*STR Convertida em ascii*/){

 long double c=1; // recebe o valor criptografado
 int i;
        for (i=0; i < e; i++){
                c = ((int)(Valor*c)% n);
}

return c;

}