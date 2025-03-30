#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Antena {
    char frequencia;  
    int x, y;
    struct Antena* prox;
} Antena;

typedef struct Nefasto {
    int x, y;
    struct Nefasto* prox;
} Nefasto;

#endif