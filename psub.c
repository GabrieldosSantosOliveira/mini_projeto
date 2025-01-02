#include <stdio.h>
#include "poly.h"
#include "errors_code.h"

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    printf("Informe todos os parametros\n");
    return MISSING_PARAM_ERROR;
  }
  FILE *p1file = fopen(argv[1], "r");
  FILE *p2file = fopen(argv[2], "r");
  FILE *destino = fopen(argv[3], "w");

  if (p1file == NULL || p2file == NULL || destino == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  Poly *p1 = new_poly();
  Poly *p2 = new_poly();
  Poly *dest = new_poly();

  read_from_a_file(p1, p1file);
  read_from_a_file(p2, p2file);
  sub(p1, p2, dest);

  write_in_a_file(dest, destino);
  fclose(destino);
  fclose(p1file);
  fclose(p2file);
  delete_poly(p1);
  delete_poly(p2);
  delete_poly(dest);

  return 0;
}