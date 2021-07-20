#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("1\n");                                  // Each "printf("k\n");" as k being a number is only to help us visualize what is happening
    int *a = malloc2(sizeof(int));                  // Okay... We allocated memory and the pointer a is pointing to the address of the memory allocated
    dump();                                         // All dump()'s only print our heap

    printf("2\n");
    int *b = malloc2(sizeof(int));                  // We made the same for the pointer b
    dump();

    printf("3\n");
    atrib2(a, b);                                   // Then we use the atrib2 function assign a to b
    dump();

    printf("4\n");
    atrib2(b, NULL);                                // Now we assign NULL to b
    dump();

    return 0;
}
