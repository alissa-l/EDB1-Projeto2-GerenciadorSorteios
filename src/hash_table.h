#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "concurso.h"

/**
 * @brief Tamanho da tabela hash.
 * 
 */
#define TAMANHO_TABELA 5000

/**
 * @brief Estrutura da tabela hash.
 * 
 */
typedef struct {
    Concurso* tabela[TAMANHO_TABELA];
} HashTable;

/**
 * @brief Gera o hash de um número de concurso - Função de dispersão.
 * 
 * @param numeroConcurso 
 * @return unsigned int 
 */
unsigned int hash(int numeroConcurso);

/**
 * @brief Cria uma nova tabela hash.
 * 
 * @return HashTable* 
 */
HashTable* criar_tabela();

/**
 * @brief Insere um concurso na tabela hash.
 * 
 * @param tabela 
 * @param concurso 
 */
void inserir_concurso(HashTable* tabela, Concurso* concurso);

/**
 * @brief Busca um concurso na tabela hash.
 * 
 * @param tabela 
 * @param numeroConcurso 
 * @return Concurso* 
 */
Concurso* buscar_concurso(HashTable* tabela, int numeroConcurso);

/**
 * @brief Remove um concurso da tabela hash.
 * 
 * @param tabela 
 * @param numeroConcurso 
 */
void remover_concurso(HashTable* tabela, int numeroConcurso);

/**
 * @brief Imprime a tabela hash.
 * 
 * @param tabela 
 */
void imprimir_tabela(HashTable* tabela);

/**
 * @brief Apresenta estatísticas sobre a tabela hash.
 * 
 * @param tabela 
 */
void apresentar_estatisticas(HashTable* tabela);

/**
 * @brief Quantidade de sorteios de um número.
 * 
 * @param tabela 
 * @param numero 
 */
void quantidade_de_sorteios_de_um_numero(HashTable* tabela, int numero);

/**
 * @brief Estatísticas sobre os 10 números mais sorteados.
 * 
 * @param tabela 
 */
void dez_mais_sorteados(HashTable* tabela);

/**
 * @brief Estatísticas sobre os 10 números menos sorteados.
 * 
 * @param tabela 
 */
void dez_menos_sorteados(HashTable* tabela);

/**
 * @brief Estatísticas sobre a quantidade de concursos em um ano.
 * 
 * @param tabela 
 * @param ano 
 */
void quantidade_ano(HashTable* tabela, int ano);

#endif
