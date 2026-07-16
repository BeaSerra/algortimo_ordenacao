// ANA BEATRIZ DA SILVA SERRA - 202304940034     /////
// LUIS FILIPE VIEIRA NEVES - 202204940033      /////
// SOULEYMAN IBRAHIM MAINASSARA - 202415140003 /////
///////////////////////////////////////////////////


#include <iostream>
#include <ctime>
#include <limits> // Necessário para usar o numeric_limits no cin.ignore
#include "biblioteca.h"

using namespace std;

// Função auxiliar para limpar o buffer caso o usuário digite letras ou caracteres inválidos
void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n[ERRO] Entrada invalida. Por favor, digite um numero valido.\n";
}

int menuTamanho() {
    int opcao;
    do {
        cout << "\n========================================\n";
        cout << "  ESCOLHA A QUANTIDADE DE ELEMENTOS\n";
        cout << "========================================\n";
        cout << "1 - 10 elementos\n";
        cout << "2 - 100 elementos\n";
        cout << "3 - 1.000 elementos\n";
        cout << "4 - 10.000 elementos\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) {
            limparBufferEntrada();
            opcao = -1; // Força continuar no loop
            continue;
        }
    } while (opcao < 1 || opcao > 4);

    switch (opcao) {
        case 1: return 10;
        case 2: return 100;
        case 3: return 1000;
        case 4: return 10000;
        default: return 10;
    }
}

int menuDisposicao() {
    int opcao;
    do {
        cout << "\n========================================\n";
        cout << "    DISPOSICAO DOS ELEMENTOS DE ENTRADA\n";
        cout << "========================================\n";
        cout << "1 - Vetor Aleatorio\n";
        cout << "2 - Vetor Ordenado Decrescente\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) {
            limparBufferEntrada();
            opcao = -1;
            continue;
        }
    } while (opcao < 1 || opcao > 2);
    return opcao;
}

int main() {
    TADOrdenacao meuTad;
    int tamanho = 0;
    int disposicao = 0;
    int opcaoMenu = 0;
    
    do {
        cout << "\n========================================\n";
        cout << "      SISTEMA DE ANALISE DE ORDENACAO (TAD)   \n";
        cout << "========================================\n";
        cout << "1 - Definir Tamanho do Vetor (Atual: " << tamanho << ")\n";
        cout << "2 - Definir Disposicao dos Dados (Atual: " << (disposicao == 1 ? "Aleatorio" : (disposicao == 2 ? "Decrescente" : "Nao definido")) << ")\n";
        cout << "3 - Visualizar Vetor de Entrada (Antes da Ordenacao)\n";
        cout << "4 - Executar Insertion Sort (Categoria 1)\n";
        cout << "5 - Executar Quick Sort (Categoria 2)\n";
        cout << "6 - Executar Counting Sort (Categoria 3)\n";
        cout << "0 - Sair do Programa\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcaoMenu)) {
            limparBufferEntrada();
            opcaoMenu = -1;
            continue;
        }
        
        if ((opcaoMenu >= 3 && opcaoMenu <= 6) && (tamanho == 0 || disposicao == 0)) {
            cout << "\n[ERRO] Voce precisa definir o tamanho (Opcao 1) e a disposição (Opcao 2) primeiro!\n";
            continue;
        }

        long comparacoes = 0;
        long trocas = 0;
        clock_t tempo_inicio, tempo_fim;
        double tempo_execucao;

        if (opcaoMenu >= 4 && opcaoMenu <= 6) {
            meuTad.restaurarVetor();
        }

        switch (opcaoMenu) {
            case 1:
                tamanho = menuTamanho();
                if (disposicao != 0) meuTad.inicializarVetor(tamanho, disposicao);
                break;
                
            case 2:
                disposicao = menuDisposicao();
                if (tamanho != 0) meuTad.inicializarVetor(tamanho, disposicao);
                break;
                
            case 3:
                cout << "\n--- VETOR ANTES DA ORDENACAO ---\n";
                meuTad.imprimirVetorAntes();
                break;
                
            case 4: 
                cout << "\nExecutando Insertion Sort...\n";
                tempo_inicio = clock();
                meuTad.insertionSort(comparacoes, trocas);
                tempo_fim = clock();
                
                tempo_execucao = double(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
                
                cout << "\n--- VETOR ORDENADO ---\n";
                meuTad.imprimirVetorDepois();
                
                cout << "\n================ RESULTADOS ================\n";
                cout << "Tempo de Execucao: " << tempo_execucao << " segundos." << endl;
                cout << "Comparacoes      : " << comparacoes << endl;
                cout << "Trocas           : " << trocas << endl;
                cout << "============================================\n";
                break;
                
            case 5: 
                cout << "\nExecutando Quick Sort...\n";
                tempo_inicio = clock();
                meuTad.quickSort(0, tamanho - 1, comparacoes, trocas);
                tempo_fim = clock();
                
                tempo_execucao = double(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
                
                cout << "\n--- VETOR ORDENADO ---\n";
                meuTad.imprimirVetorDepois();
                
                cout << "\n================ RESULTADOS ================\n";
                cout << "Tempo de Execucao: " << tempo_execucao << " segundos." << endl;
                cout << "Comparacoes      : " << comparacoes << endl;
                cout << "Trocas           : " << trocas << endl;
                cout << "============================================\n";
                break;
                
            case 6: 
                cout << "\nExecutando Counting Sort...\n";
                tempo_inicio = clock();
                meuTad.countingSort(comparacoes, trocas);
                tempo_fim = clock();
                
                tempo_execucao = double(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
                
                cout << "\n--- VETOR ORDENADO ---\n";
                meuTad.imprimirVetorDepois();
                
                cout << "\n================ RESULTADOS ================\n";
                cout << "Tempo de Execucao: " << tempo_execucao << " segundos." << endl;
                cout << "Comparacoes      : " << comparacoes << endl;
                cout << "Trocas           : " << trocas << endl;
                cout << "============================================\n";
                break;
                
            case 0:
                cout << "\nEncerrando o programa.\n";
                break;
                
            default:
                if(opcaoMenu != -1) cout << "\n[ERRO] Opcao invalida!\n";
                break;
        }
    } while (opcaoMenu != 0);
    
    return 0;
}