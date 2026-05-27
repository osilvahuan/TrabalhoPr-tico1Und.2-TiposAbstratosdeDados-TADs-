#include "array_sequence.h"

void as_inicializa(ArraySequence *as, int cap_inicial) {
    as->dados = (int *) malloc(cap_inicial * sizeof(int));
    as->quantidade = 0;
    as->capacidade = cap_inicial;
}

// FUNÇÃO CHAVE: Redimensionamento Dinâmico [1, 2]
void as_garante_capacidade(ArraySequence *as) {
    if (as->quantidade == as->capacidade) {
        int nova_cap = as->capacidade * 2; // Dobra a capacidade
        int *novo_array = (int *) malloc(nova_cap * sizeof(int));
        
        // Copia os dados do array antigo para o novo
        for (int i = 0; i < as->quantidade; i++) {
            novo_array[i] = as->dados[i];
        }
        
        free(as->dados);      // Libera a memória antiga
        as->dados = novo_array; // Aponta para o novo bloco maior
        as->capacidade = nova_cap;
        printf("LOG: Capacidade aumentada para %d\n", nova_cap);
    }
}

void as_pushBack(ArraySequence *as, int valor) {
    as_garante_capacidade(as); 
    as->dados[as->quantidade] = valor;
    as->quantidade++;
}

void as_pushFront(ArraySequence *as, int valor) {
    as_garante_capacidade(as);
    // Desloca todos para a direita para abrir espaço no índice 0
    for (int i = as->quantidade; i > 0; i--) {
        as->dados[i] = as->dados[i - 1];
    }
    as->dados[0] = valor;
    as->quantidade++;
}

// Inserção em posição específica (Requisito do Trabalho) [2]
void as_insert(ArraySequence *as, int pos, int valor) {
    if (pos < 0 || pos > as->quantidade) {
        printf("Erro: Posicao de insercao %d invalida!\n", pos);
        return;
    }
    as_garante_capacidade(as);
    // Desloca elementos para a direita a partir da posição 'pos'
    for (int i = as->quantidade; i > pos; i--) {
        as->dados[i] = as->dados[i - 1];
    }
    as->dados[pos] = valor;
    as->quantidade++;
}

// Remoção de posição específica (Requisito do Trabalho) [2]
void as_remove(ArraySequence *as, int pos) {
    if (pos < 0 || pos >= as->quantidade) {
        printf("Erro: Posicao de remocao %d invalida!\n", pos);
        return;
    }
    // Desloca elementos para a esquerda para fechar o "buraco" [5, 6]
    for (int i = pos; i < as->quantidade - 1; i++) {
        as->dados[i] = as->dados[i + 1];
    }
    as->quantidade--;
}

int as_find(ArraySequence *as, int valor) {
    for (int i = 0; i < as->quantidade; i++) {
        if (as->dados[i] == valor) return i; 
    }
    return -1; 
}

// Retorna o tamanho atual (Requisito do Trabalho) [2]
int as_size(ArraySequence *as) {
    return as->quantidade;
}

void as_print(ArraySequence *as) {
    printf("[ ");
    for (int i = 0; i < as->quantidade; i++) printf("%d ", as->dados[i]);
    printf("]\n");
}

void as_libera(ArraySequence *as) {
    free(as->dados);
}