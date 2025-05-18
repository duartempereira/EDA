#ifndef FUNCOESFICHEIRO_H
#define FUNCOESFICHEIRO_H

/**
 * @file FuncoesFicheiro.h
 * @brief Declaração da função para carregar um mapa de antenas a partir de ficheiro para o grafo.
 *
 * Contém a função que lê um ficheiro de texto com a representação do mapa e cria os vértices
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
  * Lê um ficheiro onde cada linha representa uma linha do mapa e cada caractere uma célula.
  * Cria vértices no grafo para cada antena detectada (carácter diferente de '.').
  * Atualiza as dimensões do grafo (linhas e colunas) e o número de vértices.
  *
  * @param grafo Apontador para o grafo onde os vértices serão adicionados.
  * @param nomeFicheiro Nome do ficheiro a ler.
  * @return int 0 em sucesso, -1 em caso de erro (ex: ficheiro não encontrado).
  */
int carregarMapaNoGrafo(GR* grafo, const char* nomeFicheiro);

#endif // FUNCOESFICHEIRO_H
