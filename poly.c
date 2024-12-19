#include <stdio.h>
#include "poly.h"
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE sizeof(this->code) + sizeof(this->p)
#define ID_FILE "poly"
void add(Poly *this, int power, double coef);
void write_in_a_file(Poly *, FILE *);

Poly *new_poly()
{
  Poly *poly = (Poly *)malloc(sizeof(Poly) * 1);
  strcpy(poly->code, ID_FILE);
  poly->coef = (double *)calloc(sizeof(double), 1);
  poly->p = 0;
  poly->add = add;
  return poly;
}
void add(struct poly *const this, int power, double coef)
{
  if (power > this->p)
  {

    this->coef = (double *)realloc(this->coef, sizeof(double) * (power + 1));
    if (this->coef == NULL)
    {
      printf("ERRO AO ALOCAR MEMORIA\n");
      exit(-10);
    }
    this->p = power;
  }
  this->coef[power] = coef;
};
void print_poly(Poly *poly)
{
  for (int i = 0; i <= poly->p; i++)
  {
    printf("%+.2lfx^%d", poly->coef[i], i);
  }
  printf("\n");
}
void print_poly_debug(Poly *poly)
{

  printf("Code: %s\n", poly->code);
  printf("Potencia: %d\n", poly->p);
  for (int i = 0; i <= poly->p; i++)
  {
    printf("%.2lfx^%d  ", poly->coef[i], i);
  }
  printf("\n");
}

void delete_poly(Poly *poly)
{
  if (poly->coef != NULL)
  {
    free(poly->coef);
  }
  free(poly);
}
size_t size(Poly *this)
{
  return sizeof(this->code) + sizeof(this->p) + (sizeof(this->coef) * (this->p + 1));
}

void write_in_a_file(Poly *this, FILE *file)
{
  fwrite(this->code, sizeof(char), ID_SIZE, file);
  fwrite(&(this->p), sizeof(int), 1, file);
  fwrite(this->coef, sizeof(double), (this->p + 1), file);
}

void read_from_a_file(Poly *this, FILE *file)
{
  fread(this->code, sizeof(char), ID_SIZE, file);
  fread(&(this->p), sizeof(int), 1, file);
  this->coef = calloc(sizeof(double), (this->p + 1));
  fread(this->coef, sizeof(double), (this->p + 1), file);
}
void sum(const Poly *const p1, const Poly *const p2, Poly *const dest)
{
  int max = p2->p;

  if (p1->p > p2->p)
  {
    max = p1->p;
  }
  for (int i = 0; i <= max; i++)
  {
    double k = 0;
    double x = 0;

    if (i <= p1->p)
    {
      k = p1->coef[i];
    }
    if (i <= p2->p)
    {
      x = p2->coef[i];
    }
    dest->add(dest, i, (k + x));
  }
}

void sub(const Poly *const p1, const Poly *const p2, Poly *const dest)
{
  int max = p2->p;

  if (p1->p > p2->p)
  {
    max = p1->p;
  }
  for (int i = 0; i <= max; i++)
  {
    double k = 0;
    double x = 0;

    if (i <= p1->p)
    {
      k = p1->coef[i];
    }
    if (i <= p2->p)
    {
      x = p2->coef[i];
    }
    dest->add(dest, i, (k - x));
  }
}