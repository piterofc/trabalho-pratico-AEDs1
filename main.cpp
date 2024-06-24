#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "utilsLib.h"
#include "pessoasLib.h"
#include "quartoLib.h"
#include "estadiaLib.h"

using namespace std;

/*
void funcCadastrarCliente() {
    Cliente cliente;
    cliente.criar();
    cliente.imprimir();
};

void funcCadastrarFuncionario() {
    Funcionario funcionario;
    funcionario.criar();
    funcionario.imprimir();
};

void funcCadastrarQuarto() {
    Quarto quarto;
    quarto.criar();
    quarto.imprimir();
};

void funcCadastrarEstadia() {
    Estadia estadia;
    estadia.criar();
    estadia.imprimir();
};

void funcDarBaixaEstadia() {
    int id;
    printf("Digite o numero do quarto ou o codigo da estadia: ");
    scanf("%i", &id);
    darBaixaEstadia(id);
};

void funcListarEstadias() {
    listarEstadias();
};

void funcCalcularPontosFidelidade() {
    int codigo;
    printf("Digite o codigo do cliente: ");
    scanf("%i", &codigo);
    calcularPontosFidelidade(codigo);
};

void funcListarQuartos() {
    listarQuartos();
};
*/


int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicializa os arquivos
    initFiles();

    printf("Trabalho interdisciplinar AEDs e Fundamentos da Engenharia de Software");
    printf("Feito por:\n- Gabriel Rodrigues Maciel de Abreu\n- Leonardo de Souza Galvão\n- Pedro Henrique Novais Baranda");

    // Menu
    int opcao;
    do {
        printf("\nMenu - Hotel Descanso Garantido\n\n");
        printf("1 - Clientes\n");
        printf("2 - Funcionarios\n");
        printf("3 - Quartos\n");
        printf("4 - Estadias\n");
        printf("0 - SAIR\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            // Menu de clientes
            limparTerminal();
            menuClientes();
            break;
        case 2:
            // Menu de funcionários
            limparTerminal();
            menuFuncionarios();
            break;
        case 3:
            // Menu de quartos
            limparTerminal();
            menuQuartos();
            break;
        case 4:
            // Menu de estadias
            limparTerminal();
            menuEstadias();
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            limparTerminal();
            printf("\n===============\nOpcao invalida!\n===============\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
