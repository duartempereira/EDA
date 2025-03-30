#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "FuncoesAntena.h"

Antena* LerFicheiro(char* nomeFicheiro, Antena* lista, int* numLinhas, int* numColunas)
{
    FILE* ficheiro = fopen(nomeFicheiro, "r");  // Abre o ficheiro para leitura
    if (ficheiro == NULL) return lista;  // Se não conseguir abrir, devolve a lista como está

    char c;
    int x = 1, y = 1;  // Inicializa as coordenadas com 1
    int maxColunas = 0; // Para contar as colunas máximas por linha

    // Lê o ficheiro linha por linha
    while ((c = fgetc(ficheiro)) != EOF) {
        if (c == '\n') {  // Nova linha, avançar para a próxima linha (aumenta a coordenada y)
            y++;
            x = 1;  // Reseta a coordenada x ao passar para a próxima linha
        }
        else {
            if (c != '.') {  // Ignorar células vazias
                // Adicionar antena à lista existente
                lista = InserirAntenaFim(lista, c, x, y);
            }
            x++;  // Avança a coordenada x
        }

        // Atualizar o número de colunas, se for a linha com mais colunas
        if (x > maxColunas) {
            maxColunas = x - 1;  // x foi incrementado após o uso, então subtraímos 1
        }
    }

    // Definir as variáveis numLinhas e numColunas
    *numLinhas = y;     // O número de linhas será a última linha lida
    *numColunas = maxColunas; // O número máximo de colunas encontrado

    fclose(ficheiro);
    return lista;
}