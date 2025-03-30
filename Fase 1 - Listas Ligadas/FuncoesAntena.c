/**
 * @file FuncoesAntenas.c
 * @brief Implementa��o de fun��es para manipula��o de antenas.
 *
 * @details Este ficheiro cont�m fun��es para criar, inserir, remover e listar antenas,
 * bem como gerar um mapa com as antenas posicionadas.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-03-30
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Structs.h"

 /**
  * @brief Cria uma nova antena.
  *
  * Esta fun��o aloca mem�ria para uma nova antena e inicializa os seus campos com os valores fornecidos.
  *
  * @param frequencia A frequ�ncia da antena.
  * @param x A coordenada X da antena no mapa.
  * @param y A coordenada Y da antena no mapa.
  * @return Ponteiro para a nova antena criada ou NULL se falhar a aloca��o de mem�ria.
  *
  * @details
  * Esta fun��o � respons�vel pela aloca��o din�mica de mem�ria para uma estrutura do tipo
  * `Antena` e pela inicializa��o dos seus campos. A fun��o verifica se a aloca��o de mem�ria
  * foi bem-sucedida e, em caso afirmativo, inicializa os campos `frequencia`, `x`, `y` e `prox`
  * da nova antena. Se a aloca��o de mem�ria falhar, a fun��o retorna `NULL`.
  */
Antena* CriarAntena(char frequencia, int x, int y)
{
    Antena* novaAntena = (Antena*)malloc(sizeof(Antena)); // Aloca mem�ria para uma nova antena
    if (novaAntena == NULL) return NULL; // Verifica se a aloca��o falhou

    // Inicializa os campos da antena
    novaAntena->frequencia = frequencia;
    novaAntena->x = x;
    novaAntena->y = y;
    novaAntena->prox = NULL;

    return novaAntena;
}

/**
 * @brief Insere uma nova antena no in�cio da lista.
 *
 * Esta fun��o cria uma nova antena e a insere no in�cio de uma lista existente de antenas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param freq Frequ�ncia da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Ponteiro para a nova lista com a antena inserida no in�cio.
 *
 * @details
 * Ap�s criar a nova antena, a fun��o insere-a no in�cio da lista. Se a lista j� contiver
 * antenas, o ponteiro `prox` da nova antena ser� ajustado para apontar para a primeira
 * antena da lista, e a nova antena ser� o primeiro elemento da lista.
 */
Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y)
{
    Antena* novaAntena = CriarAntena(freq, x, y); // Cria nova antena
    if (novaAntena == NULL) return lista; // Se a cria��o falhar, retorna a lista sem modifica��o

    novaAntena->prox = lista;
    return novaAntena;
}

/**
 * @brief Insere uma nova antena no fim da lista.
 *
 * Esta fun��o cria uma nova antena e a insere no final de uma lista existente de antenas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param freq Frequ�ncia da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Ponteiro para a lista com a antena inserida no final.
 *
 * @details
 * Ap�s criar a nova antena, a fun��o percorre a lista at� encontrar o �ltimo elemento,
 * e ent�o insere a nova antena no final da lista. Se a lista estiver vazia, a nova antena
 * torna-se o primeiro elemento.
 */
Antena* InserirAntenaFim(Antena* lista, char freq, int x, int y)
{
    Antena* novaAntena = CriarAntena(freq, x, y);
    if (novaAntena == NULL) return lista;

    if (lista == NULL) return novaAntena; // Se a lista estiver vazia, a nova antena se torna a lista

    Antena* atual = lista;
    while (atual->prox != NULL) { // Percorre a lista at� o �ltimo elemento
        atual = atual->prox;
    }
    atual->prox = novaAntena; // Liga a nova antena ao final da lista
    return lista;
}

/**
 * @brief Remove uma antena da lista com base nas coordenadas fornecidas.
 *
 * Esta fun��o percorre a lista de antenas e remove a antena cujas coordenadas X e Y
 * coincidem com as fornecidas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param x Coordenada X da antena a ser removida.
 * @param y Coordenada Y da antena a ser removida.
 * @return Ponteiro para a lista com a antena removida, ou a lista original se n�o encontrar a antena.
 *
 * @details
 * A fun��o percorre a lista de antenas procurando uma antena com as coordenadas especificadas.
 * Se encontrada, a antena � removida da lista e a mem�ria � liberada. Se a antena estiver no in�cio
 * da lista, a fun��o ajusta o ponteiro da lista para o pr�ximo elemento.
 */
