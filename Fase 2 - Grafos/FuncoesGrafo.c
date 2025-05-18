/**
 * @file FuncoesGrafo.c
 * @brief Fun��es para criar, imprimir e libertar um grafo.
 *
 * @details
 * Este ficheiro cont�m fun��es para manipula��o b�sica de um grafo:
 * - criar um grafo vazio,
 * - imprimir o mapa do grafo na consola,
 * - libertar toda a mem�ria usada pelo grafo.
 *
 * O grafo � representado pela estrutura `GR`, que cont�m uma lista ligada
 * de v�rtices (`Vertice`), n�mero de v�rtices, e as dimens�es do mapa (linhas e colunas).
 *
 * As fun��es utilizam estruturas auxiliares para v�rtices e arestas.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGrafo.h"
#include "FuncoesVertice.h"
#include "FuncoesAresta.h"

 /**
  * @brief Cria um grafo vazio e inicializa os seus campos.
  *
  * @return Apontador para o grafo criado. O grafo deve ser libertado posteriormente.
  *
  * @note Em caso de falha na aloca��o de mem�ria, termina o programa com exit(1).
  */
GR* criarGrafo() {
    GR* grafo = malloc(sizeof(GR));
    if (!grafo) {
        exit(1);
    }
    grafo->vertices = NULL;
    grafo->numVertices = 0;
    grafo->linhas = 0;
    grafo->colunas = 0;
    return grafo;
}

/**
 * @brief Imprime o mapa do grafo na consola.
 *
 * Constr�i uma matriz 2D de caracteres representando o mapa,
 * onde cada posi��o corresponde a um v�rtice (frequ�ncia) ou '.' para vazio.
 *
 * @param grafo Apontador para o grafo a imprimir.
 *
 * @note A fun��o aloca dinamicamente mem�ria para construir o mapa,
 * que � libertada no final da fun��o.
 */
void imprimirMapa(GR* grafo) {
    if (!grafo) return;

    int linhas = grafo->linhas;
    int colunas = grafo->colunas;

    char** mapa = malloc(linhas * sizeof(char*));
    if (!mapa) {
        perror("malloc");
        return;
    }

    for (int i = 0; i < linhas; i++) {
        mapa[i] = malloc(colunas * sizeof(char));
        if (!mapa[i]) {
            for (int j = 0; j < i; j++) free(mapa[j]);
            free(mapa);
            return;
        }
        for (int j = 0; j < colunas; j++) {
            mapa[i][j] = '.';
        }
    }

    Vertice* v = grafo->vertices;
    while (v != NULL) {
        int linha = v->y - 1;
        int col = v->x - 1;

        if (linha >= 0 && linha < linhas && col >= 0 && col < colunas) {
            mapa[linha][col] = v->frequencia;
        }
        v = v->next;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            putchar(mapa[i][j]);
        }
        putchar('\n');
        free(mapa[i]);
    }
    free(mapa);
}

/**
 * @brief Liberta toda a mem�ria alocada para o grafo, incluindo v�rtices e arestas.
 *
 * @param grafo Apontador para o grafo a libertar.
 * @return 0 se for bem sucedido, -1 se o grafo for NULL.
 *
 * @note Esta fun��o pressup�e que o grafo foi alocado dinamicamente.
 */
int libertarGrafo(GR* grafo) {
    if (!grafo) return -1;

    Vertice* v = grafo->vertices;
    while (v) {
        Vertice* tmpV = v;
        libertarArestasDoVertice(v);
        v = v->next;
        free(tmpV);
    }
    grafo->vertices = NULL;
    grafo->numVertices = 0;
    grafo->linhas = 0;
    grafo->colunas = 0;

    free(grafo);

    return 0;
}