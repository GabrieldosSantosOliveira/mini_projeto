#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "poly.h"

#define MISSING_PARAM_ERROR 10
#define ERROR_OPEN_FILE 50

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
  int len = strlen(argv[1]);
  char *tmp = (char *)calloc(sizeof(char), len + 1);
  strcpy(tmp, argv[1]);
  char *pointer = argv[1];
  int power;
  double coef;
  char *token = strtok(argv[1], "+-");
  int i = 0;
  while (token != NULL)
  {
    int t = (token - pointer);
    if (i != 0)
    {
      t = (token - pointer) - 1;
    }

    sscanf(&tmp[t], "%lf%*c%*c%d", &coef, &power);

    poly->add(poly, power, coef);
    token = strtok(NULL, "+-");
    i++;
  }
  free(tmp);
  write_in_a_file(poly, file);
  fclose(file);
  delete_poly(poly);
  return 0;
}