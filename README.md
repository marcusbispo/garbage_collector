# Garbage Collector

## What did I do?

I implemented a garbage collector using the C language by request of the programming languages discipline professor.

## How I did this?

I wrote a C library to manipulate pointers and some data.

## What will you find inside the library?

You will find a struct to hold our heap and some functions to manipulate the pointers.

### malloc2

The malloc2 function is used to allocate memory for some pointer and make it hold the number of refereces to its address.

### atrib2

The atrib2 function is used to assign pointers.

### update

The update function updates the number of references to some pointer when the atrib function is called.

### erasenode

The erasenode function free a node inside our heap when, after some assignments, the number of references to the pointer is equal to zero. It's used when called by the atrib2 function.

## What can you do?

You are free to use the library or improve it. There's a lot of possibilities working in group.

Thank you by reading this README!!!