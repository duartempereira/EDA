#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Structs.h"

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

Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y)
{
    Antena* novaAntena = CriarAntena(freq, x, y); // Cria nova antena
    if (novaAntena == NULL) return lista; // Se a cria��o falhar, retorna a lista sem modifica��o

    novaAntena->prox = lista; // Aponta para a lista existente
    return novaAntena; // Retorna a nova lista com a antena no in�cio
}

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

void ListarAntenas(Antena* lista)
{
    Antena* aux = lista;
    while (aux) {
        printf("Frequ�ncia: %c, Localiza��o: (%d, %d)\n", aux->frequencia, aux->y, aux->x);
        aux = aux->prox;
    }
}

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