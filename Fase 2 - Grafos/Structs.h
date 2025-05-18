/**
 * @file Structs.h
 * @brief Defini��o das estruturas para representar grafos de antenas com frequ�ncias e posi��es.
 *
 * @details Este ficheiro cont�m as defini��es das estruturas usadas para representar um grafo
 * onde cada v�rtice corresponde a uma antena com frequ�ncia e coordenadas, e as arestas representam liga��es entre antenas.
 * Inclui tamb�m a estrutura do grafo que cont�m a lista de v�rtices e dimens�es do mapa.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#ifndef STRUCTS_H
#define STRUCTS_H

 /**
  * @struct Aresta
  * @brief Representa uma liga��o (aresta) entre v�rtices no grafo.
  *
  * Cada aresta tem um destino (apontador para v�rtice destino), um peso (ex: dist�ncia)
  * e um apontador para a pr�xima aresta da lista ligada do v�rtice de origem.
  *
  * @param destino Apontador para o v�rtice destino desta aresta.
  * @param peso Peso da aresta, geralmente uma m�trica como dist�ncia.
  * @param next Apontador para a pr�xima aresta na lista ligada do v�rtice origem.
  */
typedef struct Aresta {
    struct Vertice* destino;   /**< V�rtice destino da aresta */
    float peso;                /**< Peso da aresta (ex: dist�ncia) */
    struct Aresta* next;       /**< Pr�xima aresta na lista ligada */
} Aresta;

/**
 * @struct Vertice
 * @brief Representa um v�rtice no grafo, correspondente a uma antena.
 *
 * Cada v�rtice tem um ID �nico, uma frequ�ncia (car�cter), coordenadas (x,y),
 * um indicador se foi visitado em procuras, uma lista de arestas adjacentes e
 * um apontador para o pr�ximo v�rtice na lista do grafo.
 *
 * @param id Identificador �nico do v�rtice.
 * @param frequencia Frequ�ncia da antena representada por um car�cter.
 * @param x Coordenada x no mapa.
 * @param y Coordenada y no mapa.
 * @param visitado Flag para marcar se o v�rtice foi visitado em procuras.
 * @param adj Lista ligada de arestas (vizinhos).
 * @param next Pr�ximo v�rtice na lista do grafo.
 */
typedef struct Vertice {
    int id;               /**< ID do v�rtice */
    char frequencia;      /**< Frequ�ncia da antena */
    int x, y;             /**< Coordenadas no mapa */
    int visitado;         /**< Flag para procuras */
    Aresta* adj;          /**< Lista ligada de arestas adjacentes */
    struct Vertice* next; /**< Pr�ximo v�rtice na lista do grafo */
} Vertice;

/**
 * @struct GR
 * @brief Representa o grafo, contendo a lista de v�rtices e dimens�es do mapa.
 *
 * O grafo armazena a lista ligada de v�rtices, o n�mero total de v�rtices,
 * e as dimens�es (linhas e colunas) do mapa de antenas.
 *
 * @param vertices Apontador para a lista ligada de v�rtices.
 * @param numVertices N�mero total de v�rtices no grafo.
 * @param linhas N�mero de linhas do mapa.
 * @param colunas N�mero m�ximo de colunas do mapa.
 */
typedef struct GR {
    Vertice* vertices;  /**< Lista ligada de v�rtices */
    int numVertices;    /**< N�mero total de v�rtices */
    int linhas;         /**< N�mero de linhas do mapa */
    int colunas;        /**< N�mero m�ximo de colunas do mapa */
} GR;

#endif // STRUCTS_H
