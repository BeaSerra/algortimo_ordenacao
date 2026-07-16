#include "biblioteca.h"
#include <vector>
#include <utility>
#include <ctime> // Necessário para usar clock() e clock_t da biblioteca <time.h>

// Função auxiliar para o Quick Sort encontrar o pivô
int particionar(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comparacoes++; // Incrementa a comparação feita no 'if'
        if (v[j] <= pivo) {
            i++;
            std::swap(v[i], v[j]);
            trocas++; // Incrementa a troca de posição
        }
    }
    
    std::swap(v[i + 1], v[fim]);
    trocas++; // Incrementa a troca final para colocar o pivô no lugar correto
    
    return i + 1;
}

// Algoritmo Categoria 2: Quick Sort (Recursivo)
void quickSort(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas) {
    if (inicio < fim) {
        int pi = particionar(v, inicio, fim, comparacoes, trocas);
        quickSort(v, inicio, pi - 1, comparacoes, trocas);
        quickSort(v, pi + 1, fim, comparacoes, trocas);
    }
}

// Desenvolve o menu e chama as funções aqui...