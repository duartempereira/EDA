/**
 * @file FuncoesLista.h
 * @brief Declaração das funções para manipulação de listas de antenas.
 *
 * @details Este ficheiro contém as declarações das funções utilizadas para manipular uma lista ligada de antenas,
 * incluindo a criação, inserção, remoção e destruição da lista, bem como a listagem e a visualização das antenas em
 * um mapa.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

#ifndef FUNCOESLISTA_H
#define FUNCOESLISTA_H

#include "Structs.h"

 /**
  * @brief Cria uma nova antena com os parâmetros fornecidos.
  *
  * Aloca memória para uma nova antena e inicializa os seus valores com as coordenadas
  * fornecidas e a frequência.
  *
  * @param frequencia A frequência da antena.
  * @param x A coordenada X da antena.
  * @param y A coordenada Y da antena.
  * @return Um ponteiro para a nova antena criada ou NULL caso a alocação falhe.
  */
Antena* CriarAntena(char frequencia, int x, int y);

/**
 * @brief Insere uma nova antena no início da lista.
 *
 * Cria uma nova antena com os parâmetros fornecidos e a insere no início da lista.
 * A lista resultante terá a nova antena como o primeiro elemento.
 *
 * @param lista A lista atual de antenas.
 * @param freq A frequência da nova antena.
 * @param x A coordenada X da nova antena.
 * @param y A coordenada Y da nova antena.
 * @return A nova lista com a antena inserida no início.
 */
Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y);

/**
 * @brief Insere uma nova antena no final da lista.
 *
 * Cria uma nova antena com os parâmetros fornecidos e a insere no final da lista.
 *
 * @param lista A lista atual de antenas.
 * @param freq A frequência da nova antena.
 * @param x A coordenada X da nova antena.
 * @param y A coordenada Y da nova antena.
 * @return A lista com a nova antena inserida no final.
 */
Antena* InserirAntenaFim(Antena* lista, char freq, int x, int y);

/**
 * @brief Remove uma antena da lista, dado as suas coordenadas.
 *
 * Remove a antena da lista que corresponde às coordenadas (x, y) fornecidas.
 * Se a antena não for encontrada, a lista não é alterada.
 *
 * @param lista A lista de antenas.
 * @param x A coordenada X da antena a remover.
 * @param y A coordenada Y da antena a remover.
 * @return A lista atualizada, com a antena removida, ou a lista original caso não encontre a antena.
 */
Antena* RemoverAntena(Antena* lista, int x, int y);

/**
 * @brief Destrói a lista de antenas, liberando a memória alocada.
 *
 * Libera toda a memória associada aos elementos da lista de antenas.
 * A lista é destruída completamente e o ponteiro é retornado como NULL.
 *
 * @param lista A lista de antenas a ser destruída.
 * @return NULL, pois a lista foi destruída.
 */
Antena* DestroiLista(Antena* lista);

/**
 * @brief Lista as antenas presentes na lista ligada.
 *
 * Exibe no terminal as informações de todas as antenas presentes na lista,
 * incluindo a sua frequência e coordenadas.
 *
 * @param lista A lista de antenas.
 */
void ListarAntenas(Antena* lista);

/**
 * @brief Mostra um mapa com as antenas, de acordo com as suas coordenadas.
 *
 * Exibe um mapa em formato de matriz, onde as posições das antenas são marcadas
 * com a sua frequência. As posições vazias são representadas por pontos (`.`).
 *
 * @param lista A lista de antenas.
 * @param numLinhas O número de linhas do mapa.
 * @param numColunas O número de colunas do mapa.
 */
void MostrarMapaAntenas(Antena* lista, int numLinhas, int numColunas);

#endif
