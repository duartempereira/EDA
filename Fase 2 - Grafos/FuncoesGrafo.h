#ifndef FUNCOESGRAFO_H
#define FUNCOESGRAFO_H

/**
 * @file FuncoesGrafo.h
 * @brief Declaração das funções para criação, impressão e libertação de um grafo.
 *
 * Este ficheiro define funções para criar um grafo vazio, imprimir o seu mapa
 * e libertar toda a memória alocada para o grafo.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Cria um grafo vazio alocando memória e inicializando os seus campos.
  *
  * @return Apontador para o grafo criado. Retorna NULL em caso de falha de alocação.
  */
GR* criarGrafo();

/**
 * @brief Imprime o mapa do grafo, representando os vértices (antenas) na sua posição.
 *
 * Usa a informação das coordenadas para montar uma matriz visual do grafo,
 * imprimindo '.' onde não há antenas.
 *
 * @param grafo Apontador para o grafo a imprimir.
 */
void imprimirMapa(GR* grafo);

/**
 * @brief Liberta toda a memória alocada para o grafo, incluindo vértices e arestas.
 *
 * Depois de libertar, o apontador do grafo torna-se inválido.
 *
 * @param grafo Apontador para o grafo a libertar.
 * @return 0 em sucesso, -1 se o grafo for NULL.
 */
int libertarGrafo(GR* grafo);

#endif // FUNCOESGRAFO_H
