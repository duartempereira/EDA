#ifndef FUNCOESGRAFO_H
#define FUNCOESGRAFO_H

/**
 * @file FuncoesGrafo.h
 * @brief Declara��o das fun��es para cria��o, impress�o e liberta��o de um grafo.
 *
 * Este ficheiro define fun��es para criar um grafo vazio, imprimir o seu mapa
 * e libertar toda a mem�ria alocada para o grafo.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Cria um grafo vazio alocando mem�ria e inicializando os seus campos.
  *
  * @return Apontador para o grafo criado. Retorna NULL em caso de falha de aloca��o.
  */
GR* criarGrafo();

/**
 * @brief Imprime o mapa do grafo, representando os v�rtices (antenas) na sua posi��o.
 *
 * Usa a informa��o das coordenadas para montar uma matriz visual do grafo,
 * imprimindo '.' onde n�o h� antenas.
 *
 * @param grafo Apontador para o grafo a imprimir.
 */
void imprimirMapa(GR* grafo);

/**
 * @brief Liberta toda a mem�ria alocada para o grafo, incluindo v�rtices e arestas.
 *
 * Depois de libertar, o apontador do grafo torna-se inv�lido.
 *
 * @param grafo Apontador para o grafo a libertar.
 * @return 0 em sucesso, -1 se o grafo for NULL.
 */
int libertarGrafo(GR* grafo);

#endif // FUNCOESGRAFO_H
