/**
 * @file FuncoesFicheiro.c
 * @brief Funções para carregar dados de ficheiro para o grafo.
 *
 * @details
 * Este ficheiro contém funções responsáveis pela leitura de ficheiros que
 * representam mapas ou grafos, e a criação dos vértices correspondentes
 * no grafo em memória.
 *
 * A função principal aqui é `carregarMapaNoGrafo`, que lê um ficheiro de texto
 * onde cada caractere representa um vértice ou espaço vazio ('.').
 * Os vértices são criados e adicionados ao grafo com posições e identificadores únicos.
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
  * uma posição no mapa. O caractere '.' representa espaço vazio (sem vértice),
  * qualquer outro caractere representa um vértice com a frequência igual ao caractere lido.
  *
  * Os vértices são criados com IDs únicos, começando a partir de `grafo->numVertices + 1`,
  * e as coordenadas (x, y) correspondem à posição no mapa (coluna, linha).
  * A função também atualiza as dimensões do grafo (linhas e colunas).
  *
  * @param grafo Apontador para a estrutura do grafo onde os vértices serão adicionados.
  * @param nomeFicheiro Nome do ficheiro de texto a ser lido.
  * @return
  * - 0 em caso de sucesso,
  * - -1 se os parâmetros forem inválidos,
  * - -2 se não for possível abrir o ficheiro,
  * - -3 se falhar a criar um vértice,
  * - -4 se falhar a adicionar um vértice ao grafo.
  *
  * @note O ficheiro deve estar no formato correto, sem linhas vazias ou caracteres inválidos.
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
    int idAtual = grafo->numVertices + 1;  // continuar o ID a partir do que já existe

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
                    return -3;  // falha a criar vértice
                }
                if (adicionarVertice(grafo, v) != 0) {
                    free(v);
                    fclose(f);
                    return -4;  // falha a adicionar vértice
                }
            }
        }
        grafo->linhas++;
    }

    fclose(f);
    return 0;  // sucesso
}