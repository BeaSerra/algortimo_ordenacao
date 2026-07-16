#include <iostream>
#include <chrono> //mede o tempo em C++
#include "biblioteca.h"

// --- TRECHO DE EXEMPLO PARA O MENU MAIN.CPP ---
#include <iostream>
#include <ctime> // Incluir a biblioteca de tempo que você configurou
#include "biblioteca.h"

// Dentro do switch/case ou do menu onde o Quick Sort for escolhido:
long comparacoes = 0;
long trocas = 0;

// 1. Inicia o temporizador exatamente antes da ordenação começar
clock_t tempo_inicio = clock(); 

// 2. Executa a ordenação do vetor 'v'
quickSort(v, 0, v.size() - 1, comparacoes, trocas);

// 3. Encerra o temporizador imediatamente após o fim
clock_t tempo_fim = clock(); 

// 4. Calcula o tempo decorrido em segundos
double tempo_execucao = double(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

// 5. Exibe os resultados exigidos pelo professor
std::cout << "Tempo de Execucao: " << tempo_execucao << " segundos." << std::endl;
std::cout << "Comparacoes: " << comparacoes << std::endl;
std::cout << "Trocas: " << trocas << std::endl;


int main() {
    // Código do menu (Integrante 1)
    return 0;
}