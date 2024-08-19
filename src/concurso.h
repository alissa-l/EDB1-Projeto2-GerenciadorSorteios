#ifndef CONCURSO_H
#define CONCURSO_H

typedef struct Concurso {
    int numero;
    char data[11];
    int ano;
    int bolas[6];
    // Ponteiro para o próximo concurso - Chaining
    struct Concurso* proximo;
} Concurso;

Concurso* criar_concurso(int numero, char data[11], int bola_1, int bola_2, int bola_3, int bola_4, int bola_5, int bola_6);
void imprimir_concurso(Concurso* concurso);

#endif