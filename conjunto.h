#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elementos;
    int quantidade;
    int capacidade;
} Conjunto;

// Operações básicas
void conjunto_inicializa(Conjunto *c, int cap);
bool conjunto_add(Conjunto *c, int elem);      // O(n)
bool conjunto_remove(Conjunto *c, int elem);   // O(n)
bool conjunto_contains(Conjunto *c, int elem); // O(n)
void conjunto_print(Conjunto *c);
void conjunto_libera(Conjunto *c);

// Operações de grupo (Exigência do Trabalho)
Conjunto conjunto_union(Conjunto *a, Conjunto *b);
Conjunto conjunto_intersection(Conjunto *a, Conjunto *b);

#endif // CONJUNTO_H