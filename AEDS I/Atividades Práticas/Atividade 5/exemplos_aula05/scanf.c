#include <stdio.h>

int main () {
  
  char texto[50];

  /* Interrompe a leitura no primeiro espaço em branco */
  scanf ("%s", texto);
  printf ("%s\n", texto);

  return (0);
}
