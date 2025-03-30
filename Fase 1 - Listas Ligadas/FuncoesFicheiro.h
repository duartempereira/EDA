/**
 * @file FuncoesFicheiro.h
 * @brief Declara��o das fun��es para manipula��o de ficheiros de antenas.
 *
 * @details Este ficheiro cont�m as declara��es das fun��es utilizadas para ler
 * um ficheiro de texto contendo informa��es sobre antenas e posicion�-las numa lista ligada.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

#ifndef FUNCOESFICHEIRO_H
#define FUNCOESFICHEIRO_H

#include "Structs.h"

 /**
  * @brief L� um ficheiro e insere as antenas na lista ligada.
  *
  * Esta fun��o abre um ficheiro de texto e l� as informa��es sobre as antenas
  * e suas localiza��es. As antenas s�o inseridas numa lista ligada com base nos dados
  * lidos do ficheiro. O n�mero de linhas e colunas do mapa tamb�m s�o atualizados.
  *
  * @param nomeFicheiro O nome do ficheiro que cont�m os dados das antenas.
  * @param lista A lista de antenas onde as antenas lidas do ficheiro ser�o inseridas.
  * @param numLinhas Ponteiro para vari�vel que armazenar� o n�mero de linhas do mapa.
  * @param numColunas Ponteiro para vari�vel que armazenar� o n�mero de colunas do mapa.
  * @return A lista de antenas com as novas antenas inseridas.
  */
Antena* LerFicheiro(char* nomeFicheiro, Antena* lista, int* numLinhas, int* numColunas);

#endif