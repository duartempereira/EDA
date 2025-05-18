/**
 * @file FuncoesAresta.c
 * @brief Implementação de funções para manipulação de arestas em grafos.
 *
 * @details Este ficheiro contém funções para adicionar, criar, remover, libertar e listar arestas
 * entre vértices de um grafo. As arestas são usadas para representar ligações entre vértices,
 * podendo ter pesos que indicam distâncias ou custos.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "FuncoesAresta.h"
#include "Structs.h"
#include "FuncoesVertice.h"

 /**
  * @brief Adiciona uma aresta entre dois vértices com um determinado peso.
  *
  * Esta função cria uma nova aresta a partir do vértice de origem para o vértice de destino,
  * atribuindo-lhe um peso especificado. A aresta é adicionada ao início da lista de adjacência
  * do vértice de origem.
  *
  * @param origem Apontador para o vértice de origem.
  * @param destino Apontador para o vértice de destino.
  * @param peso Peso associado à aresta (normalmente distância ou custo).
  * @return 0 se a aresta for adicionada com sucesso, -1 se os parâmetros forem inválidos,
  *         -2 se falhar a alocação de memória.
  *
  * @details
  * A função aloca dinamicamente uma nova estrutura `Aresta`. Se a alocação for bem-sucedida,
  * inicializa os campos `destino`, `peso` e insere a aresta no início da lista de adjacência do vértice origem.
  */
int adicionarAresta(Vertice* origem, Vertice* destino, float peso) {
    if (!origem || !destino) return -1;  // erro: parâmetros inválidos

    Aresta* novaAresta = malloc(sizeof(Aresta));
    if (!novaAresta) {
        return -2;  // erro: sem memória
    }

    novaAresta->destino = destino;
    novaAresta->peso = peso;
    novaAresta->next = origem->adj;
    origem->adj = novaAresta;

    return 0;  // sucesso
}

/**
 * @brief Cria arestas adjacentes entre vértices do grafo com base nas suas posições e frequências.
 *
 * Esta função percorre todos os vértices do grafo e tenta criar arestas para os seus vizinhos
 * nas 8 direções (ortogonais e diagonais), apenas se os vértices tiverem a mesma frequência.
 * As arestas são bidirecionais e possuem peso 1.0 para vizinhos ortogonais e 1.414 para diagonais.
 *
 * @param grafo Apontador para o grafo.
 * @return 0 se a criação for bem-sucedida, -1 se o grafo for inválido, -2 se falhar a alocação de memória.
 *
 * @details
 * Para evitar duplicação de arestas, apenas cria-se uma ligação se o ID do destino for maior
 * que o do vértice origem. Usa a função `adicionarAresta` para inserir as arestas.
 */
int criarArestasAdjacentes(GR* grafo) {
    if (!grafo) return -1;

    int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
    int dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };

    for (Vertice* v = grafo->vertices; v != NULL; v = v->next) {
        for (int i = 0; i < 8; i++) {
            int nx = v->x + dx[i];
            int ny = v->y + dy[i];
            Vertice* vizinho = procurarVerticePorCoordenadas(grafo, nx, ny);
            if (vizinho && vizinho->frequencia == v->frequencia) {
                float peso = (i < 4) ? 1.0f : 1.414f; // distância ortogonal ou diagonal

                // Evitar duplicar arestas (exemplo: só criar se destino id > origem id)
                if (vizinho->id > v->id) {
                    if (adicionarAresta(v, vizinho, peso) != 0) return -2;
                    if (adicionarAresta(vizinho, v, peso) != 0) return -2;
                }
            }
        }
    }
    return 0; // sucesso
}

/**
 * @brief Remove todas as arestas do grafo que apontam para um vértice específico.
 *
 * Esta função percorre todos os vértices do grafo e remove todas as arestas que tenham
 * o vértice alvo como destino, libertando a memória associada a essas arestas.
 *
 * @param grafo Apontador para o grafo.
 * @param alvo Apontador para o vértice alvo cujas arestas devem ser removidas.
 * @return 0 se for bem-sucedido, -1 se os parâmetros forem inválidos.
 *
 * @details
 * A função atualiza as listas de adjacência dos vértices para remover todas as arestas
 * que apontem para o vértice `alvo`, garantindo que a memória é devidamente libertada.
 */
int removerArestasParaVertice(GR* grafo, Vertice* alvo) {
    if (!grafo || !alvo) return -1;

    Vertice* v = grafo->vertices;
    while (v) {
        Aresta* atual = v->adj;
        Aresta* anterior = NULL;

        while (atual) {
            if (atual->destino == alvo) {
                if (anterior == NULL) {
                    v->adj = atual->next;
                }
                else {
                    anterior->next = atual->next;
                }
                Aresta* tmp = atual;
                atual = atual->next;
                free(tmp);
            }
            else {
                anterior = atual;
                atual = atual->next;
            }
        }
        v = v->next;
    }
    return 0;
}

/**
 * @brief Liberta todas as arestas associadas a um vértice.
 *
 * Esta função remove e liberta da memória todas as arestas da lista de adjacência
 * de um vértice específico, deixando o vértice sem nenhuma ligação.
 *
 * @param v Apontador para o vértice cujas arestas serão libertadas.
 * @return 0 se a operação for bem-sucedida, -1 se o vértice for inválido.
 */
int libertarArestasDoVertice(Vertice* v) {
    if (!v) return -1;

    Aresta* a = v->adj;
    while (a) {
        Aresta* tmp = a;
        a = a->next;
        free(tmp);
    }
    v->adj = NULL;
    return 0;
}

/**
 * @brief Lista as arestas do grafo, imprimindo as ligações de cada vértice.
 *
 * Esta função percorre todos os vértices do grafo e imprime as arestas de cada um,
 * mostrando para cada ligação o vértice destino, a frequência do destino e o peso da aresta.
 *
 * @param grafo Apontador para o grafo a ser listado.
 *
 * @details
 * A função é útil para depuração e visualização do estado atual das ligações do grafo.
 */
void listarArestas(GR* grafo) {
    if (!grafo) return;

    Vertice* vAtual = grafo->vertices;
    while (vAtual) {
        printf("Vértice %d (%c):\n", vAtual->id, vAtual->frequencia);
        Aresta* a = vAtual->adj;
        while (a) {
            printf("  -> liga a %d (%c) com peso %.1f\n",
                a->destino->id, a->destino->frequencia, a->peso);
            a = a->next;
        }
        vAtual = vAtual->next;
    }
}
