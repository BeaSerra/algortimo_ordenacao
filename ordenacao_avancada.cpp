#include "biblioteca.h"
#include <vector>
#include <utility>

long comparacoes_globais = 0;
long trocas_globais = 0;

long* p_comparacoes = &comparacoes_globais;
long* p_trocas = &trocas_globais;

int particionar(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        (*p_comparacoes)++;
        comparacoes++;
        if (v[j] <= pivo) {
            i++;
            std::swap(v[i], v[j]);
            (*p_trocas)++;
            trocas++;
        }
    }
    
    std::swap(v[i + 1], v[fim]);
    (*p_trocas)++;
    trocas++;
    
    return i + 1;
}

void quickSort(std::vector<int>& v, int inicio, int fim, long &comparacoes, long &trocas) {
    if (inicio < fim) {
        int pi = particionar(v, inicio, fim, comparacoes, trocas);
        quickSort(v, inicio, pi - 1, comparacoes, trocas);
        quickSort(v, pi + 1, fim, comparacoes, trocas);
    }
}







// Desenvolve o menu e chama as funções aqui...