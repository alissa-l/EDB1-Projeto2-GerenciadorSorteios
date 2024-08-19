#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 5000

unsigned int hash(int numeroConcurso) {
    return numeroConcurso;
}

HashTable* criar_tabela() {
    HashTable* nova_tabela = (HashTable*)malloc(sizeof(HashTable));
    if (nova_tabela == NULL) {
        return NULL;
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        nova_tabela->tabela[i] = NULL;
    }

    return nova_tabela;
}

void inserir_concurso(HashTable* tabela, Concurso* concurso) {
    unsigned int indice = hash(concurso->numero);
    concurso->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = concurso;
}

Concurso* buscar_concurso(HashTable* tabela, int numeroConcurso) {
    unsigned int indice = hash(numeroConcurso);
    Concurso* concurso = tabela->tabela[indice];
    while (concurso != NULL) {
        if (concurso->numero == numeroConcurso) {
            return concurso;
        }
        concurso = concurso->proximo;
    }
    return NULL;
}

void remover_concurso(HashTable* tabela, int numeroConcurso) {
    unsigned int indice = hash(numeroConcurso);
    Concurso* concurso = tabela->tabela[indice];
    Concurso* anterior = NULL;
    while (concurso != NULL) {
        if (concurso->numero == numeroConcurso) {
            if (anterior == NULL) {
                tabela->tabela[indice] = concurso->proximo;
            } else {
                anterior->proximo = concurso->proximo;
            }
            free(concurso);
            printf("Concurso removido com sucesso.\n");
            return;
        }
        anterior = concurso;
        concurso = concurso->proximo;
    }
}

void imprimir_tabela(HashTable* tabela) {
    printf("\n\nTabela de concursos:\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            printf("Concurso %d: %s\n", concurso->numero, concurso->data);
            concurso = concurso->proximo;
        }
    }
}

void apresentar_estatisticas(HashTable* tabela) {
    printf("\n\nEstatísticas:\n");
    int tamanho = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            tamanho++;
            concurso = concurso->proximo;
        }
    }
    printf("Quantidade de concursos: %d\n", tamanho);
    
    int numeroEscolhido;
    printf("Digite um número para ver a quantidade de sorteios: ");
    scanf("%d", &numeroEscolhido);

    quantidade_de_sorteios_de_um_numero(tabela, numeroEscolhido);
    dez_mais_sorteados(tabela);
    dez_menos_sorteados(tabela);

    int anoEscolhido;
    printf("\nDigite um ano para ver a quantidade de concursos: ");
    scanf("%d", &anoEscolhido);
    quantidade_ano(tabela, anoEscolhido);
}

void quantidade_de_sorteios_de_um_numero(HashTable* tabela, int numero) {
    int quantidade = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            for (int j = 0; j < 6; j++) {
                if (concurso->bolas[j] == numero) {
                    quantidade++;
                }
            }
            concurso = concurso->proximo;
        }
    }
    printf("O número %d foi sorteado %d vezes.\n", numero, quantidade);
}

void dez_mais_sorteados(HashTable* tabela) {
    printf("\nDez números mais sorteados:\n");

    int numeros[100] = {0};
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            for (int j = 0; j < 6; j++) {
                numeros[concurso->bolas[j] - 1]++;
            }
            concurso = concurso->proximo;
        }
    }
    printf("Números: ");
    for (int i = 0; i < 10; i++) {
        int maior = 0;
        int indice = 0;
        for (int j = 0; j < 100; j++) {
            if (numeros[j] > maior) {
                maior = numeros[j];
                indice = j;
            }
        }
        numeros[indice] = 0;
        printf("%d ", indice + 1);
    }
}

void dez_menos_sorteados(HashTable* tabela) {
    printf("\nDez números menos sorteados:\n");

    int numeros[100] = {0};
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            for (int j = 0; j < 6; j++) {
                numeros[concurso->bolas[j] - 1]++;
            }
            concurso = concurso->proximo;
        }
    }
    printf("Números: ");
    for (int i = 0; i < 10; i++) {
        int menor = 100000;
        int indice = 0;
        for (int j = 0; j < 100; j++) {
            if (numeros[j] < menor && numeros[j] != 0) {
                menor = numeros[j];
                indice = j;
            }
        }
        numeros[indice] = 0;
        printf("%d ", indice + 1);
    }
}

void quantidade_ano(HashTable* tabela, int ano) {
    int quantidade = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Concurso* concurso = tabela->tabela[i];
        while (concurso != NULL) {
            if (concurso->ano == ano) {
                quantidade++;
            }
            concurso = concurso->proximo;
        }
    }
    printf("Quantidade de concursos no ano %d: %d\n", ano, quantidade);
}