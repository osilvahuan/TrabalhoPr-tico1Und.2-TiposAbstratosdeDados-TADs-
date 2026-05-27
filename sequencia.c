#include "sequencia.h"

// Aloca a memória inicial usando malloc
void inicializa(Sequencia *s, int cap) {
    s->dados = (int *) malloc(cap * sizeof(int));
    if (s->dados == NULL) exit(1); // Verificação de erro na alocação
    s->quantidade = 0;
    s->capacidade = cap;
}

// Lógica de Inserção: O(n) devido ao deslocamento para a direita
void insert(Sequencia *s, int pos, int elem) {
    // Verificação de limites
    if (pos < 0 || pos > s->quantidade || s->quantidade >= s->capacidade) {
        printf("Erro: Posição inválida ou capacidade esgotada.\n");
        return;
    }
    // Desloca elementos para a direita para abrir espaço
    for (int i = s->quantidade; i > pos; i--) {
        s->dados[i] = s->dados[i - 1];
    }
    s->dados[pos] = elem;
    s->quantidade++;
}

// Lógica de Remoção: O(n) devido ao deslocamento para a esquerda
void remove_pos(Sequencia *s, int pos) {
    if (pos < 0 || pos >= s->quantidade) {
        printf("Erro: Posição inexistente.\n");
        return;
    }
    // Puxa os elementos para cobrir o buraco deixado
    for (int i = pos; i < s->quantidade - 1; i++) {
        s->dados[i] = s->dados[i + 1];
    }
    s->quantidade--;
}

// Acesso direto: O(1)
int get(Sequencia *s, int pos) {
    if (pos < 0 || pos >= s->quantidade) return -1;
    return s->dados[pos];
}

void print(Sequencia *s) {
    printf("SEQUENCIA: ");
    for (int i = 0; i < s->quantidade; i++) {
        printf("%d ", s->dados[i]);
    }
    printf("\n");
}

void libera(Sequencia *s) {
    free(s->dados); // Libera o array dinâmico
}