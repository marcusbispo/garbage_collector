#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("1\n");
    int *a = malloc2(sizeof(int));
    dump();
  printf("2\n");
    int *b = malloc2(sizeof(int));
    dump();
  printf("3\n");
    atrib2(a, b);
    dump();
  printf("4\n");
    atrib2(b, NULL);
    dump();
  printf("\nDigite um numero\n-> ");
  scanf("%i", a);
  printf("\nO numero digitado foi %i\n", *a);
    return 0;
}