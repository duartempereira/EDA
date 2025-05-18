#ifndef FUNCOESARESTA_H
#define FUNCOESARESTA_H

/**
 * @file FuncoesAresta.h
 * @brief Declaração das funções para manipulação de arestas no grafo.
 *
 * Contém funções para adicionar, criar, remover, libertar e listar arestas entre vértices.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Adiciona uma aresta entre dois vértices com um peso definido.
  *
  * @param origem Apontador para o vértice de origem.
  * @param destino Apontador para o vértice de destino.
  * @param peso Peso da aresta (por exemplo, distância ou custo).
  * @return int 0 se sucesso, valor negativo em caso de erro.
  */
int adicionarAresta(Vertice* origem, Vertice* destino, float peso);

/**
 * @brief Cria arestas entre vértices adjacentes no grafo que tenham a mesma frequência.
 *
 * @param grafo Apontador para o grafo.
 * @return int 0 se sucesso, valor negativo em caso de erro.
 */
int criarArestasAdjacentes(GR* grafo);

/**
 * @brief Remove todas as arestas que apontam para um vértice específico.
 *
 * @param grafo Apontador para o grafo.
 * @param alvo Apontador para o vértice alvo cujas arestas serão removidas.
 * @return int 0 se sucesso, valor negativo em caso de erro.
 */
int removerArestasParaVertice(GR* grafo, Vertice* alvo);

/**
 * @brief Liberta a memória das arestas associadas a um vértice.
 *
 * @param v Apontador para o vértice cujas arestas serão libertadas.
 * @return int 0 se sucesso, valor negativo em caso de erro.
 */
int libertarArestasDoVertice(Vertice* v);

/**
 * @brief Lista todas as arestas presentes no grafo.
 *
 * @param grafo Apontador para o grafo.
 */
void listarArestas(GR* grafo);

#endif // FUNCOESARESTA_H
