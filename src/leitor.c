#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "leitor.h"
#include "hash_table.h"

HashTable* ler_concurso_CSV() {
    FILE* arquivo = fopen("concursos/concurso.csv", "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return NULL;
    } else {
        printf("\n\nLendo dados do arquivo...\n\n");
    }

    HashTable *tabela = criar_tabela();

    char linha[1024];
    int cont = 0;
    while (fgets(linha, 1024, arquivo)) {
        if(cont == 0) {
            cont++;
            continue;
        }
        int numero;
        char data[11];
        int bola_1, bola_2, bola_3, bola_4, bola_5, bola_6;
        sscanf(linha, "%d,%[^,],%d,%d,%d,%d,%d,%d", &numero, data, &bola_1, &bola_2, &bola_3, &bola_4, &bola_5, &bola_6);
        Concurso* concurso = criar_concurso(numero, data, bola_1, bola_2, bola_3, bola_4, bola_5, bola_6);
        inserir_concurso(tabela, concurso);
    }

    fclose(arquivo);

    return tabela;
}

HashTable* ler_concurso_TSV() {
    FILE* arquivo = fopen("concursos/concurso.tsv", "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return NULL;
    } else {
        printf("\n\nLendo dados do arquivo...\n\n");
    }

    HashTable *tabela = criar_tabela();

    int cont = 0;
    char linha[1024];
    while (fgets(linha, 1024, arquivo)) {
        if(cont == 0) {
            cont++;
            continue;
        }
        int numero;
        char data[11];
        int bola_1, bola_2, bola_3, bola_4, bola_5, bola_6;
        sscanf(linha, "%d\t%[^,]\t%d\t%d\t%d\t%d\t%d\t%d", &numero, data, &bola_1, &bola_2, &bola_3, &bola_4, &bola_5, &bola_6);
        Concurso* concurso = criar_concurso(numero, data, bola_1, bola_2, bola_3, bola_4, bola_5, bola_6);
        inserir_concurso(tabela, concurso);
    }

    fclose(arquivo);

    return tabela;
}