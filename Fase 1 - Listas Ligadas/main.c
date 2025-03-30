/**
 * @file main.c
 * @brief Fun��o principal do programa que lida com antenas e ficheiros.
 *
 * @details Este programa l� um ficheiro de texto contendo informa��es sobre antenas e
 * posiciona-as numa lista ligada. Ele permite a visualiza��o do mapa de antenas,
 * a adi��o e remo��o de antenas.
 *
 * @author Duarte "macrogod" Pereira
 * @date 2024-03-29
 * @version 1.0
 */

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

    // Vari�veis para armazenar o n�mero de linhas e colunas
    int numLinhas = 0, numColunas = 0;

    // Ler o ficheiro e adicionar antenas � lista existente
    listaAntenas = LerFicheiro("mapa_antenas.txt", listaAntenas, &numLinhas, &numColunas);

    // Imprimir o mapa original
    printf("\nMapa de Antenas lido\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas lidas do ficheiro
    printf("\nLista de Antenas:\n");
    ListarAntenas(listaAntenas);

    // Adicionar uma nova antena na posi��o (4,7) com frequ�ncia 'A'
    listaAntenas = InserirAntenaFim(listaAntenas, 'A', 4, 7);
    printf("\nAntena adicionada na posi��o (4,7) com frequ�ncia 'A'.\n");

    // Imprimir o mapa atualizado
    printf("\nMapa das Antenas (ap�s adi��o):\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas ap�s a adi��o
    printf("\nLista de Antenas ap�s a adi��o:\n");
    ListarAntenas(listaAntenas);

    // Remover uma antena da posi��o (10,10)
    listaAntenas = RemoverAntena(listaAntenas, 4, 7);
    printf("\nAntena na posi��o (10,10) removida (se existia).\n");

    // Imprimir o mapa ap�s a remo��o
    printf("\nMapa das Antenas (ap�s remo��o):\n");
    MostrarMapaAntenas(listaAntenas, numLinhas, numColunas);

    // Mostrar a lista de antenas ap�s a remo��o
    printf("\nLista de Antenas ap�s a remo��o:\n");
    ListarAntenas(listaAntenas);

    // Libertar mem�ria das listas
    DestroiLista(listaAntenas);

    return 0;
}