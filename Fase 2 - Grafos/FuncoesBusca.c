/**
 * @file FuncoesBusca.c
 * @brief Fun��es para procuras em grafos (DFS, BFS e procura de todos os caminhos).
 *
 * @details
 * Este ficheiro cont�m implementa��es de algoritmos b�sicos de procura em grafos:
 * - Depth-First Traversal (DFT)
 * - Breadth-First Traversal (BFT)
 * - Procura recursiva de todos os caminhos entre dois v�rtices
 *
 * Al�m disso, tem fun��es auxiliares para resetar o estado dos v�rtices e imprimir resultados.
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
  * @brief Reseta o estado de visita de todos os v�rtices do grafo.
  *
  * Percorre todos os v�rtices do grafo e define o campo `visitado` como 0 (n�o visitado).
  *
  * @param grafo Apontador para o grafo.
  * @return 1 se conseguiu resetar, 0 se o grafo for inv�lido (NULL).
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
 * @brief Obt�m um vizinho n�o visitado de um dado v�rtice.
 *
 * Percorre as arestas adjacentes ao v�rtice e retorna o primeiro destino que ainda n�o foi visitado.
 *
 * @param v Apontador para o v�rtice atual.
 * @return Apontador para o v�rtice vizinho n�o visitado, ou NULL se todos os vizinhos j� foram visitados.
 */
Vertice* getVizinhoNaoVisitado(Vertice* v) {
    Aresta* a = v->adj;
    while (a) {
        if (!a->destino->visitado)
            return a->destino;
        a = a->next;
    }
    return NULL;  // n�o h� vizinhos n�o visitados
}

/**
 * @brief Percurso em profundidade (Depth-First Traversal) recursivo a partir de um v�rtice.
 *
 * Marca o v�rtice atual como visitado, imprime-o e faz recurs�o para os seus vizinhos n�o visitados.
 *
 * @param v Apontador para o v�rtice inicial da procura.
 * @return N�mero total de v�rtices visitados durante a travessia.
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
 * @brief Verifica se a fila est� vazia.
 *
 * Usada internamente para o BFS, verifica se os �ndices da fila indicam que ela est� vazia.
 *
 * @param inicio �ndice do in�cio da fila.
 * @param fim �ndice do fim da fila.
 * @return 1 se a fila estiver vazia, 0 caso contr�rio.
 */
int filaVazia(int inicio, int fim) {
    return inicio == fim;
}

/**
 * @brief Percurso em largura (Breadth-First Traversal) a partir de um v�rtice.
 *
 * Utiliza uma fila para visitar v�rtices em camadas, come�ando pelo v�rtice inicial.
 *
 * @param inicio Apontador para o v�rtice inicial da procura.
 * @return N�mero total de v�rtices visitados durante a travessia.
 *
 * @details
 * Marca os v�rtices como visitados � medida que s�o inseridos na fila,
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
 * @brief Imprime um caminho armazenado num array de v�rtices.
 *
 * Imprime a sequ�ncia de v�rtices que representam o caminho, mostrando id e frequ�ncia.
 *
 * @param caminho Array de apontadores para v�rtices que formam o caminho.
 * @param tamanho N�mero de v�rtices no caminho.
 */
void imprimirCaminho(Vertice* caminho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d (%c) -> ", caminho[i]->id, caminho[i]->frequencia);
    }
    printf("FIM\n");
}

/**
 * @brief Encontra e imprime todos os caminhos entre dois v�rtices.
 *
 * Fun��o recursiva que explora todas as rotas poss�veis entre `atual` e `destino`,
 * evitando ciclos gra�as ao campo `visitado`.
 *
 * @param atual Apontador para o v�rtice atual na explora��o.
 * @param destino Apontador para o v�rtice destino que queremos alcan�ar.
 * @param caminho Array de apontadores para armazenar o caminho corrente.
 * @param pos Posi��o atual no array caminho.
 * @return N�mero total de caminhos encontrados entre `atual` e `destino`.
 *
 * @details
 * A cada chamada, o v�rtice atual � marcado como visitado e adicionado ao caminho.
 * Ao chegar ao destino, imprime o caminho e conta 1 caminho encontrado.
 * Depois, explora recursivamente os vizinhos n�o visitados.
 * Antes de retornar, desmarca o v�rtice para permitir outras rotas.
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