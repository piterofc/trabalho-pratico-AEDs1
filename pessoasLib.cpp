#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "utilsLib.h"
#include "pessoasLib.h"
#include "estadiaLib.h"
#include "pesquisaPessoasLib.h"

using namespace std;

// Menus

void menuClientes() {
    //setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        printf("\nClientes - Hotel Descanso Garantido\n\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Procurar por cliente\n");
        printf("4 - Calcular pontos de fidelidade\n");
        printf("5 - Listar estadias de um cliente\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &opcao);

        Cliente cliente;
        int codigoCliente;

        switch (opcao) {
            case 1:
                limparTerminal();
                cliente.criar();
                break;
            case 2:
                limparTerminal();
                listarClientes();
                break;
            case 3:
                limparTerminal();
                procurarCliente();
                break;
            case 4:
                limparTerminal();
                int codigo;
                printf("Digite o codigo do cliente: ");
                scanf("%i", &codigo);
                calcularPontosFidelidade(codigo);
                break;
            case 5:
                limparTerminal();
                printf("Digite o codigo do cliente: ");
                scanf("%i", &codigoCliente);
                listarEstadiasCliente(codigoCliente);
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

void menuFuncionarios() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        printf("\nFuncionarios - Hotel Descanso Garantido\n\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Procurar por funcionario\n");
        printf("3 - Listar funcionarios\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &opcao);

        Funcionario funcionario;

        switch (opcao) {
            case 1:
                limparTerminal();
                funcionario.criar();
                break;
            case 2:
                limparTerminal();
                procurarFuncionario();
                break;
            case 3:
                limparTerminal();
                listarFuncionarios();
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


// Cliente class

void Cliente::criar() {
    setlocale(LC_ALL, "Portuguese");

    // printf("Codigo: ");
    // scanf("%i", &codigo);
    codigo = gerarCodigoAleatorio();
    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Endereco: ");
    fflush(stdin);
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = 0;

    printf("Telefone: ");
    fflush(stdin);
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = 0;

    fstream clientesFile("clientes.dat", ios::in | ios::out | ios::app);

    // Verifica se o cliente já existe
    if (verificarCliente(codigo)) {
        printf("Esse cliente ja existe!\n\n");
    } else {
        clientesFile.write((char*)this, sizeof(Cliente));
        printf("\nCliente adicionado com sucesso!\n\n");
    }

    clientesFile.close();
};

void Cliente::imprimir() {
    setlocale(LC_ALL, "Portuguese");

    printf("Codigo: %i\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Endereco: %s\n", endereco);
    printf("Telefone: %s\n", telefone);
    printf("Pontos de fidelidade: %i\n", getFidelidade());
    printf("\n");
};

int Cliente::getCodigo() {
    return codigo;
};

int Cliente::getFidelidade() {
    Estadia estadia;
    int diarias = 0;

    fstream arquivoLer("estadias.dat", ios::in);

    while (arquivoLer.read((char*)&estadia, sizeof(estadia))) {
        int estadiaCC = estadia.getCodigoCliente();

        if (estadiaCC == codigo) {
            diarias += estadia.getDiarias();
        }
    }

    arquivoLer.close();
    return diarias * 10;
};


// Cliente functions

int verificarCliente(int codigo) {
    setlocale(LC_ALL, "Portuguese");

    Cliente cliente;
    fstream clientesFile("clientes.dat", ios::in);

    if (!clientesFile && !clientesFile.is_open()) {
        printf("Não foi possível abrir o arquivo!\n\n");
        // return 0;
    }

    while (clientesFile.read((char*)&cliente, sizeof(cliente))) {
        if (cliente.getCodigo() == codigo) {
            clientesFile.close();
            return 1;
        }
    }

    clientesFile.close();
    return 0;
};

void listarClientes() {
    setlocale(LC_ALL, "Portuguese");

    Cliente cliente;
    fstream clientesFile("clientes.dat", ios::in);

    if (!clientesFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return;
    }

    while (clientesFile.read((char*)&cliente, sizeof(cliente))) {
        cliente.imprimir();
    }

    clientesFile.close();
};

void calcularPontosFidelidade(int codigo) {
    setlocale(LC_ALL, "Portuguese");

    Cliente cliente;
    fstream clientesFile("clientes.dat", ios::in);

    if (!clientesFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return;
    }

    while (clientesFile.read((char*)&cliente, sizeof(cliente))) {
        if (cliente.getCodigo() == codigo) {
            int pontos = cliente.getFidelidade();
            printf("Pontos de fidelidade: %i\n", pontos);
        }
    }

    clientesFile.close();
};

void listarEstadiasCliente(int codigo) {
    setlocale(LC_ALL, "Portuguese");

    Estadia estadia;
    fstream estadiasFile("estadias.dat", ios::in | ios::out | ios::app);

    if (!estadiasFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return;
    }

    int existe = 0;

    // Verifica se o cliente existe
    if (!verificarCliente(codigo)) {
        printf("Cliente não encontrado!\n\n");
        return;
    }

    while (estadiasFile.read((char*)&estadia, sizeof(estadia))) {
        if (estadia.getCodigoCliente() == codigo) {
            estadia.imprimir();
            existe = 1;
        }
    }

    if (!existe) {
        printf("Nenhuma estadia encontrada para esse cliente!\n\n");
    }

    estadiasFile.close();
};



// Funcionario class

void Funcionario::criar() {
    setlocale(LC_ALL, "Portuguese");

    codigo = gerarCodigoAleatorio();

    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Telefone: ");
    fflush(stdin);
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = 0;

    printf("Cargo: ");
    fflush(stdin);
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = 0;

    printf("Salario: ");
    scanf("%f", &salario);

    fstream funcionariosFile("funcionarios.dat", ios::in | ios::out | ios::app);

    // Verifica se o funcionário já existe
    if (verificarFuncionario(codigo)) {
        printf("Esse funcionario ja existe!\n\n");
    } else {
        funcionariosFile.write((char*)this, sizeof(Funcionario));
        printf("Funcionario adicionado com sucesso!\n\n");
    }

    funcionariosFile.close();
};

void Funcionario::imprimir() {
    setlocale(LC_ALL, "Portuguese");

    printf("Codigo: %i\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Telefone: %s\n", telefone);
    printf("Cargo: %s\n", cargo);
    printf("Salario: R$%.2f\n", salario);
    printf("\n");
};

int Funcionario::getCodigo() {
    return codigo;
};


// Funcionario functions

int verificarFuncionario(int codigo) {
    setlocale(LC_ALL, "Portuguese");

    Funcionario funcionario;
    fstream funcionariosFile("funcionarios.dat", ios::in);

    if (!funcionariosFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return 0;
    }

    while (funcionariosFile.read((char*)&funcionario, sizeof(funcionario))) {
        if (funcionario.getCodigo() == codigo) {
            funcionariosFile.close();
            return 1;
        }
    }

    funcionariosFile.close();
    return 0;
};

void listarFuncionarios() {
    setlocale(LC_ALL, "Portuguese");

    Funcionario funcionario;
    fstream funcionariosFile("funcionarios.dat", ios::in | ios::out);

    if (!funcionariosFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return;
    }

    while (funcionariosFile.read((char*)&funcionario, sizeof(funcionario))) {
        funcionario.imprimir();
    }

    funcionariosFile.close();
};