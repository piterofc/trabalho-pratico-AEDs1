#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "utilsLib.h"
#include "quartoLib.h"

using namespace std;


// Menu

void menuQuartos() {
    //setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        printf("\nQuartos - Hotel Descanso Garantido\n\n");
        printf("1 - Cadastrar quarto\n");
        printf("2 - Listar quartos\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &opcao);

        Quarto quarto;

        switch (opcao) {
            case 1:
                limparTerminal();
                quarto.criar();
                break;
            case 2:
                limparTerminal();
                listarQuartos();
                break;
            case 0:
                limparTerminal();
                break;
            default:
                limparTerminal();
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);
};


// Quuartos class

void Quarto::criar() {
    setlocale(LC_ALL, "Portuguese");

    printf("Insira o numero do quarto: ");
    scanf("%i", &numero);
    printf("Insira a quantidade de hospedes: ");
    scanf("%i", &capacidade);
    printf("Insira o custo da diaria: ");
    scanf("%f", &custo_diaria);

    fstream quartosFile("quartos.dat", ios::in | ios::out | ios::app);

    // Verifica se o quarto já existe
    if (verificarQuarto(numero)) {
        printf("Esse quarto ja existe!\n\n");
    } else {
        quartosFile.write((char*)this, sizeof(Quarto));
        printf("Quarto adicionado com sucesso!\n\n");
    }

    quartosFile.close();
};

void Quarto::imprimir() {
    setlocale(LC_ALL, "Portuguese");

    printf("Numero: %i\n", numero);
    printf("Quantidade de hospedes: %i\n", capacidade);
    printf("Custo da diaria: R$%.2f\n", custo_diaria);
};

int Quarto::getNumero() {
    return numero;
};
int Quarto::getCapacidade() {
    return capacidade;
};
float Quarto::getCustoDiaria() {
    return custo_diaria;
};


// Quarto functions

int verificarQuarto(int num) {
    setlocale(LC_ALL, "Portuguese");

    Quarto quarto;
    fstream quartosFile("quartos.dat", ios::in);

    if (!quartosFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return 0;
    }

    while (quartosFile.read((char*)&quarto, sizeof(quarto))) {
        if (quarto.getNumero() == num) {
            quartosFile.close();
            return 1;
        }
    }

    quartosFile.close();
    return 0;
};

float getQuartoCusto(int num) {
    setlocale(LC_ALL, "Portuguese");

    Quarto quarto;
    fstream quartosFile("quartos.dat", ios::in);

    if (!quartosFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return 0;
    }

    while (quartosFile.read((char*)&quarto, sizeof(quarto))) {
        if (quarto.getNumero() == num) {
            quartosFile.close();
            return quarto.getCustoDiaria();
        }
    }

    quartosFile.close();
    return 0;
};

void listarQuartos() {
    setlocale(LC_ALL, "Portuguese");

    Quarto quarto;
    fstream quartoFile("quartos.dat", ios::in);

    if (!quartoFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
    } else {
        printf("Quartos cadastrados:\n\n");
        while (quartoFile.read((char*)&quarto, sizeof(quarto))) {
            quarto.imprimir();
            printf("\n");
        }
    }

    quartoFile.close();
};