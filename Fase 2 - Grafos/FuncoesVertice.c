/**
 * @file FuncoesVertice.c
 * @brief Fun��es para manipula��o de v�rtices num grafo.
 *
 * @details
 * Este ficheiro cont�m fun��es para criar, adicionar, procurar, alterar e remover v�rtices
 * numa estrutura de grafo. Tamb�m inclui fun��es de impress�o para listar v�rtices.
 *
 * Um v�rtice � representado pela estrutura `Vertice`, contendo ID, frequ�ncia,
 * coordenadas (x, y), lista de adjac�ncias e marca��o de visita.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "Structs.h"
#include "FuncoesVertice.h"
#include "FuncoesAresta.h"

 /**
  * @brief Cria um novo v�rtice com os dados fornecidos.
  *
  * @param id Identificador �nico do v�rtice.
  * @param frequencia Car�cter que representa a frequ�ncia do v�rtice.
  * @param x Coordenada X do v�rtice.
  * @param y Coordenada Y do v�rtice.
  * @return Apontador para o v�rtice criado, ou NULL em caso de falha na aloca��o.
  */
Vertice* criarVertice(int id, char frequencia, int x, int y) {
    Vertice* v = malloc(sizeof(Vertice));
    if (!v) {
        return NULL; // falha na aloca��o
    }
    v->id = id;
    v->frequencia = frequencia;
    v->x = x;
    v->y = y;
    v->visitado = 0;
    v->adj = NULL;
    v->next = NULL;
    return v;
}

/**
 * @brief Adiciona um v�rtice ao grafo.
 *
 * Atualiza as dimens�es do grafo se necess�rio.
 *
 * @param grafo Apontador para o grafo onde o v�rtice ser� adicionado.
 * @param vertice Apontador para o v�rtice a adicionar.
 * @return 0 em caso de sucesso, -1 em caso de erro (Apontadores NULL).
 */
int adicionarVertice(GR* grafo, Vertice* vertice) {
    if (!grafo || !vertice) return -1;

    if (vertice->x > grafo->colunas) {
        grafo->colunas = vertice->x;
    }
    if (vertice->y > grafo->linhas) {
        grafo->linhas = vertice->y;
    }

    if (grafo->vertices == NULL) {
        grafo->vertices = vertice;
    }
    else {
        Vertice* temp = grafo->vertices;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = vertice;
    }
    grafo->numVertices++;
    return 0;
}

/**
 * @brief Imprime os dados de um v�rtice na consola.
 *
 * @param v Apontador para o v�rtice a imprimir.
 */
void imprimirVertice(Vertice* v) {
    if (!v) return;
    printf("ID: %d  Freq: %c  Coord: (%d,%d)\n", v->id, v->frequencia, v->x, v->y);
}

/**
 * @brief Lista todos os v�rtices do grafo, imprimindo-os na consola.
 *
 * @param grafo Apontador para o grafo.
 */
void listarVertices(GR* grafo) {
    if (!grafo) return;
    Vertice* v = grafo->vertices;
    while (v) {
        imprimirVertice(v);
        v = v->next;
    }
}

/**
 * @brief Procura um v�rtice no grafo pelas coordenadas (x, y).
 *
 * @param grafo Apontador para o grafo.
 * @param x Coordenada X a procurar.
 * @param y Coordenada Y a procurar.
 * @return Apontador para o v�rtice encontrado, ou NULL se n�o encontrado.
 */
Vertice* procurarVerticePorCoordenadas(GR* grafo, int x, int y) {
    if (!grafo) return NULL;
    Vertice* v = grafo->vertices;
    while (v != NULL) {
        if (v->x == x && v->y == y) return v;
        v = v->next;
    }
    return NULL;
}

/**
 * @brief Altera a frequ�ncia de um v�rtice.
 *
 * @param v Apontador para o v�rtice a alterar.
 * @param novaFreq Novo car�cter de frequ�ncia.
 * @return 1 se alterou com sucesso, 0 se v for NULL.
 */
int alterarFrequenciaVertice(Vertice* v, char novaFreq) {
    if (!v) return 0;
    v->frequencia = novaFreq;
    return 1;
}

/**
 * @brief Procura um v�rtice no grafo pelo seu ID.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do v�rtice a procurar.
 * @return Apontador para o v�rtice encontrado, ou NULL se n�o existir.
 */
Vertice* procurarVerticePorId(GR* grafo, int id) {
    if (!grafo) return NULL;
    Vertice* v = grafo->vertices;
    while (v != NULL) {
        if (v->id == id) return v;
        v = v->next;
    }
    return NULL;
}

/**
 * @brief Remove um v�rtice do grafo pelo seu ID.
 *
 * Tamb�m remove todas as arestas associadas a este v�rtice.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do v�rtice a remover.
 * @return 0 em caso de sucesso, -1 se o v�rtice n�o for encontrado ou grafo inv�lido.
 */
int removerVerticePorId(GR* grafo, int id) {
    if (!grafo || !grafo->vertices) return -1;

    Vertice* atual = grafo->vertices;
    Vertice* anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            if (anterior == NULL) {
                grafo->vertices = atual->next;
            }
            else {
                anterior->next = atual->next;
            }

            removerArestasParaVertice(grafo, atual);
            libertarArestasDoVertice(atual);
            free(atual);
            grafo->numVertices--;
            return 0;
        }
        anterior = atual;
        atual = atual->next;
    }
    return -1; // n�o encontrado
}
