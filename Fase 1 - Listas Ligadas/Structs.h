/**
 * @file Structs.h
 * @brief Defini��o das estruturas utilizadas para representar antenas e localiza��es com efeitos nefastos.
 *
 * @details Este ficheiro cont�m as defini��es das estruturas de dados para uma antena e uma localiza��o com efeito nefasto.
 * A estrutura `Antena` � utilizada para armazenar as informa��es de cada antena, incluindo a sua frequ�ncia e coordenadas,
 * enquanto a estrutura `Nefasto` representa as localiza��es com efeitos nefastos, com suas respectivas coordenadas.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

#ifndef STRUCTS_H
#define STRUCTS_H

 /**
  * @struct Antena
  * @brief Representa uma antena com uma frequ�ncia e coordenadas no mapa.
  *
  * Esta estrutura armazena as informa��es de uma antena, incluindo sua frequ�ncia,
  * as coordenadas `x` e `y` e um ponteiro para o pr�ximo elemento da lista ligada.
  *
  * @param frequencia A frequ�ncia da antena, representada por um caractere.
  * @param x A coordenada X da antena no mapa.
  * @param y A coordenada Y da antena no mapa.
  * @param prox Ponteiro para a pr�xima antena na lista ligada.
  */
typedef struct Antena {
    char frequencia;  /**< Frequ�ncia da antena */
    int x, y;         /**< Coordenadas X e Y da antena */
    struct Antena* prox; /**< Ponteiro para a pr�xima antena */
} Antena;

/**
 * @struct Nefasto
 * @brief Representa uma localiza��o com efeitos nefastos no mapa.
 *
 * Esta estrutura armazena as coordenadas de uma localiza��o que possui um efeito
 * nefasto. A estrutura � utilizada em listas ligadas para armazenar tais posi��es
 * no mapa.
 *
 * @param x A coordenada X da localiza��o nefasto.
 * @param y A coordenada Y da localiza��o nefasto.
 * @param prox Ponteiro para a pr�xima localiza��o nefasto na lista ligada.
 */
typedef struct Nefasto {
    int x, y;         /**< Coordenadas X e Y da localiza��o nefasto */
    struct Nefasto* prox; /**< Ponteiro para o pr�ximo nefasto */
} Nefasto;

#endif