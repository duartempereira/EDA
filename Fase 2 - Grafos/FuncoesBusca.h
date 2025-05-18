#ifndef FUNCOESBUSCA_H
#define FUNCOESBUSCA_H

/**
 * @file FuncoesBusca.h
 * @brief Declara��o das fun��es para realiza��o de procuras em grafos.
 *
 * Cont�m fun��es para resetar estado de visitados, procuras em profundidade e largura,
 * al�m de fun��es auxiliares para encontrar e imprimir caminhos.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Reseta o estado 'visitado' de todos os v�rtices do grafo para 0.
  *
  * @param grafo Apontador para o grafo onde os v�rtices ser�o resetados.
  * @return int 1 se sucesso, 0 se grafo inv�lido.
  */
int resetarVisitados(GR* grafo);

/**
 * @brief Obt�m o primeiro vizinho adjacente n�o visitado de um v�rtice.
 *
 * @param v Apontador para o v�rtice.
 * @return Vertice* Apontador para o vizinho n�o visitado ou NULL se n�o existir.
 */
Vertice* getVizinhoNaoVisitado(Vertice* v);

/**
 * @brief Realiza uma procura em profundidade (Depth-First Traversal) a partir de um v�rtice.
 * Marca os v�rtices visitados e imprime-os durante a visita.
 *
 * @param v Apontador para o v�rtice inicial.
 * @return int N�mero de v�rtices visitados.
 */
int dft(Vertice* v);

/**
 * @brief Verifica se uma fila est� vazia dado o �ndice de in�cio e fim.
 *
 * @param inicio �ndice do in�cio da fila.
 * @param fim �ndice do fim da fila.
 * @return int 1 se fila vazia, 0 caso contr�rio.
 */
int filaVazia(int inicio, int fim);

/**
 * @brief Realiza uma procura em largura (Breadth-First Traversal) a partir de um v�rtice.
 * Marca os v�rtices visitados e imprime-os durante a visita.
 *
 * @param inicio Apontador para o v�rtice inicial.
 * @return int N�mero de v�rtices visitados.
 */
int bft(Vertice* inicio);

/**
 * @brief Imprime o caminho formado por um array de v�rtices.
 *
 * @param caminho Array de apontadores para os v�rtices que formam o caminho.
 * @param tamanho N�mero de v�rtices no caminho.
 */
void imprimirCaminho(Vertice* caminho[], int tamanho);

/**
 * @brief Encontra e imprime todos os caminhos poss�veis entre dois v�rtices no grafo.
 * Usa procura recursiva para explorar todos os caminhos sem repetir v�rtices.
 *
 * @param atual V�rtice atual da procura.
 * @param destino V�rtice destino da procura.
 * @param caminho Array auxiliar para armazenar o caminho atual.
 * @param pos Posi��o atual no array caminho.
 * @return int N�mero total de caminhos encontrados.
 */
int encontrarTodosCaminhos(Vertice* atual, Vertice* destino, Vertice* caminho[], int pos);

#endif // FUNCOESBUSCA_H
