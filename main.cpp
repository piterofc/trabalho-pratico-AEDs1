#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int opcao;

    // Menu
    do {
        printf("\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar funcionario\n");
        printf("3 - Cadastrar quarto\n");
        printf("4 - Cadastrar estadia\n");
        printf("5 - Dar baixa em estadia\n");
        printf("6 - Pesquisar por cliente/funcionario\n");
        printf("7 - Exibir estadias\n");
        printf("8 - Mostrar pontos de fidelidade\n");
        printf("9 - SAIR\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            // Cadastro de cliente
            break;
        case 2:
            // Cadastro de funcionário
            break;
        case 3:
            // Cadastro de quarto
            break;
        case 4:
            // Cadastro de estadia
            break;
        case 5:
            // Baixa em estadia
            break;
        case 6:
            // Pesquisa por cliente/funcionário
            break;
        case 7:
            // Exibição de estadias
            break;
        case 8:
            // Cálculo de pontos de fidelidade
            break;
        case 9:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 9);

    return 0;
}