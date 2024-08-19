#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "concurso.h"

Concurso* criar_concurso(int numero, char data[11], int bola_1, int bola_2, int bola_3, int bola_4, int bola_5, int bola_6) {
    Concurso* novo_concurso = (Concurso*)malloc(sizeof(Concurso));
    if (novo_concurso == NULL) {
        return NULL;
    }
    novo_concurso->numero = numero;
    strncpy(novo_concurso->data, data, 11);
    novo_concurso->bolas[0] = bola_1;
    novo_concurso->bolas[1] = bola_2;
    novo_concurso->bolas[2] = bola_3;
    novo_concurso->bolas[3] = bola_4;
    novo_concurso->bolas[4] = bola_5;
    novo_concurso->bolas[5] = bola_6;
    novo_concurso->ano = atoi(strrchr(data, '-') + 1);
    return novo_concurso;
}

void imprimir_concurso(Concurso* concurso) {
    printf("Concurso %d: %s\n", concurso->numero, concurso->data);
    printf("Bolas sorteadas: %d %d %d %d %d %d\n", concurso->bolas[0], concurso->bolas[1], concurso->bolas[2], concurso->bolas[3], concurso->bolas[4], concurso->bolas[5]);
}