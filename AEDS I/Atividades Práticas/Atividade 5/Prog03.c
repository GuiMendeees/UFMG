#include <stdio.h>

// Se o I != J    E M[i][j] == M [i][j]

int main () {

int i,j; /* linha e coluna matriz */
int matriz [4][4];

    for (i=0; i<4; i++){
    	
        for (j=0; j<4; j++)
            scanf ("%d", &matriz[i][j]);
      }

    if ((i != j) && (matriz [i][j] == matriz [j][i]))
        printf ("Matriz simetrica");

    else
        printf ("Nao e uma matriz simetrica");

return 0;

}
