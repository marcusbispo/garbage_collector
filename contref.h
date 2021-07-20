#ifndef CONTREF_H_INCLUDED
#define CONTREF_H_INCLUDED

typedef struct heap{
    int count;
    void *address;
    struct heap *next;
    struct heap *prev;
}heap;

heap *erasenode(heap *a, void *address);
void update(void *st_address, int inc);
void *malloc2(int size_);
void atrib2(void *st_address, void *nd_address);
void dump();

#endif // CONTREF_H_INCLUDED
