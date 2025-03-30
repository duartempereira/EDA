/**
 * @file FuncoesFicheiro.c
 * @brief Fun��es para manipula��o de ficheiros contendo dados sobre antenas.
 *
 * @details Este ficheiro cont�m a fun��o `LerFicheiro`, que � respons�vel por ler um ficheiro de texto
 * contendo as localiza��es de antenas em um mapa e armazenar as informa��es em uma lista ligada.
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
  * @brief L� um ficheiro e cria uma lista de antenas a partir das suas coordenadas.
  *
  * Esta fun��o abre um ficheiro de texto contendo as posi��es das antenas representadas por caracteres,
  * e armazena as antenas em uma lista ligada. A fun��o tamb�m calcula o n�mero de linhas e colunas
  * presentes no mapa.
  *
  * @param nomeFicheiro O nome do ficheiro a ser lido.
  * @param lista A lista de antenas onde as novas antenas ser�o inseridas.
  * @param numLinhas Ponteiro para a vari�vel que receber� o n�mero de linhas do mapa.
  * @param numColunas Ponteiro para a vari�vel que receber� o n�mero de colunas do mapa.
  * @return A lista de antenas atualizada.
  *
  * @details
  * A fun��o l� o ficheiro linha por linha e processa cada caracter. Para cada antena (caracter que n�o seja '.'),
  * a fun��o chama a fun��o `InserirAntenaFim` para adicionar a antena � lista. As coordenadas X e Y s�o
  * calculadas com base na posi��o do caracter no ficheiro. O n�mero m�ximo de colunas � calculado durante
  * a leitura do ficheiro, e o n�mero de linhas � determinado pela quantidade de quebras de linha encontradas.
  */
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