Antena* RemoverAntena(Antena* lista, int x, int y)
{
    if (lista == NULL) return NULL;

    if (lista->x == x && lista->y == y) { // Se a antena a remover est� no in�cio da lista
        Antena* aux = lista;
        lista = lista->prox;
        free(aux);
        return lista;
    }

    Antena* aux = lista;
    Antena* auxAnt = NULL;
    while (aux && (aux->x != x || aux->y != y)) { // Procura a antena na lista
        auxAnt = aux;
        aux = aux->prox;
    }
    if (aux != NULL) { // Se encontrou a antena
        auxAnt->prox = aux->prox;
        free(aux);
    }
    return lista;
}

/**
 * @brief Destr�i a lista de antenas, liberando toda a mem�ria alocada.
 *
 * Esta fun��o percorre a lista de antenas e libera a mem�ria de cada elemento.
 *
 * @param lista Ponteiro para a lista de antenas a ser destru�da.
 * @return NULL
 *
 * @details
 * A fun��o percorre toda a lista, liberando a mem�ria alocada para cada elemento. Quando
 * a lista estiver vazia, o ponteiro ser� ajustado para NULL.
 */
Antena* DestroiLista(Antena* lista)
{
    Antena* aux;
    while (lista != NULL) { // Percorre a lista e libera cada elemento
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
    return NULL;
}

/**
 * @brief Lista as antenas presentes na lista.
 *
 * Esta fun��o percorre a lista de antenas e imprime as informa��es de cada antena.
 *
 * @param lista Ponteiro para a lista de antenas a ser listada.
 *
 * @details
 * A fun��o percorre a lista e imprime para cada antena a sua frequ�ncia e as suas coordenadas.
 */
void ListarAntenas(Antena* lista)
{
    Antena* aux = lista;
    while (aux) {
        printf("Frequ�ncia: %c, Localiza��o: (%d, %d)\n", aux->frequencia, aux->y, aux->x);
        aux = aux->prox;
    }
}

/**
 * @brief Exibe um mapa com as antenas posicionadas nas coordenadas especificadas.
 *
 * Esta fun��o cria um mapa representado por um vetor de caracteres, posiciona as antenas
 * nas coordenadas fornecidas e imprime o mapa.
 *
 * @param lista Ponteiro para a lista de antenas.
 * @param numLinhas N�mero de linhas do mapa.
 * @param numColunas N�mero de colunas do mapa.
 *
 * @details
 * A fun��o cria um mapa onde cada c�lula � representada por um ponto (`.`), e depois
 * posiciona as antenas no mapa usando as coordenadas fornecidas. As antenas s�o representadas
 * pela sua frequ�ncia. Ap�s posicionar as antenas, o mapa � impresso na consola.
 */
void MostrarMapaAntenas(Antena* lista, int numLinhas, int numColunas)
{
    // Aloca mem�ria para o mapa de uma vez s� (um �nico bloco cont�nuo)
    char* mapa = (char*)malloc(numLinhas * numColunas * sizeof(char));

    if (mapa == NULL) {
        printf("Erro ao alocar mem�ria para o mapa.\n");
        return; // Se falhar a aloca��o, sai da fun��o
    }

    // Inicializa o mapa com pontos (.)
    for (int i = 0; i < numLinhas * numColunas; i++) {
        mapa[i] = '.';
    }

    Antena* aux = lista;
    while (aux != NULL) { // Posiciona as antenas no mapa
        int x = aux->x - 1;  // Ajusta para o �ndice zero
        int y = aux->y - 1;  // Ajusta para o �ndice zero
        mapa[y * numColunas + x] = aux->frequencia; // Calcula a posi��o no vetor linear
        aux = aux->prox;
    }

    // Imprime o mapa
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            printf("%c", mapa[i * numColunas + j]); // Acessa os elementos do mapa
        }
        printf("\n");
    }

    // Liberta a mem�ria alocada para o mapa
    free(mapa);
}