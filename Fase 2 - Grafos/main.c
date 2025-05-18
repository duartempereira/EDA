/**
 * @file main.c
 * @brief Programa principal para manipulação e análise de grafo de antenas.
 *
 * @details
 * Este programa principal cria um grafo, carrega dados de antenas a partir de um ficheiro,
 * adiciona vértices manualmente, cria ligações (arestas) entre antenas adjacentes com
 * a mesma frequência, e executa diferentes operações de procura (DFS e BFS).
 *
 * Também demonstra a remoção de vértices, impressão do mapa e listagem dos vértices,
 * além de encontrar todos os caminhos possíveis entre duas antenas.
 *
 * O programa termina libertando toda a memória alocada.
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
    // Define a localidade para português (acentos, caracteres especiais)
    setlocale(LC_ALL, "Portuguese");

    // Cria um grafo vazio (estrutura base para o mapa de antenas)
    GR* grafo = criarGrafo();

    // Carrega o mapa do ficheiro "mapa_antenas.txt" e cria os vértices no grafo
    carregarMapaNoGrafo(grafo, "mapa_antenas.txt");

    // Imprime informações básicas sobre o mapa carregado
    printf("- Mapa carregado -\n");
    printf("Linhas lidas: %d\n", grafo->linhas);
    printf("Colunas lidas: %d\n", grafo->colunas);
    printf("Número de antenas (vértices) lidos: %d\n\n", grafo->numVertices);

    // Cria e adiciona manualmente dois vértices (antenas) ao grafo
    Vertice* v1 = criarVertice(17, '0', 3, 3);
    adicionarVertice(grafo, v1);

    Vertice* v2 = criarVertice(16, 'A', 13, 2);
    adicionarVertice(grafo, v2);

    // Cria arestas entre antenas adjacentes que têm a mesma frequência
    criarArestasAdjacentes(grafo);

    // Imprime o mapa visual, mostrando as antenas posicionadas no grid
    printf("- Mapa - \n");
    imprimirMapa(grafo);
    printf("\n");

    // Lista todos os vértices do grafo, mostrando ID, frequência e coordenadas
    listarVertices(grafo);
    printf("\n");

    // Remove o vértice com ID 16 do grafo (a antena com frequência 'A' que adicionámos)
    removerVerticePorId(grafo, 16);

    // Testes comentados para listar vértices e arestas após remoção (podes ativar se quiseres)
    //printf("\nLista de vértices após remover:\n");
    //listarVertices(grafo);
    //printf("\n\n\n");

    /*listarArestas(grafo);*/  // Função comentada para listar arestas (se existir)

    // Procura o vértice com ID 5 para usar como ponto inicial nas procuras
    Vertice* inicio = procurarVerticePorId(grafo, 5);

    // Executa Procura em Profundidade (DFS) a partir do vértice 'inicio'
    resetarVisitados(grafo);  // limpa flags de visitação
    printf("=== Procura em Profundidade (DFS) ===\n");
    dft(inicio);
    printf("\n");

    // Executa Procura em Largura (BFS) a partir do vértice 'inicio'
    resetarVisitados(grafo);
    printf("=== Procura em Largura (BFS) ===\n");
    bft(inicio);
    printf("\n");

    // Procura vértices de origem e destino para encontrar todos os caminhos entre eles
    Vertice* origem = procurarVerticePorId(grafo, 5);
    Vertice* destino = procurarVerticePorId(grafo, 15);

    // Verifica se os vértices existem antes de tentar encontrar caminhos
    if (!origem || !destino) {
        printf("Origem ou destino não encontrado!\n");
        return 1;
    }

    // Array auxiliar para guardar o caminho atual durante a procura
    Vertice* caminho[100];
    resetarVisitados(grafo);

    // Encontra e imprime todos os caminhos possíveis entre a antena de origem e a de destino
    printf("=== Todos os caminhos entre antena %d e antena %d ===\n", origem->id, destino->id);
    encontrarTodosCaminhos(origem, destino, caminho, 0);

    // Liberta toda a memória alocada para o grafo e respetivas estruturas
    libertarGrafo(grafo);
    return 0;
}