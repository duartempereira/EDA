/**
 * @file Structs.h
 * @brief Definição das estruturas utilizadas para representar antenas e localizações com efeitos nefastos.
 *
 * @details Este ficheiro contém as definições das estruturas de dados para uma antena e uma localização com efeito nefasto.
 * A estrutura `Antena` é utilizada para armazenar as informações de cada antena, incluindo a sua frequência e coordenadas,
 * enquanto a estrutura `Nefasto` representa as localizações com efeitos nefastos, com suas respectivas coordenadas.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

#ifndef STRUCTS_H
#define STRUCTS_H

 /**
  * @struct Antena
  * @brief Representa uma antena com uma frequência e coordenadas no mapa.
  *
  * Esta estrutura armazena as informações de uma antena, incluindo sua frequência,
  * as coordenadas `x` e `y` e um ponteiro para o próximo elemento da lista ligada.
  *
  * @param frequencia A frequência da antena, representada por um caractere.
  * @param x A coordenada X da antena no mapa.
  * @param y A coordenada Y da antena no mapa.
  * @param prox Ponteiro para a próxima antena na lista ligada.
  */
typedef struct Antena {
    char frequencia;  /**< Frequência da antena */
    int x, y;         /**< Coordenadas X e Y da antena */
    struct Antena* prox; /**< Ponteiro para a próxima antena */
} Antena;

/**
 * @struct Nefasto
 * @brief Representa uma localização com efeitos nefastos no mapa.
 *
 * Esta estrutura armazena as coordenadas de uma localização que possui um efeito
 * nefasto. A estrutura é utilizada em listas ligadas para armazenar tais posições
 * no mapa.
 *
 * @param x A coordenada X da localização nefasto.
 * @param y A coordenada Y da localização nefasto.
 * @param prox Ponteiro para a próxima localização nefasto na lista ligada.
 */
typedef struct Nefasto {
    int x, y;         /**< Coordenadas X e Y da localização nefasto */
    struct Nefasto* prox; /**< Ponteiro para o próximo nefasto */
} Nefasto;

#endif