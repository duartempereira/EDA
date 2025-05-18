/**
 * @file Structs.h
 * @brief Definição das estruturas para representar grafos de antenas com frequências e posições.
 *
 * @details Este ficheiro contém as definições das estruturas usadas para representar um grafo
 * onde cada vértice corresponde a uma antena com frequência e coordenadas, e as arestas representam ligações entre antenas.
 * Inclui também a estrutura do grafo que contém a lista de vértices e dimensões do mapa.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#ifndef STRUCTS_H
#define STRUCTS_H

 /**
  * @struct Aresta
  * @brief Representa uma ligação (aresta) entre vértices no grafo.
  *
  * Cada aresta tem um destino (apontador para vértice destino), um peso (ex: distância)
  * e um apontador para a próxima aresta da lista ligada do vértice de origem.
  *
  * @param destino Apontador para o vértice destino desta aresta.
  * @param peso Peso da aresta, geralmente uma métrica como distância.
  * @param next Apontador para a próxima aresta na lista ligada do vértice origem.
  */
typedef struct Aresta {
    struct Vertice* destino;   /**< Vértice destino da aresta */
    float peso;                /**< Peso da aresta (ex: distância) */
    struct Aresta* next;       /**< Próxima aresta na lista ligada */
} Aresta;

/**
 * @struct Vertice
 * @brief Representa um vértice no grafo, correspondente a uma antena.
 *
 * Cada vértice tem um ID único, uma frequência (carácter), coordenadas (x,y),
 * um indicador se foi visitado em procuras, uma lista de arestas adjacentes e
 * um apontador para o próximo vértice na lista do grafo.
 *
 * @param id Identificador único do vértice.
 * @param frequencia Frequência da antena representada por um carácter.
 * @param x Coordenada x no mapa.
 * @param y Coordenada y no mapa.
 * @param visitado Flag para marcar se o vértice foi visitado em procuras.
 * @param adj Lista ligada de arestas (vizinhos).
 * @param next Próximo vértice na lista do grafo.
 */
typedef struct Vertice {
    int id;               /**< ID do vértice */
    char frequencia;      /**< Frequência da antena */
    int x, y;             /**< Coordenadas no mapa */
    int visitado;         /**< Flag para procuras */
    Aresta* adj;          /**< Lista ligada de arestas adjacentes */
    struct Vertice* next; /**< Próximo vértice na lista do grafo */
} Vertice;

/**
 * @struct GR
 * @brief Representa o grafo, contendo a lista de vértices e dimensões do mapa.
 *
 * O grafo armazena a lista ligada de vértices, o número total de vértices,
 * e as dimensões (linhas e colunas) do mapa de antenas.
 *
 * @param vertices Apontador para a lista ligada de vértices.
 * @param numVertices Número total de vértices no grafo.
 * @param linhas Número de linhas do mapa.
 * @param colunas Número máximo de colunas do mapa.
 */
typedef struct GR {
    Vertice* vertices;  /**< Lista ligada de vértices */
    int numVertices;    /**< Número total de vértices */
    int linhas;         /**< Número de linhas do mapa */
    int colunas;        /**< Número máximo de colunas do mapa */
} GR;

#endif // STRUCTS_H
