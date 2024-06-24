#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <locale.h>

#include "utilsLib.h"
#include "pessoasLib.h"
#include "pesquisaPessoasLib.h"

using namespace std;

void procurarCliente() {
    int tipo, cliente_code;
    char cliente_name[50];

    printf("\nComo vai pesquisar?\n");
    printf("1: Codigo\n");
    printf("2: Nome\n");
    printf("Opcao: ");
    scanf("%i",&tipo);

    Cliente cliente;
    fstream arquivoLer("clientes.dat", ios::in);

    switch (tipo) {
    case 1:
        printf("\nDigite o codigo: ");
        scanf("%i", &cliente_code);

        while (arquivoLer.read((char*)&cliente, sizeof(cliente))) {
            if (cliente_code == cliente.getCodigo()) {
                cliente.imprimir();
            }
            else {
                printf("\nCliente nao encontrado!\n\n");
            }
        };

        arquivoLer.close();
        break;
    case 2:
        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(cliente_name, sizeof(cliente_name), stdin);
        cliente_name[strcspn(cliente_name, "\n")] = 0;

        fstream arquivoLer("clientes.dat", ios::in);
        while (arquivoLer.read((char*)&cliente, sizeof(cliente))) {
            if(strcmp(cliente_name, cliente.nome) == 0) {
                cliente.imprimir();
                arquivoLer.close();
                break;
            } else {
                printf("\nCliente nao encontrado!\n\n");
            }
        };
        arquivoLer.close();
        break;
    };
};

void procurarFuncionario() {
    int tipo, funcionario_code;
    char funcionario_name[50];

    printf("\nComo vai pesquisar?\n");
    printf("1: Codigo\n");
    printf("2: Nome\n");
    printf("Opcao: ");
    scanf("%i",&tipo);

    Funcionario funcionario;
    fstream arquivoLer("funcionarios.dat", ios::in);

    switch (tipo) {
    case 1:
        printf("\nDigite o codigo: ");
        scanf("%i", &funcionario_code);

        while (arquivoLer.read((char*)&funcionario, sizeof(funcionario))) {
            if (funcionario_code == funcionario.getCodigo()) {
                funcionario.imprimir();
            }
            else {
                printf("\nFuncionario nao encontrado!\n\n");
            }
        };

        arquivoLer.close();
        break;
    case 2:
        printf("Digite o nome: ");
        fflush(stdin);
        fgets(funcionario_name, sizeof(funcionario_name), stdin);
        funcionario_name[strcspn(funcionario_name, "\n")] = 0;

        ifstream arquivoLer;
        arquivoLer.open("funcionarios.dat", ios::in | ios::out);
        while (arquivoLer.read((char*)&funcionario, sizeof(funcionario))) {
            if(strcmp(funcionario_name, funcionario.nome) == 0) {
                funcionario.imprimir();
                arquivoLer.close();
                break;
            } else {
                printf("\nFuncionario nao encontrado!\n\n");
            }
        };
        arquivoLer.close();
        break;
    };
};