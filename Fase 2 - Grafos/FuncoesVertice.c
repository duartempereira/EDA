/**
 * @file FuncoesVertice.c
 * @brief Funções para manipulação de vértices num grafo.
 *
 * @details
 * Este ficheiro contém funções para criar, adicionar, procurar, alterar e remover vértices
 * numa estrutura de grafo. Também inclui funções de impressão para listar vértices.
 *
 * Um vértice é representado pela estrutura `Vertice`, contendo ID, frequência,
 * coordenadas (x, y), lista de adjacências e marcação de visita.
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
  * @brief Cria um novo vértice com os dados fornecidos.
  *
  * @param id Identificador único do vértice.
  * @param frequencia Carácter que representa a frequência do vértice.
  * @param x Coordenada X do vértice.
  * @param y Coordenada Y do vértice.
  * @return Apontador para o vértice criado, ou NULL em caso de falha na alocação.
  */
Vertice* criarVertice(int id, char frequencia, int x, int y) {
    Vertice* v = malloc(sizeof(Vertice));
    if (!v) {
        return NULL; // falha na alocação
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
 * @brief Adiciona um vértice ao grafo.
 *
 * Atualiza as dimensões do grafo se necessário.
 *
 * @param grafo Apontador para o grafo onde o vértice será adicionado.
 * @param vertice Apontador para o vértice a adicionar.
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
 * @brief Imprime os dados de um vértice na consola.
 *
 * @param v Apontador para o vértice a imprimir.
 */
void imprimirVertice(Vertice* v) {
    if (!v) return;
    printf("ID: %d  Freq: %c  Coord: (%d,%d)\n", v->id, v->frequencia, v->x, v->y);
}

/**
 * @brief Lista todos os vértices do grafo, imprimindo-os na consola.
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
 * @brief Procura um vértice no grafo pelas coordenadas (x, y).
 *
 * @param grafo Apontador para o grafo.
 * @param x Coordenada X a procurar.
 * @param y Coordenada Y a procurar.
 * @return Apontador para o vértice encontrado, ou NULL se não encontrado.
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
 * @brief Altera a frequência de um vértice.
 *
 * @param v Apontador para o vértice a alterar.
 * @param novaFreq Novo carácter de frequência.
 * @return 1 se alterou com sucesso, 0 se v for NULL.
 */
int alterarFrequenciaVertice(Vertice* v, char novaFreq) {
    if (!v) return 0;
    v->frequencia = novaFreq;
    return 1;
}

/**
 * @brief Procura um vértice no grafo pelo seu ID.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do vértice a procurar.
 * @return Apontador para o vértice encontrado, ou NULL se não existir.
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
 * @brief Remove um vértice do grafo pelo seu ID.
 *
 * Também remove todas as arestas associadas a este vértice.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do vértice a remover.
 * @return 0 em caso de sucesso, -1 se o vértice não for encontrado ou grafo inválido.
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
    return -1; // não encontrado
}
