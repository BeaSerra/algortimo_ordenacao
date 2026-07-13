#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>

// ============================================================================
// PARTE 1: INTEGRAÇÃO, INTERFACE E ALGORITMO SIMPLES (Integrante 1)
// ============================================================================

// Preenche o vetor com números aleatórios
void gerarVetorAleatorio(std::vector<int>& v, int tam);

// Preenche o vetor de forma decrescente (pior caso para muitos algoritmos)
void gerarVetorDecrescente(std::vector<int>& v, int tam);

// Exibe os elementos do vetor na tela (utilizar apenas para vetores pequenos)
void imprimirVetor(const std::vector<int>& v);

// Algoritmo Categoria 1: Insertion Sort (Modifica o vetor e calcula trocas/comparações)
void insertionSort(std::vector<int>& v, long &comparacoes, long &trocas);


// ============================================================================
// PARTE 2: ALGORITMO AVANÇADO (Integrante 2)
// ============================================================================

// Função auxiliar para o Quick Sort encontrar o pivô
int particionar(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas);

// Algoritmo Categoria 2: Quick Sort (Recursivo)
void quickSort(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas);


// ============================================================================
// PARTE 3: ALGORITMO LINEAR (Integrante 3)
// ============================================================================

// Algoritmo Categoria 3: Counting Sort (Não baseado em comparações)
void countingSort(std::vector<int>& v, long &comparacoes, long &trocas);

#endif 