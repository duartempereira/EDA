#ifndef FUNCOESVERTICE_H
#define FUNCOESVERTICE_H

/**
 * @file FuncoesVertice.h
 * @brief Declaração das funções para manipulação de vértices num grafo.
 *
 * Inclui criação, adição, remoção, procura e impressão de vértices.
 * Cada vértice representa uma antena com uma frequência e coordenadas (x,y).
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Cria um novo vértice com ID, frequência e coordenadas fornecidas.
  *
  * @param id Identificador único do vértice.
  * @param frequencia Carácter que representa a frequência da antena.
  * @param x Coordenada x do vértice no mapa.
  * @param y Coordenada y do vértice no mapa.
  * @return Apontador para o vértice criado ou NULL em caso de erro.
  */
Vertice* criarVertice(int id, char frequencia, int x, int y);

/**
 * @brief Adiciona um vértice ao grafo.
 * Atualiza as dimensões do grafo se necessário.
 *
 * @param grafo Apontador para o grafo onde o vértice será adicionado.
 * @param vertice Apontador para o vértice a adicionar.
 * @return 0 se sucesso, -1 em caso de erro.
 */
int adicionarVertice(GR* grafo, Vertice* vertice);

/**
 * @brief Imprime informação detalhada de um vértice.
 *
 * @param v Apontador para o vértice a imprimir.
 */
void imprimirVertice(Vertice* v);

/**
 * @brief Lista todos os vértices do grafo imprimindo-os um a um.
 *
 * @param grafo Apontador para o grafo.
 */
void listarVertices(GR* grafo);

/**
 * @brief Altera a frequência de um vértice.
 *
 * @param v Apontador para o vértice a alterar.
 * @param novaFreq Novo carácter da frequência.
 * @return 1 se a frequência foi alterada, 0 se o vértice for NULL.
 */
int alterarFrequenciaVertice(Vertice* v, char novaFreq);

/**
 * @brief Procura um vértice no grafo pelas suas coordenadas (x, y).
 *
 * @param grafo Apontador para o grafo.
 * @param x Coordenada x do vértice a procurar.
 * @param y Coordenada y do vértice a procurar.
 * @return Apontador para o vértice encontrado ou NULL se não existir.
 */
Vertice* procurarVerticePorCoordenadas(GR* grafo, int x, int y);

/**
 * @brief Procura um vértice no grafo pelo seu ID.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do vértice a procurar.
 * @return Apontador para o vértice encontrado ou NULL se não existir.
 */
Vertice* procurarVerticePorId(GR* grafo, int id);

/**
 * @brief Remove um vértice do grafo pelo seu ID.
 * Também remove as arestas associadas ao vértice.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do vértice a remover.
 * @return 0 se removido com sucesso, -1 se erro ou não encontrado.
 */
int removerVerticePorId(GR* grafo, int id);

#endif
