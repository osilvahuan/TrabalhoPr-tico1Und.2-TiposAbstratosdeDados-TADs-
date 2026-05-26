#ifndef SEQUENCIA_H
#define SEQUENCIA_H

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura conforme os requisitos de TAD
typedef struct {
    int *dados;      // Ponteiro para o array alocado dinamicamente
    int quantidade;  // Número de elementos atualmente inseridos
    int capacidade;  // Tamanho total do array alocado
} Sequencia;

// Protótipos das funções obrigatórias
void inicializa(Sequencia *s, int cap);
void insert(Sequencia *s, int pos, int elem);
void remove_pos(Sequencia *s, int pos);
int get(Sequencia *s, int pos);
void print(Sequencia *s);
void libera(Sequencia *s); //evita vazamento de memória

#endif // SEQUENCIA_H