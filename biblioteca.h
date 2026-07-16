#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector> 

class TADOrdenacao {
private:
    std::vector<int> vetorOriginal;  // Dados encapsulados (o vetor de entrada)
    std::vector<int> vetorTrabalho;  // Cópia usada para fazer a ordenação sem perder o original

    // Função auxiliar do Quick Sort 
    int particionar(int inicio, int fim, long &comparacoes, long &trocas);

public:
    // Construtor
    TADOrdenacao();

    void inicializarVetor(int tamanho, int disposicao); // Define tamanho e gera os valores
    void imprimirVetorAntes() const;                     // Apresenta o vetor antes da ordenação
    void imprimirVetorDepois() const;                    // Apresenta o vetor depois da ordenação
    void restaurarVetor();                              // Restaura o vetor de trabalho para o estado original

    // Algoritmos de Ordenação
    void insertionSort(long &comparacoes, long &trocas);
    void quickSort(int inicio, int fim, long &comparacoes, long &trocas);
    void countingSort(long &comparacoes, long &trocas);

    // Funções auxiliares de acesso
    int obterTamanho() const;
};

#endif // BIBLIOTECA_H