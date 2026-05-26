#include "conjunto.h"

void conjunto_inicializa(Conjunto *c, int cap) {
    c->elementos = (int *) malloc(cap * sizeof(int));
    c->quantidade = 0;
    c->capacidade = cap;
}

bool conjunto_contains(Conjunto *c, int elem) {
    for (int i = 0; i < c->quantidade; i++) {
        if (c->elementos[i] == elem) return true; // Encontrou [8]
    }
    return false;
}

bool conjunto_add(Conjunto *c, int elem) {
    if (conjunto_contains(c, elem) || c->quantidade >= c->capacidade) {
        return false; // Não adiciona repetidos ou se estiver cheio [5, 9]
    }
    c->elementos[c->quantidade] = elem;
    c->quantidade++;
    return true;
}

bool conjunto_remove(Conjunto *c, int elem) {
    for (int i = 0; i < c->quantidade; i++) {
        if (c->elementos[i] == elem) {
            // Técnica eficiente: troca com o último e decrementa [6, 7]
            c->elementos[i] = c->elementos[c->quantidade - 1];
            c->quantidade--;
            return true;
        }
    }
    return false;
}

// União: Novo conjunto com elementos de A + elementos de B (sem repetir) [10]
Conjunto conjunto_union(Conjunto *a, Conjunto *b) {
    Conjunto res;
    conjunto_inicializa(&res, a->capacidade + b->capacidade);
    for (int i = 0; i < a->quantidade; i++) conjunto_add(&res, a->elementos[i]);
    for (int i = 0; i < b->quantidade; i++) conjunto_add(&res, b->elementos[i]);
    return res;
}

// Interseção: Novo conjunto apenas com elementos presentes em AMBOS [11]
Conjunto conjunto_intersection(Conjunto *a, Conjunto *b) {
    Conjunto res;
    conjunto_inicializa(&res, a->quantidade); 
    for (int i = 0; i < a->quantidade; i++) {
        if (conjunto_contains(b, a->elementos[i])) {
            conjunto_add(&res, a->elementos[i]);
        }
    }
    return res;
}

void conjunto_print(Conjunto *c) {
    printf("{ ");
    for (int i = 0; i < c->quantidade; i++) printf("%d ", c->elementos[i]);
    printf("}\n");
}

void conjunto_libera(Conjunto *c) {
    free(c->elementos);
}