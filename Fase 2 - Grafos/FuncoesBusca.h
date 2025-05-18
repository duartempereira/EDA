#ifndef FUNCOESBUSCA_H
#define FUNCOESBUSCA_H

/**
 * @file FuncoesBusca.h
 * @brief Declaração das funções para realização de procuras em grafos.
 *
 * Contém funções para resetar estado de visitados, procuras em profundidade e largura,
 * além de funções auxiliares para encontrar e imprimir caminhos.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Reseta o estado 'visitado' de todos os vértices do grafo para 0.
  *
  * @param grafo Apontador para o grafo onde os vértices serão resetados.
  * @return int 1 se sucesso, 0 se grafo inválido.
  */
int resetarVisitados(GR* grafo);

/**
 * @brief Obtém o primeiro vizinho adjacente não visitado de um vértice.
 *
 * @param v Apontador para o vértice.
 * @return Vertice* Apontador para o vizinho não visitado ou NULL se não existir.
 */
Vertice* getVizinhoNaoVisitado(Vertice* v);

/**
 * @brief Realiza uma procura em profundidade (Depth-First Traversal) a partir de um vértice.
 * Marca os vértices visitados e imprime-os durante a visita.
 *
 * @param v Apontador para o vértice inicial.
 * @return int Número de vértices visitados.
 */
int dft(Vertice* v);

/**
 * @brief Verifica se uma fila está vazia dado o índice de início e fim.
 *
 * @param inicio Índice do início da fila.
 * @param fim Índice do fim da fila.
 * @return int 1 se fila vazia, 0 caso contrário.
 */
int filaVazia(int inicio, int fim);

/**
 * @brief Realiza uma procura em largura (Breadth-First Traversal) a partir de um vértice.
 * Marca os vértices visitados e imprime-os durante a visita.
 *
 * @param inicio Apontador para o vértice inicial.
 * @return int Número de vértices visitados.
 */
int bft(Vertice* inicio);

/**
 * @brief Imprime o caminho formado por um array de vértices.
 *
 * @param caminho Array de apontadores para os vértices que formam o caminho.
 * @param tamanho Número de vértices no caminho.
 */
void imprimirCaminho(Vertice* caminho[], int tamanho);

/**
 * @brief Encontra e imprime todos os caminhos possíveis entre dois vértices no grafo.
 * Usa procura recursiva para explorar todos os caminhos sem repetir vértices.
 *
 * @param atual Vértice atual da procura.
 * @param destino Vértice destino da procura.
 * @param caminho Array auxiliar para armazenar o caminho atual.
 * @param pos Posição atual no array caminho.
 * @return int Número total de caminhos encontrados.
 */
int encontrarTodosCaminhos(Vertice* atual, Vertice* destino, Vertice* caminho[], int pos);

#endif // FUNCOESBUSCA_H
