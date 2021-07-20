#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

heap *list = NULL;                                          // our heap

heap *erasenode(heap *a, void *address){                    // erasenode function
    heap *aux = a;                                          // aux points to the first node

    while(aux != NULL && aux->address != address){          // we search for the node
        aux = aux->next;
    }

    if(aux != NULL){                                        // if we have found
        if(aux->prev == NULL && aux->next == NULL){         //      we free it
            free(aux->address);
            free(aux);
            return NULL;
        }
        else if(aux->prev == NULL && aux->next != NULL){
            aux->next->prev = NULL;
            a = aux->next;
            free(aux->address);
            free(aux);
        }
        else if(aux->prev != NULL && aux->next == NULL){
            aux->prev->next = NULL;
            free(aux->address);
            free(aux);
        }
        else{
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux->address);
            free(aux);
        }
    }

    return a;                                               // then we return the heap
}

void update(void *st_address, int inc){                     // update function
    heap *aux = list;                                       // aux points to the first node

    while(aux != NULL && aux->address != st_address){       // we search for the node with the first address
        aux = aux->next;
    }

    if(aux != NULL && aux->address == st_address){          // if we have found
        aux->count = aux->count + inc;                      //      we update the count

        if(aux->count == 0){                                //      if the count is equal 0
            erasenode(list, st_address);                    //          we erase the node
        }
    }
}

void *malloc2(int size_){                                    // malloc2 function
    heap *aux = malloc(sizeof(heap));                       // we create an aux node
    aux->address = malloc(size_);                           // alocate memory for our data
    aux->count = 1;                                         // count 1 for our node

    if(list != NULL){                                       // if there's something inside our heap
        aux->next = list;                                   //      the aux node will get in the first position
        aux->prev = NULL;
        list->prev = aux;
    }
    else{                                                   // else
        aux->next = NULL;
        aux->prev = NULL;                                   //      the aux node will be the first one to get in
    }

    list = aux;                                             // we update our heap

    return list->address;                                   // and return the first node address
}

void atrib2(void *st_address, void *nd_address){            // atrib2 function
    if(st_address != NULL){                                 // if the first address is not NULL
        update(st_address, -1);                             //      we update it
        if(nd_address != NULL){                             //      if the second address is not NULL
            update(nd_address, 1);                          //          we update the it
        }
        st_address = nd_address;                            // then the first address points to the second one
    }
}

void dump(){                                                // dump function
    heap *aux = list;                                       // aux points to the first node

    while(aux != NULL){                                     // then we print heap
        printf("Address: %p\nCount: %i\n\n", aux->address, aux->count);
        aux = aux->next;
    }
}
