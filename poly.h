#ifndef POLY_H
#define POLY_H

#include <stdio.h>
#define ID_SIZE 4
typedef struct poly
{
  char code[ID_SIZE];
  int p;
  double *coef;
  void (*add)(struct poly * const, int power, double coef);
} Poly;

Poly *new_poly();
void delete_poly(Poly *poly);
void print_poly_debug(Poly *poly);
void print_poly(Poly *poly);
void sum(const Poly *const p1, const Poly *const p2, Poly *const dest);
void sub(const Poly *const p1, const Poly *const p2, Poly *const dest);

void write_in_a_file(struct poly *, FILE *);
void read_from_a_file(struct poly *, FILE *);

#endif