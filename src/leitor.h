#ifndef LEITOR_H
#define LEITOR_H

#include "concurso.h"
#include "hash_table.h"

/**
 * @brief Lê um concurso do arquivo CSV.
 *
 * @param arquivo Arquivo de onde será lido o concurso.
 * @return Concurso* Concurso lido.
 */
HashTable* ler_concurso_CSV();

/**
 * @brief Lê um concurso do arquivo TSV.
 *
 * @param arquivo Arquivo de onde será lido o concurso.
 * @return Concurso* Concurso lido.
 */
HashTable* ler_concurso_TSV();


#endif