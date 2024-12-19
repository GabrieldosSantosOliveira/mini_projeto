#include <stdio.h>
#include <string.h>

int main()
{
  char a[10] = "Gabr+iel";
  printf("STRING: %p\n", a);
  char *pointer = a;
  printf("TOKEN: %p\n", pointer);

  char *token = strtok(a, "+");
  printf("TOKEN: %p\n", token);
  token = strtok(NULL, "+");
  printf("TOKEN: %p\n", token);
  return 0;
}