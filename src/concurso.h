#ifndef CONCURSO_H
#define CONCURSO_H

/**
 * @brief Struct que representa um concurso.
 * 
 */
typedef struct Concurso {
    int numero;
    char data[11];
    int ano;
    int bolas[6];
    // Ponteiro para o próximo concurso - Chaining
    struct Concurso* proximo;
} Concurso;

/**
 * @brief Cria um novo concurso.
 * 
 * @param numero 
 * @param data 
 * @param bola_1 
 * @param bola_2 
 * @param bola_3 
 * @param bola_4 
 * @param bola_5 
 * @param bola_6 
 * @return Concurso* 
 */
Concurso* criar_concurso(int numero, char data[11], int bola_1, int bola_2, int bola_3, int bola_4, int bola_5, int bola_6);

/**
 * @brief Imprime um concurso.
 * 
 * @param concurso 
 */
void imprimir_concurso(Concurso* concurso);

#endif