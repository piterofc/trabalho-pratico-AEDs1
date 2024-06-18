#include "quartoLib.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Getters
int Quarto::getNumero() {
    return numero;
};
int Quarto::getQuantidadeHospedes() {
    return quantidade_hospedes;
};
float Quarto::getCustoDiaria() {
    return custo_diaria;
};
int Quarto::getStatus() {
    return status;
};

// Função para criar o quarto
void Quarto::adicionarQuarto() {
    printf("Insira o numero do quarto: ");
    scanf("%i", &numero);
    printf("Insira a quantidade de hospedes: ");
    scanf("%i", &quantidade_hospedes);
    printf("Insira o custo da diaria: ");
    scanf("%f", &custo_diaria);

    ofstream outFile;
    outFile.open("quartos.dat", ios::binary | ios::app);

    // Verifica se o quarto já existe
    if (verificarQuarto(numero)) {
        printf("Esse quarto ja existe!\n\n");
    } else {
        outFile.write((char*)this, sizeof(Quarto));
        printf("Quarto adicionado com sucesso!\n\n");
    }

    outFile.close();
};

// Função para imprimir o quarto
void Quarto::imprimeQuarto() {
    printf("Numero do quarto: %i\n", numero);
    printf("Quantidade de hospedes: %i\n", quantidade_hospedes);
    printf("Custo da diaria: %.2f\n", custo_diaria);
};


// Função para verificar se um quarto já existe
int verificarQuarto(int num) {
    Quarto quarto;
    ifstream inFile;

    inFile.open("quartos.dat", ios::binary);

    if (!inFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return 0;
    }

    while (inFile.read((char*)&quarto, sizeof(quarto))) {
        if (quarto.getNumero() == num) {
            inFile.close();
            return 1;
        }
    }

    inFile.close();
    return 0;
};

// Função para listar todos os quartos
void listarQuartos() {
    Quarto quarto;
    ifstream inFile;

    inFile.open("quartos.dat", ios::binary);

    if (!inFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
    } else {
        printf("Quartos cadastrados:\n\n");
        while (inFile.read((char*)&quarto, sizeof(quarto))) {
            quarto.imprimeQuarto();
            printf("\n");
        }
    }

    inFile.close();
};