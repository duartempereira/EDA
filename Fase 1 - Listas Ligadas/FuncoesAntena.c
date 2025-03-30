/**
 * @file FuncoesAntenas.c
 * @brief Implementação de funções para manipulação de antenas.
 *
 * @details Este ficheiro contém funções para criar, inserir, remover e listar antenas,
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
  * Esta função aloca memória para uma nova antena e inicializa os seus campos com os valores fornecidos.
  *
  * @param frequencia A frequência da antena.
  * @param x A coordenada X da antena no mapa.
  * @param y A coordenada Y da antena no mapa.
  * @return Ponteiro para a nova antena criada ou NULL se falhar a alocação de memória.
  *
  * @details
  * Esta função é responsável pela alocação dinâmica de memória para uma estrutura do tipo
  * `Antena` e pela inicialização dos seus campos. A função verifica se a alocação de memória
  * foi bem-sucedida e, em caso afirmativo, inicializa os campos `frequencia`, `x`, `y` e `prox`
  * da nova antena. Se a alocação de memória falhar, a função retorna `NULL`.
  */
Antena* CriarAntena(char frequencia, int x, int y)
{
    Antena* novaAntena = (Antena*)malloc(sizeof(Antena)); // Aloca memória para uma nova antena
    if (novaAntena == NULL) return NULL; // Verifica se a alocação falhou

    // Inicializa os campos da antena
    novaAntena->frequencia = frequencia;
    novaAntena->x = x;
    novaAntena->y = y;
    novaAntena->prox = NULL;

    return novaAntena;
}

/**
 * @brief Insere uma nova antena no início da lista.
 *
 * Esta função cria uma nova antena e a insere no início de uma lista existente de antenas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Ponteiro para a nova lista com a antena inserida no início.
 *
 * @details
 * Após criar a nova antena, a função insere-a no início da lista. Se a lista já contiver
 * antenas, o ponteiro `prox` da nova antena será ajustado para apontar para a primeira
 * antena da lista, e a nova antena será o primeiro elemento da lista.
 */
Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y)
{
    Antena* novaAntena = CriarAntena(freq, x, y); // Cria nova antena
    if (novaAntena == NULL) return lista; // Se a criação falhar, retorna a lista sem modificação

    novaAntena->prox = lista;
    return novaAntena;
}

/**
 * @brief Insere uma nova antena no fim da lista.
 *
 * Esta função cria uma nova antena e a insere no final de uma lista existente de antenas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Ponteiro para a lista com a antena inserida no final.
 *
 * @details
 * Após criar a nova antena, a função percorre a lista até encontrar o último elemento,
 * e então insere a nova antena no final da lista. Se a lista estiver vazia, a nova antena
 * torna-se o primeiro elemento.
 */
Antena* InserirAntenaFim(Antena* lista, char freq, int x, int y)
{
    Antena* novaAntena = CriarAntena(freq, x, y);
    if (novaAntena == NULL) return lista;

    if (lista == NULL) return novaAntena; // Se a lista estiver vazia, a nova antena se torna a lista

    Antena* atual = lista;
    while (atual->prox != NULL) { // Percorre a lista até o último elemento
        atual = atual->prox;
    }
    atual->prox = novaAntena; // Liga a nova antena ao final da lista
    return lista;
}

/**
 * @brief Remove uma antena da lista com base nas coordenadas fornecidas.
 *
 * Esta função percorre a lista de antenas e remove a antena cujas coordenadas X e Y
 * coincidem com as fornecidas.
 *
 * @param lista Ponteiro para a lista de antenas existente.
 * @param x Coordenada X da antena a ser removida.
 * @param y Coordenada Y da antena a ser removida.
 * @return Ponteiro para a lista com a antena removida, ou a lista original se não encontrar a antena.
 *
 * @details
 * A função percorre a lista de antenas procurando uma antena com as coordenadas especificadas.
 * Se encontrada, a antena é removida da lista e a memória é liberada. Se a antena estiver no início
 * da lista, a função ajusta o ponteiro da lista para o próximo elemento.
 */
Antena* RemoverAntena(Antena* lista, int x, int y)
{
    if (lista == NULL) return NULL;

    if (lista->x == x && lista->y == y) { // Se a antena a remover está no início da lista
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
 * @brief Destrói a lista de antenas, liberando toda a memória alocada.
 *
 * Esta função percorre a lista de antenas e libera a memória de cada elemento.
 *
 * @param lista Ponteiro para a lista de antenas a ser destruída.
 * @return NULL
 *
 * @details
 * A função percorre toda a lista, liberando a memória alocada para cada elemento. Quando
 * a lista estiver vazia, o ponteiro será ajustado para NULL.
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
 * Esta função percorre a lista de antenas e imprime as informações de cada antena.
 *
 * @param lista Ponteiro para a lista de antenas a ser listada.
 *
 * @details
 * A função percorre a lista e imprime para cada antena a sua frequência e as suas coordenadas.
 */
void ListarAntenas(Antena* lista)
{
    Antena* aux = lista;
    while (aux) {
        printf("Frequência: %c, Localização: (%d, %d)\n", aux->frequencia, aux->y, aux->x);
        aux = aux->prox;
    }
}

/**
 * @brief Exibe um mapa com as antenas posicionadas nas coordenadas especificadas.
 *
 * Esta função cria um mapa representado por um vetor de caracteres, posiciona as antenas
 * nas coordenadas fornecidas e imprime o mapa.
 *
 * @param lista Ponteiro para a lista de antenas.
 * @param numLinhas Número de linhas do mapa.
 * @param numColunas Número de colunas do mapa.
 *
 * @details
 * A função cria um mapa onde cada célula é representada por um ponto (`.`), e depois
 * posiciona as antenas no mapa usando as coordenadas fornecidas. As antenas são representadas
 * pela sua frequência. Após posicionar as antenas, o mapa é impresso na consola.
 */
void MostrarMapaAntenas(Antena* lista, int numLinhas, int numColunas)
{
    // Aloca memória para o mapa de uma vez só (um único bloco contínuo)
    char* mapa = (char*)malloc(numLinhas * numColunas * sizeof(char));

    if (mapa == NULL) {
        printf("Erro ao alocar memória para o mapa.\n");
        return; // Se falhar a alocação, sai da função
    }

    // Inicializa o mapa com pontos (.)
    for (int i = 0; i < numLinhas * numColunas; i++) {
        mapa[i] = '.';
    }

    Antena* aux = lista;
    while (aux != NULL) { // Posiciona as antenas no mapa
        int x = aux->x - 1;  // Ajusta para o índice zero
        int y = aux->y - 1;  // Ajusta para o índice zero
        mapa[y * numColunas + x] = aux->frequencia; // Calcula a posição no vetor linear
        aux = aux->prox;
    }

    // Imprime o mapa
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            printf("%c", mapa[i * numColunas + j]); // Acessa os elementos do mapa
        }
        printf("\n");
    }

    // Liberta a memória alocada para o mapa
    free(mapa);
}