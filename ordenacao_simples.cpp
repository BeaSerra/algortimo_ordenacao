// ANA BEATRIZ DA SILVA SERRA - 202304940034
// Descrição: implementação do algoritmo de ordenação Insertion Sort (Categoria 1 — baseado em comparações diretas para a ordenação final).

#include "biblioteca.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

TADOrdenacao::TADOrdenacao() {
    // Construtor padrão
}

void TADOrdenacao::inicializarVetor(int tamanho, int disposicao) {
    vetorOriginal.resize(tamanho);
    if (disposicao == 1) { // Aleatório
        srand(time(0));
        for (int i = 0; i < tamanho; i++) {
            vetorOriginal[i] = rand() % 20000; // gera números até 20.000
        }
    } else { // Decrescente
        for (int i = 0; i < tamanho; i++) {
            vetorOriginal[i] = tamanho - i;
        }
    }
    restaurarVetor(); // Inicializa o vetor de trabalho
}

void TADOrdenacao::restaurarVetor() {
    vetorTrabalho = vetorOriginal;
}

void TADOrdenacao::imprimirVetorAntes() const {
    // Imprime o vetor original (só se for pequeno para não quebrar o terminal)
    if (vetorOriginal.size() <= 100) {
        for (int x : vetorOriginal) cout << x << " ";
        cout << endl;
    } else {
        cout << "[Vetor muito grande para ser exibido na tela (" << vetorOriginal.size() << " elementos)]" << endl;
    }
}

void TADOrdenacao::imprimirVetorDepois() const {
    if (vetorTrabalho.size() <= 100) {
        for (int x : vetorTrabalho) cout << x << " ";
        cout << endl;
    } else {
        cout << "[Vetor muito grande para ser exibido na tela (" << vetorTrabalho.size() << " elementos)]" << endl;
    }
}

int TADOrdenacao::obterTamanho() const {
    return vetorOriginal.size();
}

void TADOrdenacao::insertionSort(long &comparacoes, long &trocas) {
    comparacoes = 0;
    trocas = 0;
    int n = vetorTrabalho.size();
    for (int i = 1; i < n; i++) {
        int chave = vetorTrabalho[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (vetorTrabalho[j] > chave) {
                vetorTrabalho[j + 1] = vetorTrabalho[j];
                trocas++;
                j--;
            } else {
                break;
            }
        }
        vetorTrabalho[j + 1] = chave;
    }
}