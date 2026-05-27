#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;      // Ponteiro para o array dinâmico
    int quantidade;  // Elementos atuais
    int capacidade;  // Espaço total disponível
} ArraySequence;

// Protótipos obrigatórios conforme o PDF do trabalho
void as_inicializa(ArraySequence *as, int cap_inicial);
void as_pushBack(ArraySequence *as, int valor);
void as_pushFront(ArraySequence *as, int valor);
void as_insert(ArraySequence *as, int pos, int valor);
void as_remove(ArraySequence *as, int pos);
int as_find(ArraySequence *as, int valor);
int as_size(ArraySequence *as);
void as_print(ArraySequence *as);
void as_libera(ArraySequence *as);

#endif // ARRAY_SEQUENCE_H