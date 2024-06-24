#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilsLib.h"

using namespace std;

void initFiles() {
    ifstream clientesFile("clientes.dat");
    ifstream funcionariosFile("funcionarios.dat");
    ifstream quartosFile("quartos.dat");
    ifstream estadiasFile("estadias.dat");

    if (!clientesFile) {
        ofstream newClientesFile("clientes.dat");
        newClientesFile.close();
    }
    if (!funcionariosFile) {
        ofstream newFuncionariosFile("funcionarios.dat");
        newFuncionariosFile.close();
    }
    if (!quartosFile) {
        ofstream newQuartosFile("quartos.dat");
        newQuartosFile.close();
    }
    if (!estadiasFile) {
        ofstream newEstadiasFile("estadias.dat");
        newEstadiasFile.close();
    }

    // Fecha os arquivos
    clientesFile.close();
    funcionariosFile.close();
    quartosFile.close();
    estadiasFile.close();
};

int gerarCodigoAleatorio() {
    srand(time(NULL));
    return rand();
}

void limparTerminal() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}