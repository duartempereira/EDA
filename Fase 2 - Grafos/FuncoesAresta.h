#ifndef FUNCOESARESTA_H
#define FUNCOESARESTA_H

/**
 * @file FuncoesAresta.h
 * @brief Declara��o das fun��es para manipula��o de arestas no grafo.
 *
 * Cont�m fun��es para adicionar, criar, remover, libertar e listar arestas entre v�rtices.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Adiciona uma aresta entre dois v�rtices com um peso definido.
  *
  * @param origem Apontador para o v�rtice de origem.
  * @param destino Apontador para o v�rtice de destino.
  * @param peso Peso da aresta (por exemplo, dist�ncia ou custo).
  * @return int 0 se sucesso, valor negativo em caso de erro.
  */
int adicionarAresta(Vertice* origem, Vertice* destino, float peso);

/**
 * @brief Cria arestas entre v�rtices adjacentes no grafo que tenham a mesma frequ�ncia.
 *
 * @param grafo Apontador para o grafo.
 * @return int 0 se sucesso, valor negativo em caso de erro.
 */
int criarArestasAdjacentes(GR* grafo);

/**
 * @brief Remove todas as arestas que apontam para um v�rtice espec�fico.
 *
 * @param grafo Apontador para o grafo.
 * @param alvo Apontador para o v�rtice alvo cujas arestas ser�o removidas.
 * @return int 0 se sucesso, valor negativo em caso de erro.
 */
int removerArestasParaVertice(GR* grafo, Vertice* alvo);

/**
 * @brief Liberta a mem�ria das arestas associadas a um v�rtice.
 *
 * @param v Apontador para o v�rtice cujas arestas ser�o libertadas.
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
