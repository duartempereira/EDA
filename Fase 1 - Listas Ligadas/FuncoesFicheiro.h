/**
 * @file FuncoesFicheiro.h
 * @brief Declaração das funções para manipulação de ficheiros de antenas.
 *
 * @details Este ficheiro contém as declarações das funções utilizadas para ler
 * um ficheiro de texto contendo informações sobre antenas e posicioná-las numa lista ligada.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

#ifndef FUNCOESFICHEIRO_H
#define FUNCOESFICHEIRO_H

#include "Structs.h"

 /**
  * @brief Lê um ficheiro e insere as antenas na lista ligada.
  *
  * Esta função abre um ficheiro de texto e lê as informações sobre as antenas
  * e suas localizações. As antenas são inseridas numa lista ligada com base nos dados
  * lidos do ficheiro. O número de linhas e colunas do mapa também são atualizados.
  *
  * @param nomeFicheiro O nome do ficheiro que contém os dados das antenas.
  * @param lista A lista de antenas onde as antenas lidas do ficheiro serão inseridas.
  * @param numLinhas Ponteiro para variável que armazenará o número de linhas do mapa.
  * @param numColunas Ponteiro para variável que armazenará o número de colunas do mapa.
  * @return A lista de antenas com as novas antenas inseridas.
  */
Antena* LerFicheiro(char* nomeFicheiro, Antena* lista, int* numLinhas, int* numColunas);

#endif