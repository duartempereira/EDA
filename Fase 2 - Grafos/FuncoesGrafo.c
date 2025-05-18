/**
 * @file FuncoesGrafo.c
 * @brief Funções para criar, imprimir e libertar um grafo.
 *
 * @details
 * Este ficheiro contém funções para manipulação básica de um grafo:
 * - criar um grafo vazio,
 * - imprimir o mapa do grafo na consola,
 * - libertar toda a memória usada pelo grafo.
 *
 * O grafo é representado pela estrutura `GR`, que contém uma lista ligada
 * de vértices (`Vertice`), número de vértices, e as dimensões do mapa (linhas e colunas).
 *
 * As funções utilizam estruturas auxiliares para vértices e arestas.
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
  * @note Em caso de falha na alocação de memória, termina o programa com exit(1).
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
 * Constrói uma matriz 2D de caracteres representando o mapa,
 * onde cada posição corresponde a um vértice (frequência) ou '.' para vazio.
 *
 * @param grafo Apontador para o grafo a imprimir.
 *
 * @note A função aloca dinamicamente memória para construir o mapa,
 * que é libertada no final da função.
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
 * @brief Liberta toda a memória alocada para o grafo, incluindo vértices e arestas.
 *
 * @param grafo Apontador para o grafo a libertar.
 * @return 0 se for bem sucedido, -1 se o grafo for NULL.
 *
 * @note Esta função pressupõe que o grafo foi alocado dinamicamente.
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