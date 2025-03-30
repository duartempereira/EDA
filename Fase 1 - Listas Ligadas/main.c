#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include "FuncoesAntena.h"
#include "FuncoesFicheiro.h"
#include "Structs.h"

int main()
{
    // Definir locale para UTF-8
    setlocale(LC_ALL, "Portuguese");

    // Inicializa a lista de antenas vazia
    Antena* listaAntenas = NULL;

    // Variáveis para armazenar o número de linhas e colunas
    int numLinhas = 0, numColunas = 0;

    // Ler o ficheiro e adicionar antenas à lista existente
    listaAntenas = LerFicheiro("mapa_antenas.txt", listaAntenas, &numLinhas, &numColunas);

    // Imprimir o mapa original
    printf("\nMapa de Antenas lido\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas lidas do ficheiro
    printf("\nLista de Antenas:\n");
    ListarAntenas(listaAntenas);

    // Adicionar uma nova antena na posição (4,7) com frequência 'A'
    listaAntenas = InserirAntenaFim(listaAntenas, 'A', 4, 7);
    printf("\nAntena adicionada na posição (4,7) com frequência 'A'.\n");

    // Imprimir o mapa atualizado
    printf("\nMapa das Antenas (após adição):\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas após a adição
    printf("\nLista de Antenas após a adição:\n");
    ListarAntenas(listaAntenas);

    // Remover uma antena da posição (10,10)
    listaAntenas = RemoverAntena(listaAntenas, 4, 7);
    printf("\nAntena na posição (10,10) removida (se existia).\n");

    // Imprimir o mapa após a remoção
    printf("\nMapa das Antenas (após remoção):\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas após a remoção
    printf("\nLista de Antenas após a remoção:\n");
    ListarAntenas(listaAntenas);

    // Libertar memória das listas
    DestroiLista(listaAntenas);

    return 0;
}