#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "FuncoesAntena.h"

Antena* LerFicheiro(char* nomeFicheiro, Antena* lista, int* numLinhas, int* numColunas)
{
    FILE* ficheiro = fopen(nomeFicheiro, "r");  // Abre o ficheiro para leitura
    if (ficheiro == NULL) return lista;  // Se n�o conseguir abrir, devolve a lista como est�

    char c;
    int x = 1, y = 1;  // Inicializa as coordenadas com 1
    int maxColunas = 0; // Para contar as colunas m�ximas por linha

    // L� o ficheiro linha por linha
    while ((c = fgetc(ficheiro)) != EOF) {
        if (c == '\n') {  // Nova linha, avan�ar para a pr�xima linha (aumenta a coordenada y)
            y++;
            x = 1;  // Reseta a coordenada x ao passar para a pr�xima linha
        }
        else {
            if (c != '.') {  // Ignorar c�lulas vazias
                // Adicionar antena � lista existente
                lista = InserirAntenaFim(lista, c, x, y);
            }
            x++;  // Avan�a a coordenada x
        }

        // Atualizar o n�mero de colunas, se for a linha com mais colunas
        if (x > maxColunas) {
            maxColunas = x - 1;  // x foi incrementado ap�s o uso, ent�o subtra�mos 1
        }
    }

    // Definir as vari�veis numLinhas e numColunas
    *numLinhas = y;     // O n�mero de linhas ser� a �ltima linha lida
    *numColunas = maxColunas; // O n�mero m�ximo de colunas encontrado

    fclose(ficheiro);
    return lista;
}