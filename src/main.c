#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "concurso.h"
#include "leitor.h"

/**
 * @brief Imprime as opções do menu.
 * 
 */
void menu() {
    printf("+-------------------------------------------------+\n");
    printf("1 - Inserir Concurso\n");
    printf("2 - Buscar Concurso\n");
    printf("3 - Remover Concurso\n");
    printf("4 - Visualizar Todos os Concursos\n");
    printf("5 - Carregar Concursos do arquivo CSV\n");
    printf("6 - Carregar Concursos do arquivo TSV\n");
    printf("7 - Apresentar Estatísticas\n");
    printf("0 - Sair\n");
    printf("+-------------------------------------------------+\n");
    printf("Escolha uma opção: ");
}

int main() {
    HashTable* tabela = criar_tabela();
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n\nDigite os dados do concurso:\n");
                int numero;
                char data[11];
                int bola_1, bola_2, bola_3, bola_4, bola_5, bola_6;
                printf("Número: ");
                scanf("%d", &numero);
                printf("Data no formato DD-MM-AAAA: ");
                scanf("%s", data);
                printf("Bola 1: ");
                scanf("%d", &bola_1);
                printf("Bola 2: ");
                scanf("%d", &bola_2);
                printf("Bola 3: ");
                scanf("%d", &bola_3);
                printf("Bola 4: ");
                scanf("%d", &bola_4);
                printf("Bola 5: ");
                scanf("%d", &bola_5);
                printf("Bola 6: ");
                scanf("%d", &bola_6);
                Concurso* concurso = criar_concurso(numero, data, bola_1, bola_2, bola_3, bola_4, bola_5, bola_6);
                inserir_concurso(tabela, concurso);
                break;
            case 2:
                printf("\n\nDigite o número do concurso: ");
                int numeroConcurso;
                scanf("%d", &numeroConcurso);
                Concurso* concurso_b = buscar_concurso(tabela, numeroConcurso);
                if (concurso_b != NULL) {
                    imprimir_concurso(concurso_b);
                } else {
                    printf("Concurso não encontrado.\n");
                }
                break;
            case 3:
                printf("\n\nDigite o número do concurso: ");
                int numeroConcursoRemover;
                scanf("%d", &numeroConcursoRemover);
                remover_concurso(tabela, numeroConcursoRemover);              
                break;
            case 4:
                imprimir_tabela(tabela);
                break;
            case 5:
                tabela = ler_concurso_CSV();
                break;
            case 6:
                tabela = ler_concurso_TSV();
                break;
            case 7:
                apresentar_estatisticas(tabela);
                break;
            case 0:
                break;
            default:
        }
    } while (opcao != 0);

    return 0;
}
