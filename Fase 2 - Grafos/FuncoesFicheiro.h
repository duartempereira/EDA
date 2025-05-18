#ifndef FUNCOESFICHEIRO_H
#define FUNCOESFICHEIRO_H

/**
 * @file FuncoesFicheiro.h
 * @brief Declara��o da fun��o para carregar um mapa de antenas a partir de ficheiro para o grafo.
 *
 * Cont�m a fun��o que l� um ficheiro de texto com a representa��o do mapa e cria os v�rtices
 * correspondentes no grafo.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include "Structs.h"

 /**
  * @brief Carrega o mapa de antenas de um ficheiro de texto para o grafo.
  *
  * L� um ficheiro onde cada linha representa uma linha do mapa e cada caractere uma c�lula.
  * Cria v�rtices no grafo para cada antena detectada (car�cter diferente de '.').
  * Atualiza as dimens�es do grafo (linhas e colunas) e o n�mero de v�rtices.
  *
  * @param grafo Apontador para o grafo onde os v�rtices ser�o adicionados.
  * @param nomeFicheiro Nome do ficheiro a ler.
  * @return int 0 em sucesso, -1 em caso de erro (ex: ficheiro n�o encontrado).
  */
int carregarMapaNoGrafo(GR* grafo, const char* nomeFicheiro);

#endif // FUNCOESFICHEIRO_H
