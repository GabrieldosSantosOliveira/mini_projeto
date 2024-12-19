#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "poly.h"

#define MISSING_PARAM_ERROR 10
#define ERROR_OPEN_FILE 50

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Informe todos os parametros\n");
    return MISSING_PARAM_ERROR;
  }
  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  Poly *poly = new_poly();
  read_from_a_file(poly, file);
  print_poly(poly);
  fclose(file);
  delete_poly(poly);
  return 0;
}