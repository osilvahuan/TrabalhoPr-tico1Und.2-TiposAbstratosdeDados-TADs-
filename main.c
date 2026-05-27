#include <stdio.h>
#include "sequencia.h"
#include "conjunto.h"
#include "array_sequence.h"

int main() {
    printf("==========================================\n");
    printf("   TESTES DO TRABALHO PRATICO 1 - UND 2  \n");
    printf("==========================================\n\n");

    // --- TESTE DO TAD 1: SEQUÊNCIA ---
    // Requisito: Inserir 10 elementos e remover 2 do meio [1]
    printf(">>> TAD 1: SEQUENCIA <<<\n");
    Sequencia seq;
    inicializa(&seq, 15); 

    for (int i = 0; i < 10; i++) {
        insert(&seq, i, (i + 1) * 10); // Insere 10, 20, 30... 100
    }
    
    printf("Antes da remocao:\n");
    print(&seq);

    // Removendo 2 elementos do meio conforme o PDF [1]
    remove_pos(&seq, 4); 
    remove_pos(&seq, 4); 

    printf("Depois de remover 2 elementos do meio:\n");
    print(&seq);
    
    libera(&seq); 
    printf("\n------------------------------------------\n\n");


    // --- TESTE DO TAD 2: CONJUNTO ---
    // Requisito: Uniao e Intersecao de A={1,2,3,5} e B={3,4,5,6} [1]
    printf(">>> TAD 2: CONJUNTO <<<\n");
    Conjunto A, B;
    conjunto_inicializa(&A, 10);
    conjunto_inicializa(&B, 10);

    // Populando os conjuntos de teste obrigatórios [1]
    conjunto_add(&A, 1); conjunto_add(&A, 2); 
    conjunto_add(&A, 3); conjunto_add(&A, 5);

    conjunto_add(&B, 3); conjunto_add(&B, 4); 
    conjunto_add(&B, 5); conjunto_add(&B, 6);

    printf("Conjunto A: "); conjunto_print(&A);
    printf("Conjunto B: "); conjunto_print(&B);

    // Operações que devem retornar novos conjuntos [1]
    Conjunto uni = conjunto_union(&A, &B);
    printf("\nUniao (A U B): "); conjunto_print(&uni);

    Conjunto inter = conjunto_intersection(&A, &B);
    printf("Intersecao (A n B): "); conjunto_print(&inter);

    conjunto_libera(&A); 
    conjunto_libera(&B);
    conjunto_libera(&uni); 
    conjunto_libera(&inter);
    printf("\n------------------------------------------\n\n");


    // --- TESTE DO TAD 3: ARRAY SEQUENCE (Crescimento Dinâmico) ---
    // Requisito: Inserir valores, crescer dinamicamente e testar limites [1]
    printf(">>> TAD 3: ARRAY SEQUENCE <<<\n");
    ArraySequence as;
    as_inicializa(&as, 2); // Capacidade inicial pequena para forçar o crescimento [Conversa]

    // 1. Inserir os valores obrigatórios: [2-5] [1]
    as_pushBack(&as, 10);
    as_pushBack(&as, 20);
    as_pushBack(&as, 30); // O array dobra de tamanho aqui [Conversa]
    as_pushBack(&as, 40);
    printf("Apos inserir [2-5]:\n");
    as_print(&as);

    // 2. Inserir no início (pushFront) [1]
    as_pushFront(&as, 5);
    printf("Apos inserir 5 no inicio:\n");
    as_print(&as);

    // 3. Inserir no meio (posição 3) [1]
    as_insert(&as, 3, 25);
    printf("Apos inserir 25 na posicao 3:\n");
    as_print(&as);

    // 4. Remover um elemento [1]
    as_remove(&as, 1);
    printf("Apos remover o elemento da posicao 1:\n");
    as_print(&as);

    // 5. Exibir tamanho e estrutura final [1]
    printf("Tamanho final: %d\n", as_size(&as));
    printf("Estrutura Final: ");
    as_print(&as);

    as_libera(&as); 

    printf("\n==========================================\n");
    printf("        FIM DE TODOS OS TESTES            \n");
    printf("==========================================\n");

    return 0;
}