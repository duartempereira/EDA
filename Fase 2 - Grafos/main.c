/**
 * @file main.c
 * @brief Programa principal para manipula��o e an�lise de grafo de antenas.
 *
 * @details
 * Este programa principal cria um grafo, carrega dados de antenas a partir de um ficheiro,
 * adiciona v�rtices manualmente, cria liga��es (arestas) entre antenas adjacentes com
 * a mesma frequ�ncia, e executa diferentes opera��es de procura (DFS e BFS).
 *
 * Tamb�m demonstra a remo��o de v�rtices, impress�o do mapa e listagem dos v�rtices,
 * al�m de encontrar todos os caminhos poss�veis entre duas antenas.
 *
 * O programa termina libertando toda a mem�ria alocada.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2025-05-18
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Structs.h"
#include "FuncoesGrafo.h"
#include "FuncoesVertice.h"
#include "FuncoesAresta.h"
#include "FuncoesBusca.h"
#include "FuncoesFicheiro.h"


int main() {
    // Define a localidade para portugu�s (acentos, caracteres especiais)
    setlocale(LC_ALL, "Portuguese");

    // Cria um grafo vazio (estrutura base para o mapa de antenas)
    GR* grafo = criarGrafo();

    // Carrega o mapa do ficheiro "mapa_antenas.txt" e cria os v�rtices no grafo
    carregarMapaNoGrafo(grafo, "mapa_antenas.txt");

    // Imprime informa��es b�sicas sobre o mapa carregado
    printf("- Mapa carregado -\n");
    printf("Linhas lidas: %d\n", grafo->linhas);
    printf("Colunas lidas: %d\n", grafo->colunas);
    printf("N�mero de antenas (v�rtices) lidos: %d\n\n", grafo->numVertices);

    // Cria e adiciona manualmente dois v�rtices (antenas) ao grafo
    Vertice* v1 = criarVertice(17, '0', 3, 3);
    adicionarVertice(grafo, v1);

    Vertice* v2 = criarVertice(16, 'A', 13, 2);
    adicionarVertice(grafo, v2);

    // Cria arestas entre antenas adjacentes que t�m a mesma frequ�ncia
    criarArestasAdjacentes(grafo);

    // Imprime o mapa visual, mostrando as antenas posicionadas no grid
    printf("- Mapa - \n");
    imprimirMapa(grafo);
    printf("\n");

    // Lista todos os v�rtices do grafo, mostrando ID, frequ�ncia e coordenadas
    listarVertices(grafo);
    printf("\n");

    // Remove o v�rtice com ID 16 do grafo (a antena com frequ�ncia 'A' que adicion�mos)
    removerVerticePorId(grafo, 16);

    // Testes comentados para listar v�rtices e arestas ap�s remo��o (podes ativar se quiseres)
    //printf("\nLista de v�rtices ap�s remover:\n");
    //listarVertices(grafo);
    //printf("\n\n\n");

    /*listarArestas(grafo);*/  // Fun��o comentada para listar arestas (se existir)

    // Procura o v�rtice com ID 5 para usar como ponto inicial nas procuras
    Vertice* inicio = procurarVerticePorId(grafo, 5);

    // Executa Procura em Profundidade (DFS) a partir do v�rtice 'inicio'
    resetarVisitados(grafo);  // limpa flags de visita��o
    printf("=== Procura em Profundidade (DFS) ===\n");
    dft(inicio);
    printf("\n");

    // Executa Procura em Largura (BFS) a partir do v�rtice 'inicio'
    resetarVisitados(grafo);
    printf("=== Procura em Largura (BFS) ===\n");
    bft(inicio);
    printf("\n");

    // Procura v�rtices de origem e destino para encontrar todos os caminhos entre eles
    Vertice* origem = procurarVerticePorId(grafo, 5);
    Vertice* destino = procurarVerticePorId(grafo, 15);

    // Verifica se os v�rtices existem antes de tentar encontrar caminhos
    if (!origem || !destino) {
        printf("Origem ou destino n�o encontrado!\n");
        return 1;
    }

    // Array auxiliar para guardar o caminho atual durante a procura
    Vertice* caminho[100];
    resetarVisitados(grafo);

    // Encontra e imprime todos os caminhos poss�veis entre a antena de origem e a de destino
    printf("=== Todos os caminhos entre antena %d e antena %d ===\n", origem->id, destino->id);
    encontrarTodosCaminhos(origem, destino, caminho, 0);

    // Liberta toda a mem�ria alocada para o grafo e respetivas estruturas
    libertarGrafo(grafo);
    return 0;
}