#include <stdio.h>
#include "poly.h"
#include "errors_code.h"

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    printf("Informe todos os parametros\n");
    return MISSING_PARAM_ERROR;
  }
  FILE *file = fopen(argv[2], "w");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
    return ERROR_OPEN_FILE;
  }
  Poly *poly = new_poly();
  char *tmp = argv[1];
  int power;
  double coef;
  while (*tmp != '\0')
  {
    sscanf(tmp, "%lf%*c%*c%d", &coef, &power);
    poly->add(poly, power, coef);
    tmp++;
    while ((*tmp != '\0') && (*tmp != '+' && *tmp != '-'))
    {
      tmp++;
    }
  }
  write_in_a_file(poly, file);
  fclose(file);
  delete_poly(poly);
  return 0;
}