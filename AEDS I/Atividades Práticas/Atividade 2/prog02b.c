/* Atividade II
    Aeds 1
    Aluno: Guilherme Mendes de Oliveira */

    #include <stdio.h>

    int main(){

    int a = 10.7;
    int b = 3.02;
    int c;
    c = a+b;

    printf("C= %d\n", c);

    c = a-b;

    printf("C= %d\n", c);

    int valor = 15;
    int divisor = 4;
    int resultado = valor/divisor;

    printf ("resultado= %d\n",resultado);

    return 0;

    }

/* Na outra atividade o resultado apresentava casas decimais devido a variável  double armazenar ja o tipo INT não armazena
a divisão não é exata portanto deveria ter casa decimal, mas a variável INT só armazena valor inteiro */
