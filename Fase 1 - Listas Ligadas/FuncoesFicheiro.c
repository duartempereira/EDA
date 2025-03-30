/**
 * @file FuncoesFicheiro.c
 * @brief Funções para manipulação de ficheiros contendo dados sobre antenas.
 *
 * @details Este ficheiro contém a função `LerFicheiro`, que é responsável por ler um ficheiro de texto
 * contendo as localizações de antenas em um mapa e armazenar as informações em uma lista ligada.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-03-30
 * @version 1.0
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "FuncoesAntena.h"

 /**
  * @brief Lê um ficheiro e cria uma lista de antenas a partir das suas coordenadas.
  *
  * Esta função abre um ficheiro de texto contendo as posições das antenas representadas por caracteres,
  * e armazena as antenas em uma lista ligada. A função também calcula o número de linhas e colunas
  * presentes no mapa.
  *
  * @param nomeFicheiro O nome do ficheiro a ser lido.
  * @param lista A lista de antenas onde as novas antenas serão inseridas.
  * @param numLinhas Ponteiro para a variável que receberá o número de linhas do mapa.
  * @param numColunas Ponteiro para a variável que receberá o número de colunas do mapa.
  * @return A lista de antenas atualizada.
  *
  * @details
  * A função lê o ficheiro linha por linha e processa cada caracter. Para cada antena (caracter que não seja '.'),
  * a função chama a função `InserirAntenaFim` para adicionar a antena à lista. As coordenadas X e Y são
  * calculadas com base na posição do caracter no ficheiro. O número máximo de colunas é calculado durante
  * a leitura do ficheiro, e o número de linhas é determinado pela quantidade de quebras de linha encontradas.
  */
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