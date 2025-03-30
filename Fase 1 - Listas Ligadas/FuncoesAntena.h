/**
 * @file FuncoesLista.h
 * @brief Declara��o das fun��es para manipula��o de listas de antenas.
 *
 * @details Este ficheiro cont�m as declara��es das fun��es utilizadas para manipular uma lista ligada de antenas,
 * incluindo a cria��o, inser��o, remo��o e destrui��o da lista, bem como a listagem e a visualiza��o das antenas em
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
  * @brief Cria uma nova antena com os par�metros fornecidos.
  *
  * Aloca mem�ria para uma nova antena e inicializa os seus valores com as coordenadas
  * fornecidas e a frequ�ncia.
  *
  * @param frequencia A frequ�ncia da antena.
  * @param x A coordenada X da antena.
  * @param y A coordenada Y da antena.
  * @return Um ponteiro para a nova antena criada ou NULL caso a aloca��o falhe.
  */
Antena* CriarAntena(char frequencia, int x, int y);

/**
 * @brief Insere uma nova antena no in�cio da lista.
 *
 * Cria uma nova antena com os par�metros fornecidos e a insere no in�cio da lista.
 * A lista resultante ter� a nova antena como o primeiro elemento.
 *
 * @param lista A lista atual de antenas.
 * @param freq A frequ�ncia da nova antena.
 * @param x A coordenada X da nova antena.
 * @param y A coordenada Y da nova antena.
 * @return A nova lista com a antena inserida no in�cio.
 */
Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y);

/**
 * @brief Insere uma nova antena no final da lista.
 *
 * Cria uma nova antena com os par�metros fornecidos e a insere no final da lista.
 *
 * @param lista A lista atual de antenas.
 * @param freq A frequ�ncia da nova antena.
 * @param x A coordenada X da nova antena.
 * @param y A coordenada Y da nova antena.
 * @return A lista com a nova antena inserida no final.
 */
Antena* InserirAntenaFim(Antena* lista, char freq, int x, int y);

/**
 * @brief Remove uma antena da lista, dado as suas coordenadas.
 *
 * Remove a antena da lista que corresponde �s coordenadas (x, y) fornecidas.
 * Se a antena n�o for encontrada, a lista n�o � alterada.
 *
 * @param lista A lista de antenas.
 * @param x A coordenada X da antena a remover.
 * @param y A coordenada Y da antena a remover.
 * @return A lista atualizada, com a antena removida, ou a lista original caso n�o encontre a antena.
 */
Antena* RemoverAntena(Antena* lista, int x, int y);

/**
 * @brief Destr�i a lista de antenas, liberando a mem�ria alocada.
 *
 * Libera toda a mem�ria associada aos elementos da lista de antenas.
 * A lista � destru�da completamente e o ponteiro � retornado como NULL.
 *
 * @param lista A lista de antenas a ser destru�da.
 * @return NULL, pois a lista foi destru�da.
 */
Antena* DestroiLista(Antena* lista);

/**
 * @brief Lista as antenas presentes na lista ligada.
 *
 * Exibe no terminal as informa��es de todas as antenas presentes na lista,
 * incluindo a sua frequ�ncia e coordenadas.
 *
 * @param lista A lista de antenas.
 */
void ListarAntenas(Antena* lista);

/**
 * @brief Mostra um mapa com as antenas, de acordo com as suas coordenadas.
 *
 * Exibe um mapa em formato de matriz, onde as posi��es das antenas s�o marcadas
 * com a sua frequ�ncia. As posi��es vazias s�o representadas por pontos (`.`).
 *
 * @param lista A lista de antenas.
 * @param numLinhas O n�mero de linhas do mapa.
 * @param numColunas O n�mero de colunas do mapa.
 */
void MostrarMapaAntenas(Antena* lista, int numLinhas, int numColunas);

#endif
