/**
 * @file FuncoesBusca.c
 * @brief Funções para procuras em grafos (DFS, BFS e procura de todos os caminhos).
 *
 * @details
 * Este ficheiro contém implementações de algoritmos básicos de procura em grafos:
 * - Depth-First Traversal (DFT)
 * - Breadth-First Traversal (BFT)
 * - Procura recursiva de todos os caminhos entre dois vértices
 *
 * Além disso, tem funções auxiliares para resetar o estado dos vértices e imprimir resultados.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "FuncoesVertice.h"

 /**
  * @brief Reseta o estado de visita de todos os vértices do grafo.
  *
  * Percorre todos os vértices do grafo e define o campo `visitado` como 0 (não visitado).
  *
  * @param grafo Apontador para o grafo.
  * @return 1 se conseguiu resetar, 0 se o grafo for inválido (NULL).
  */
int resetarVisitados(GR* grafo) {
    if (!grafo) return 0;
    Vertice* atual = grafo->vertices;
    while (atual) {
        atual->visitado = 0;
        atual = atual->next;
    }
    return 1;
}

/**
 * @brief Obtém um vizinho não visitado de um dado vértice.
 *
 * Percorre as arestas adjacentes ao vértice e retorna o primeiro destino que ainda não foi visitado.
 *
 * @param v Apontador para o vértice atual.
 * @return Apontador para o vértice vizinho não visitado, ou NULL se todos os vizinhos já foram visitados.
 */
Vertice* getVizinhoNaoVisitado(Vertice* v) {
    Aresta* a = v->adj;
    while (a) {
        if (!a->destino->visitado)
            return a->destino;
        a = a->next;
    }
    return NULL;  // não há vizinhos não visitados
}

/**
 * @brief Percurso em profundidade (Depth-First Traversal) recursivo a partir de um vértice.
 *
 * Marca o vértice atual como visitado, imprime-o e faz recursão para os seus vizinhos não visitados.
 *
 * @param v Apontador para o vértice inicial da procura.
 * @return Número total de vértices visitados durante a travessia.
 */
int dft(Vertice* v) {
    if (v == NULL || v->visitado) return 0;

    v->visitado = 1;
    imprimirVertice(v);

    int count = 1;
    Vertice* vizinho;
    while ((vizinho = getVizinhoNaoVisitado(v)) != NULL) {
        count += dft(vizinho);
    }
    return count;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * Usada internamente para o BFS, verifica se os índices da fila indicam que ela está vazia.
 *
 * @param inicio Índice do início da fila.
 * @param fim Índice do fim da fila.
 * @return 1 se a fila estiver vazia, 0 caso contrário.
 */
int filaVazia(int inicio, int fim) {
    return inicio == fim;
}

/**
 * @brief Percurso em largura (Breadth-First Traversal) a partir de um vértice.
 *
 * Utiliza uma fila para visitar vértices em camadas, começando pelo vértice inicial.
 *
 * @param inicio Apontador para o vértice inicial da procura.
 * @return Número total de vértices visitados durante a travessia.
 *
 * @details
 * Marca os vértices como visitados à medida que são inseridos na fila,
 * evitando visitas repetidas.
 */
int bft(Vertice* inicio) {
    if (inicio == NULL) return 0;

    Vertice* fila[1000];
    int inicioFila = 0, fimFila = 0;

    int count = 0;
    inicio->visitado = 1;
    fila[fimFila++] = inicio;

    while (!filaVazia(inicioFila, fimFila)) {
        Vertice* v = fila[inicioFila++];
        imprimirVertice(v);
        count++;

        Aresta* a = v->adj;
        while (a != NULL) {
            if (!a->destino->visitado) {
                a->destino->visitado = 1;
                fila[fimFila++] = a->destino;
            }
            a = a->next;
        }
    }
    return count;
}

/**
 * @brief Imprime um caminho armazenado num array de vértices.
 *
 * Imprime a sequência de vértices que representam o caminho, mostrando id e frequência.
 *
 * @param caminho Array de apontadores para vértices que formam o caminho.
 * @param tamanho Número de vértices no caminho.
 */
void imprimirCaminho(Vertice* caminho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d (%c) -> ", caminho[i]->id, caminho[i]->frequencia);
    }
    printf("FIM\n");
}

/**
 * @brief Encontra e imprime todos os caminhos entre dois vértices.
 *
 * Função recursiva que explora todas as rotas possíveis entre `atual` e `destino`,
 * evitando ciclos graças ao campo `visitado`.
 *
 * @param atual Apontador para o vértice atual na exploração.
 * @param destino Apontador para o vértice destino que queremos alcançar.
 * @param caminho Array de apontadores para armazenar o caminho corrente.
 * @param pos Posição atual no array caminho.
 * @return Número total de caminhos encontrados entre `atual` e `destino`.
 *
 * @details
 * A cada chamada, o vértice atual é marcado como visitado e adicionado ao caminho.
 * Ao chegar ao destino, imprime o caminho e conta 1 caminho encontrado.
 * Depois, explora recursivamente os vizinhos não visitados.
 * Antes de retornar, desmarca o vértice para permitir outras rotas.
 */
int encontrarTodosCaminhos(Vertice* atual, Vertice* destino, Vertice* caminho[], int pos) {
    atual->visitado = 1;
    caminho[pos] = atual;
    pos++;

    int totalCaminhos = 0;
    if (atual == destino) {
        imprimirCaminho(caminho, pos);
        totalCaminhos = 1;
    }
    else {
        Aresta* a = atual->adj;
        while (a != NULL) {
            if (!a->destino->visitado) {
                totalCaminhos += encontrarTodosCaminhos(a->destino, destino, caminho, pos);
            }
            a = a->next;
        }
    }

    atual->visitado = 0;
    return totalCaminhos;
}