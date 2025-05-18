/**
 * @file FuncoesFicheiro.c
 * @brief Fun��es para carregar dados de ficheiro para o grafo.
 *
 * @details
 * Este ficheiro cont�m fun��es respons�veis pela leitura de ficheiros que
 * representam mapas ou grafos, e a cria��o dos v�rtices correspondentes
 * no grafo em mem�ria.
 *
 * A fun��o principal aqui � `carregarMapaNoGrafo`, que l� um ficheiro de texto
 * onde cada caractere representa um v�rtice ou espa�o vazio ('.').
 * Os v�rtices s�o criados e adicionados ao grafo com posi��es e identificadores �nicos.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesFicheiro.h"
#include "FuncoesVertice.h"
#include "FuncoesGrafo.h"

 /**
  * @brief Carrega um mapa a partir de um ficheiro para um grafo.
  *
  * Cada linha do ficheiro representa uma linha do mapa, e cada caractere representa
  * uma posi��o no mapa. O caractere '.' representa espa�o vazio (sem v�rtice),
  * qualquer outro caractere representa um v�rtice com a frequ�ncia igual ao caractere lido.
  *
  * Os v�rtices s�o criados com IDs �nicos, come�ando a partir de `grafo->numVertices + 1`,
  * e as coordenadas (x, y) correspondem � posi��o no mapa (coluna, linha).
  * A fun��o tamb�m atualiza as dimens�es do grafo (linhas e colunas).
  *
  * @param grafo Apontador para a estrutura do grafo onde os v�rtices ser�o adicionados.
  * @param nomeFicheiro Nome do ficheiro de texto a ser lido.
  * @return
  * - 0 em caso de sucesso,
  * - -1 se os par�metros forem inv�lidos,
  * - -2 se n�o for poss�vel abrir o ficheiro,
  * - -3 se falhar a criar um v�rtice,
  * - -4 se falhar a adicionar um v�rtice ao grafo.
  *
  * @note O ficheiro deve estar no formato correto, sem linhas vazias ou caracteres inv�lidos.
  */
int carregarMapaNoGrafo(GR* grafo, const char* nomeFicheiro) {
    if (!grafo || !nomeFicheiro) return -1;

    FILE* f = fopen(nomeFicheiro, "r");
    if (!f) {
        perror("Erro ao abrir ficheiro");
        return -2;
    }

    grafo->linhas = 0;
    grafo->colunas = 0;
    int idAtual = grafo->numVertices + 1;  // continuar o ID a partir do que j� existe

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        size_t len = strlen(buffer);

        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        if ((int)len > grafo->colunas) {
            grafo->colunas = (int)len;
        }

        for (int x = 0; x < (int)len; x++) {
            char c = buffer[x];
            if (c != '.') {
                Vertice* v = criarVertice(idAtual++, c, x, grafo->linhas);
                if (!v) {
                    fclose(f);
                    return -3;  // falha a criar v�rtice
                }
                if (adicionarVertice(grafo, v) != 0) {
                    free(v);
                    fclose(f);
                    return -4;  // falha a adicionar v�rtice
                }
            }
        }
        grafo->linhas++;
    }

    fclose(f);
    return 0;  // sucesso
}