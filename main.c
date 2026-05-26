#include "sequencia.h"

int main() {
    Sequencia seq;
    inicializa(&seq, 20);

    // 1. Inserir 10 elementos
    for (int i = 0; i < 10; i++) {
        insert(&seq, i, (i + 1) * 5); // Insere 5, 10, 15... 50
    }

    printf("--- Antes da Remoção ---\n");
    print(&seq);

    // 2. Remover 2 elementos do meio
    remove_pos(&seq, 4); // Remove o 5 elemento
    remove_pos(&seq, 5); // Remove o novo 6 elemento

    printf("\n--- Depois da Remoção ---\n");
    print(&seq);

    libera(&seq);
    return 0;
}