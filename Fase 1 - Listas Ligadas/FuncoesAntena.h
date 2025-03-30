#ifndef FUNCOESLISTA_H
#define FUNCOESLISTA_H

#include "Structs.h"

Antena* CriarAntena(char frequencia, int x, int y);

Antena* InserirAntenaInicio(Antena* lista, char freq, int x, int y);

Antena* InserirAntenaFim(Antena* lista, char freq, int x, int y);

Antena* RemoverAntena(Antena* lista, int x, int y);

Antena* DestroiLista(Antena* lista);

void ListarAntenas(Antena* lista);

void MostrarMapaAntenas(Antena* lista, int numLinhas, int numColunas);

#endif