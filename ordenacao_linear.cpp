/*
 * Arquivo: ordenacao_linear.cpp
 * Autor: Souleymane Ibrahim
 * Disciplina: Estrutura de Dados
 * Descrição: Implementação do Counting Sort — algoritmo de ordenação
 *            linear (não baseado em comparações entre elementos).
 */

#include "biblioteca.h"
#include <algorithm>

// Algoritmo Categoria 3: Counting Sort
// Complexidade: O(n + k), onde k é o intervalo de valores (maior - menor)
void countingSort(std::vector<int>& v, long &comparacoes, long &trocas) {
    comparacoes = 0;
    trocas = 0;

    int n = v.size();
    if (n == 0) return;

    int maior = v[0];
    int menor = v[0];
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (v[i] > maior) maior = v[i];

        comparacoes++;
        if (v[i] < menor) menor = v[i];
    }

    int intervalo = maior - menor + 1;

    std::vector<int> contagem(intervalo, 0);
    for (int i = 0; i < n; i++) {
        contagem[v[i] - menor]++;
    }

    int indice = 0;
    for (int valor = 0; valor < intervalo; valor++) {
        while (contagem[valor] > 0) {
            v[indice] = valor + menor;
            trocas++;
            indice++;
            contagem[valor]--;
        }
    }
}


// Desenvolve o menu e chama as funções aqui...
