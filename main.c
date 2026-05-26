#include <stdio.h>
#include "sequencia.h"
#include "conjunto.h"

int main() {
    printf("==========================================\n");
    printf("   TESTES DO TRABALHO PRATICO 1 - UND 2  \n");
    printf("==========================================\n\n");

    // --- TESTE DO TAD 1: SEQUÊNCIA ---
    // Requisito: Inserir 10 elementos, remover 2 do meio e exibir [2]
    printf(">>> TAD 1: SEQUÊNCIA <<<\n");
    Sequencia seq;
    inicializa(&seq, 15); // Alocação dinâmica inicial [1]

    for (int i = 0; i < 10; i++) {
        insert(&seq, i, (i + 1) * 10); // Insere 10, 20, 30... 100
    }
    
    printf("Antes da remocao:\n");
    print(&seq);

    // Removendo 2 elementos do meio (posições 4 e 5)
    remove_pos(&seq, 4); 
    remove_pos(&seq, 4); // Note: após remover a pos 4, o próximo elemento assume a pos 4

    printf("Depois de remover 2 elementos do meio:\n");
    print(&seq);
    
    libera(&seq); // Liberação de memória obrigatória [1]
    printf("\n------------------------------------------\n\n");


    // --- TESTE DO TAD 2: CONJUNTO ---
    // Requisito: Uniao e Intersecao de A={1,2,3,5} e B={3,4,5,6} [3]
    printf(">>> TAD 2: CONJUNTO <<<\n");
    Conjunto A, B;
    conjunto_inicializa(&A, 10);
    conjunto_inicializa(&B, 10);

    // Populando Conjunto A sem permitir repetidos [3]
    conjunto_add(&A, 1); conjunto_add(&A, 2); 
    conjunto_add(&A, 3); conjunto_add(&A, 5);

    // Populando Conjunto B
    conjunto_add(&B, 3); conjunto_add(&B, 4); 
    conjunto_add(&B, 5); conjunto_add(&B, 6);

    printf("Conjunto A: "); conjunto_print(&A);
    printf("Conjunto B: "); conjunto_print(&B);

    // Operação de União (Gera um novo conjunto) [3]
    Conjunto uni = conjunto_union(&A, &B);
    printf("\nUniao (A U B): "); conjunto_print(&uni);

    // Operação de Interseção (Gera um novo conjunto) [3]
    Conjunto inter = conjunto_intersection(&A, &B);
    printf("Intersecao (A n B): "); conjunto_print(&inter);

    // Limpeza final da memória alocada dinamicamente
    conjunto_libera(&A); 
    conjunto_libera(&B);
    conjunto_libera(&uni); 
    conjunto_libera(&inter);

    printf("\n==========================================\n");
    printf("        FIM DOS TESTES ATUAIS             \n");
    printf("==========================================\n");

    return 0;
}