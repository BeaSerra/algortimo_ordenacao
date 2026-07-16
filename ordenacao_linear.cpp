/*
 * Souleymane Ibrahim
 * Descrição: Implementação do Counting Sort — algoritmo de ordenação linear (Categoria 3 — não baseado em comparações diretas para a ordenação final).
 */

#include "biblioteca.h"
#include <algorithm>
#include <vector>

// Algoritmo Categoria 3: Counting Sort (Membro da classe TADOrdenacao)
// Complexidade: O(n + k), onde "n" é o número de elementos e "k" é o intervalo de valores
void TADOrdenacao::countingSort(long &comparacoes, long &trocas) {
    // Zera os contadores no início da execução
    comparacoes = 0;
    trocas = 0;

    int n = vetorTrabalho.size();
    
    // Se o vetor estiver vazio, encerra a função
    if (n == 0) return;

    //Encontra o maior e o menor elemento do vetor
    int maior = vetorTrabalho[0];
    int menor = vetorTrabalho[0];
    
    for (int i = 1; i < n; i++) {
        comparacoes++; // Conta a comparação do 'maior'
        if (vetorTrabalho[i] > maior) {
            maior = vetorTrabalho[i];
        }

        comparacoes++; // Conta a comparação do 'menor'
        if (vetorTrabalho[i] < menor) {
            menor = vetorTrabalho[i];
        }
    }

    //Calcula o tamanho necessário para o vetor de contagem
    int intervalo = maior - menor + 1;

    // Cria o vetor de contagem preenchido com zeros
    std::vector<int> contagem(intervalo, 0);
    
    //Conta a frequência de cada elemento do vetor original
    for (int i = 0; i < n; i++) {
        // Subtrai 'menor' para lidar com números negativos ou evitar desperdício de memória
        contagem[vetorTrabalho[i] - menor]++;
    }

    //Reconstrói o vetor original, agora ordenado
    int indice = 0;
    for (int valor = 0; valor < intervalo; valor++) {
        while (contagem[valor] > 0) {
            // Coloca o elemento de volta no vetor de trabalho
            vetorTrabalho[indice] = valor + menor;
            
            trocas++; // Registra a inserção como uma troca
            indice++; // Avança para a próxima posição do vetor
            contagem[valor]--; // Diminui a contagem do elemento que acabou de ser inserido
        }
    }
}