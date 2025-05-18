#ifndef FUNCOESVERTICE_H
#define FUNCOESVERTICE_H

/**
 * @file FuncoesVertice.h
 * @brief Declara��o das fun��es para manipula��o de v�rtices num grafo.
 *
 * Inclui cria��o, adi��o, remo��o, procura e impress�o de v�rtices.
 * Cada v�rtice representa uma antena com uma frequ�ncia e coordenadas (x,y).
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Cria um novo v�rtice com ID, frequ�ncia e coordenadas fornecidas.
  *
  * @param id Identificador �nico do v�rtice.
  * @param frequencia Car�cter que representa a frequ�ncia da antena.
  * @param x Coordenada x do v�rtice no mapa.
  * @param y Coordenada y do v�rtice no mapa.
  * @return Apontador para o v�rtice criado ou NULL em caso de erro.
  */
Vertice* criarVertice(int id, char frequencia, int x, int y);

/**
 * @brief Adiciona um v�rtice ao grafo.
 * Atualiza as dimens�es do grafo se necess�rio.
 *
 * @param grafo Apontador para o grafo onde o v�rtice ser� adicionado.
 * @param vertice Apontador para o v�rtice a adicionar.
 * @return 0 se sucesso, -1 em caso de erro.
 */
int adicionarVertice(GR* grafo, Vertice* vertice);

/**
 * @brief Imprime informa��o detalhada de um v�rtice.
 *
 * @param v Apontador para o v�rtice a imprimir.
 */
void imprimirVertice(Vertice* v);

/**
 * @brief Lista todos os v�rtices do grafo imprimindo-os um a um.
 *
 * @param grafo Apontador para o grafo.
 */
void listarVertices(GR* grafo);

/**
 * @brief Altera a frequ�ncia de um v�rtice.
 *
 * @param v Apontador para o v�rtice a alterar.
 * @param novaFreq Novo car�cter da frequ�ncia.
 * @return 1 se a frequ�ncia foi alterada, 0 se o v�rtice for NULL.
 */
int alterarFrequenciaVertice(Vertice* v, char novaFreq);

/**
 * @brief Procura um v�rtice no grafo pelas suas coordenadas (x, y).
 *
 * @param grafo Apontador para o grafo.
 * @param x Coordenada x do v�rtice a procurar.
 * @param y Coordenada y do v�rtice a procurar.
 * @return Apontador para o v�rtice encontrado ou NULL se n�o existir.
 */
Vertice* procurarVerticePorCoordenadas(GR* grafo, int x, int y);

/**
 * @brief Procura um v�rtice no grafo pelo seu ID.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do v�rtice a procurar.
 * @return Apontador para o v�rtice encontrado ou NULL se n�o existir.
 */
Vertice* procurarVerticePorId(GR* grafo, int id);

/**
 * @brief Remove um v�rtice do grafo pelo seu ID.
 * Tamb�m remove as arestas associadas ao v�rtice.
 *
 * @param grafo Apontador para o grafo.
 * @param id ID do v�rtice a remover.
 * @return 0 se removido com sucesso, -1 se erro ou n�o encontrado.
 */
int removerVerticePorId(GR* grafo, int id);

#endif
