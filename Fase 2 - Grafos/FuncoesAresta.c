/**
 * @file FuncoesAresta.c
 * @brief Implementa��o de fun��es para manipula��o de arestas em grafos.
 *
 * @details Este ficheiro cont�m fun��es para adicionar, criar, remover, libertar e listar arestas
 * entre v�rtices de um grafo. As arestas s�o usadas para representar liga��es entre v�rtices,
 * podendo ter pesos que indicam dist�ncias ou custos.
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
  * @brief Adiciona uma aresta entre dois v�rtices com um determinado peso.
  *
  * Esta fun��o cria uma nova aresta a partir do v�rtice de origem para o v�rtice de destino,
  * atribuindo-lhe um peso especificado. A aresta � adicionada ao in�cio da lista de adjac�ncia
  * do v�rtice de origem.
  *
  * @param origem Apontador para o v�rtice de origem.
  * @param destino Apontador para o v�rtice de destino.
  * @param peso Peso associado � aresta (normalmente dist�ncia ou custo).
  * @return 0 se a aresta for adicionada com sucesso, -1 se os par�metros forem inv�lidos,
  *         -2 se falhar a aloca��o de mem�ria.
  *
  * @details
  * A fun��o aloca dinamicamente uma nova estrutura `Aresta`. Se a aloca��o for bem-sucedida,
  * inicializa os campos `destino`, `peso` e insere a aresta no in�cio da lista de adjac�ncia do v�rtice origem.
  */
int adicionarAresta(Vertice* origem, Vertice* destino, float peso) {
    if (!origem || !destino) return -1;  // erro: par�metros inv�lidos

    Aresta* novaAresta = malloc(sizeof(Aresta));
    if (!novaAresta) {
        return -2;  // erro: sem mem�ria
    }

    novaAresta->destino = destino;
    novaAresta->peso = peso;
    novaAresta->next = origem->adj;
    origem->adj = novaAresta;

    return 0;  // sucesso
}

/**
 * @brief Cria arestas adjacentes entre v�rtices do grafo com base nas suas posi��es e frequ�ncias.
 *
 * Esta fun��o percorre todos os v�rtices do grafo e tenta criar arestas para os seus vizinhos
 * nas 8 dire��es (ortogonais e diagonais), apenas se os v�rtices tiverem a mesma frequ�ncia.
 * As arestas s�o bidirecionais e possuem peso 1.0 para vizinhos ortogonais e 1.414 para diagonais.
 *
 * @param grafo Apontador para o grafo.
 * @return 0 se a cria��o for bem-sucedida, -1 se o grafo for inv�lido, -2 se falhar a aloca��o de mem�ria.
 *
 * @details
 * Para evitar duplica��o de arestas, apenas cria-se uma liga��o se o ID do destino for maior
 * que o do v�rtice origem. Usa a fun��o `adicionarAresta` para inserir as arestas.
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
                float peso = (i < 4) ? 1.0f : 1.414f; // dist�ncia ortogonal ou diagonal

                // Evitar duplicar arestas (exemplo: s� criar se destino id > origem id)
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
 * @brief Remove todas as arestas do grafo que apontam para um v�rtice espec�fico.
 *
 * Esta fun��o percorre todos os v�rtices do grafo e remove todas as arestas que tenham
 * o v�rtice alvo como destino, libertando a mem�ria associada a essas arestas.
 *
 * @param grafo Apontador para o grafo.
 * @param alvo Apontador para o v�rtice alvo cujas arestas devem ser removidas.
 * @return 0 se for bem-sucedido, -1 se os par�metros forem inv�lidos.
 *
 * @details
 * A fun��o atualiza as listas de adjac�ncia dos v�rtices para remover todas as arestas
 * que apontem para o v�rtice `alvo`, garantindo que a mem�ria � devidamente libertada.
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
 * @brief Liberta todas as arestas associadas a um v�rtice.
 *
 * Esta fun��o remove e liberta da mem�ria todas as arestas da lista de adjac�ncia
 * de um v�rtice espec�fico, deixando o v�rtice sem nenhuma liga��o.
 *
 * @param v Apontador para o v�rtice cujas arestas ser�o libertadas.
 * @return 0 se a opera��o for bem-sucedida, -1 se o v�rtice for inv�lido.
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
 * @brief Lista as arestas do grafo, imprimindo as liga��es de cada v�rtice.
 *
 * Esta fun��o percorre todos os v�rtices do grafo e imprime as arestas de cada um,
 * mostrando para cada liga��o o v�rtice destino, a frequ�ncia do destino e o peso da aresta.
 *
 * @param grafo Apontador para o grafo a ser listado.
 *
 * @details
 * A fun��o � �til para depura��o e visualiza��o do estado atual das liga��es do grafo.
 */
void listarArestas(GR* grafo) {
    if (!grafo) return;

    Vertice* vAtual = grafo->vertices;
    while (vAtual) {
        printf("V�rtice %d (%c):\n", vAtual->id, vAtual->frequencia);
        Aresta* a = vAtual->adj;
        while (a) {
            printf("  -> liga a %d (%c) com peso %.1f\n",
                a->destino->id, a->destino->frequencia, a->peso);
            a = a->next;
        }
        vAtual = vAtual->next;
    }
}
