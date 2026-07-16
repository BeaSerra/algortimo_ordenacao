//LUIS FILIPE VIEIRA NEVES - 202204940033
// Descrição: implementação do algoritmo de ordenação Quick Sort (Categoria 2 — baseado em comparações diretas para a ordenação final).


#include "biblioteca.h"
#include <utility>

using namespace std;

// Função auxiliar para o Quick Sort encontrar o pivô (Membro da classe TADOrdenacao)
int TADOrdenacao::particionar(int inicio, int fim, long &comparacoes, long &trocas) {
  
    int pivo = vetorTrabalho[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comparacoes++; // Incrementa a comparação
        if (vetorTrabalho[j] <= pivo) {
            i++;
            swap(vetorTrabalho[i], vetorTrabalho[j]);
            trocas++; // Incrementa a troca realizada
        }
    }
    
    swap(vetorTrabalho[i + 1], vetorTrabalho[fim]);
    trocas++; // Incrementa a troca final para colocar o pivô no lugar correto
    
    return i + 1;
}

// Algoritmo Categoria 2: Quick Sort Recursivo (Membro da classe TADOrdenacao)
void TADOrdenacao::quickSort(int inicio, int fim, long &comparacoes, long &trocas) {
    // Se for a primeira chamada recursiva (raiz), garante que os contadores iniciam zerados
    if (inicio == 0 && fim == (int)vetorTrabalho.size() - 1) {
        comparacoes = 0;
        trocas = 0;
    }

    if (inicio < fim) {
        // Chama a função de particionamento da própria classe
        int pi = particionar(inicio, fim, comparacoes, trocas);
        
        // Chamadas recursivas para as metades esquerda e direita
        quickSort(inicio, pi - 1, comparacoes, trocas);
        quickSort(pi + 1, fim, comparacoes, trocas);
    }
}