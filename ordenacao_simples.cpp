// ANA BEATRIZ DA SILVA SERRA - 202304940034
// Descrição: implementação do algoritmo de ordenação Insertion Sort (Categoria 1 — baseado em comparações diretas para a ordenação final).

#include "biblioteca.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

TADOrdenacao::TADOrdenacao() {
    // Construtor padrão (inicializa o TAD vazio)
}

void TADOrdenacao::inicializarVetor(int tamanho, int disposicao) {
    vetorOriginal.resize(tamanho); // Ajusta o tamanho do vetor original

    if (disposicao == 1) { // 1 = Vetor Aleatório
        srand(time(0)); // Inicializa a semente para geração de números aleatórios
        for (int i = 0; i < tamanho; i++) {
            vetorOriginal[i] = rand() % 20000; // Gera números de 0 até 19.999
        }
    } else { // 2 = Vetor Decrescente
        for (int i = 0; i < tamanho; i++) {
            vetorOriginal[i] = tamanho - i; // Preenche em ordem decrescente
        }
    }
    
    restaurarVetor(); // Garante que o vetor de trabalho receba os dados recém-gerados
}

void TADOrdenacao::restaurarVetor() {
    // Copia os dados do vetor original intacto para o vetor de trabalho que será ordenado
    vetorTrabalho = vetorOriginal;
}

void TADOrdenacao::imprimirVetorAntes() const {
    // Imprime o vetor original apenas se tiver até 100 elementos (evita poluir/travar o terminal)
    if (vetorOriginal.size() <= 100) {
        for (int x : vetorOriginal) cout << x << " ";
        cout << endl;
    } else {
        cout << "[Vetor muito grande para ser exibido na tela (" << vetorOriginal.size() << " elementos)]" << endl;
    }
}

void TADOrdenacao::imprimirVetorDepois() const {
    // Imprime o vetor de trabalho (já ordenado) apenas se tiver até 100 elementos
    if (vetorTrabalho.size() <= 100) {
        for (int x : vetorTrabalho) cout << x << " ";
        cout << endl;
    } else {
        cout << "[Vetor muito grande para ser exibido na tela (" << vetorTrabalho.size() << " elementos)]" << endl;
    }
}

int TADOrdenacao::obterTamanho() const {
    return vetorOriginal.size(); // Retorna a quantidade de elementos do vetor
}

void TADOrdenacao::insertionSort(long &comparacoes, long &trocas) {
    //  Zera os contadores no início da execução
    comparacoes = 0;
    trocas = 0;
    int n = vetorTrabalho.size();
    
    //  Percorre o vetor a partir do segundo elemento (índice 1)
    for (int i = 1; i < n; i++) {
        int chave = vetorTrabalho[i]; // Elemento atual que precisa ser posicionado
        int j = i - 1;                // Índice do elemento anterior
        
        //  Verifica os elementos anteriores e desloca os maiores para a direita
        while (j >= 0) {
            comparacoes++; // Conta a comparação do 'if' abaixo
            
            if (vetorTrabalho[j] > chave) {
                vetorTrabalho[j + 1] = vetorTrabalho[j]; // Desloca o elemento maior para a direita
                trocas++; // Registra o deslocamento como uma troca
                j--;      // Volta um índice para continuar verificando
            } else {
                // Se o elemento anterior for menor ou igual, a posição correta foi encontrada
                break; 
            }
        }
        //  Insere a chave no espaço vazio que foi aberto
        vetorTrabalho[j + 1] = chave;
    }
}