#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "utilsLib.h"
#include "pessoasLib.h"
#include "quartoLib.h"
#include "estadiaLib.h"

using namespace std;

// Menu

void menuEstadias() {
    //setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        printf("\nEstadias - Hotel Descanso Garantido\n\n");
        printf("1 - Cadastrar estadia\n");
        printf("2 - Listar estadias\n");
        printf("3 - Listar estadias de um cliente\n");
        printf("4 - Dar baixa em estadia\n");
        printf("0 - Voltar\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%i", &opcao);

        Estadia estadia;
        int codigoCliente;

        switch (opcao) {
            case 1:
                limparTerminal();
                estadia.criar();
                break;
            case 2:
                limparTerminal();
                listarEstadias();
                break;
            case 3:
                limparTerminal();
                printf("Digite o codigo do cliente: ");
                scanf("%i", &codigoCliente);
                listarEstadiasCliente(codigoCliente);
                break;
            case 4:
                limparTerminal();
                int id;
                printf("Digite o numero do quarto ou o codigo da estadia: ");
                scanf("%i", &id);
                darBaixaEstadia(id);
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



// Data class

int Data::totalDias() {
    int total = 0;
    total += dia;
    total += mes * 30;
    total += ano * 365;
    return total;
};

int Data::totalSegundos() {
    int total = 0;
    total += segundos;
    total += minutos * 60;
    total += horas * 3600;
    return total;
};

/* Implementação original com horas, minutos e segundos
void Data::criar() {
    printf("Dia (dd/mm/aaaa): ");
    scanf("%02i/%02i/%04i", &dia, &mes, &ano);
    printf("Horario (hh:mm:ss): ");
    scanf("%02i:%02i:%02i", &horas, &minutos, &segundos);
};
*/

void Data::criar() {
    // printf("Dia (dd/mm/aaaa): ");
    scanf("%02i/%02i/%04i", &dia, &mes, &ano);
};



// Estadia class

void Estadia::criar() {
    setlocale(LC_ALL, "Portuguese");

    // printf("Digite o codigo da estadia: ");
    // scanf("%i", &codigo);
    codigo = gerarCodigoAleatorio();

    if (!codigo) {
        printf("Codigo invalido!\nCriacao de estadia cancelada.\n");
        return;
    }

    printf("Digite o codigo do cliente: ");
    scanf("%i", &codigo_cliente);

    if (!codigo_cliente) {
        printf("Codigo de cliente invalido!\nCriacao de estadia cancelada.\n");
        return;
    }

    // Implementar verificação de existência do cliente
    if (!verificarCliente(codigo_cliente)) {
        printf("Cliente nao encontrado!\nCriacao de estadia cancelada.\n");
        return;
    }

    printf("Digite a data de entrada:");
    data_entrada.criar();

    // if (!data_entrada.totalDias() || !data_entrada.totalSegundos()) {
    if (!data_entrada.totalDias()) {
        printf("Data de entrada invalida!\nCriacao de estadia cancelada.\n");
        return;
    }

    /*
    if (data_entrada.horas < 14) {
        printf("As diarias comecam a partir de 14:00!\nCriacao de estadia cancelada.\n");
        return;
    }
    */

    printf("Digite a data de saida:");
    data_saida.criar();

    // if (!data_saida.totalDias() || !data_saida.totalSegundos()) {
    if (!data_saida.totalDias()) {
        printf("Data de saida invalida!\nCriacao de estadia cancelada.\n");
        return;
    }

    /*
    if (data_saida.horas > 12) {
        printf("As diarias terminam ate 12:00!\nCriacao de estadia cancelada.\n");
        return;
    }
    */

    if (data_saida.totalDias() <= data_entrada.totalDias()) {
        printf("A data de saida deve ser posterior a data de entrada!\nCriacao de estadia cancelada.\n");
        return;
    }

    printf("Digite o numero de pessoas: ");
    scanf("%i", &hospedes);

    if (!hospedes) {
        printf("Numero de hospedes invalido!\nCriacao de estadia cancelada.\n");
        return;
    }

    int diariasOk = setDiarias();

    if (!diariasOk) {
        printf("Diarias invalidas!\nCriacao de estadia cancelada.\n");
        return;
    }

    int quartoOk = defineQuarto();

    if (quartoOk) {
        printf("Reservando quarto de numero %i para cliente de codigo %i!\n", num_quarto, codigo_cliente);
    } else {
        printf("Nenhum quarto disponivel para %i pessoas no momento!\nCriacao de estadia cancelada.\n", hospedes);
        return;
    }

    fstream estadiasFile("estadias.dat", ios::in | ios::out | ios::app);
    estadiasFile.write((char*)this, sizeof(Estadia));
    estadiasFile.flush();
    estadiasFile.close();

    printf("Estadia criada com sucesso!\n");
};

void Estadia::imprimir() {
    setlocale(LC_ALL, "Portuguese");

    printf("Codigo: %i\n", codigo);
    printf("Codigo do cliente: %i\n", codigo_cliente);
    printf("Numero do quarto: %i\n", num_quarto);
    // printf("Data de entrada: %02i/%02i/%04i %02i:%02i:%02i\n", data_entrada.dia, data_entrada.mes, data_entrada.ano, data_entrada.horas, data_entrada.minutos, data_entrada.segundos);
    printf("Data de entrada: %02i/%02i/%04i\n", data_entrada.dia, data_entrada.mes, data_entrada.ano);
    // printf("Data de saida: %02i/%02i/%04i %02i:%02i:%02i\n", data_saida.dia, data_saida.mes, data_saida.ano, data_saida.horas, data_saida.minutos, data_saida.segundos);
    printf("Data de saida: %02i/%02i/%04i\n", data_saida.dia, data_saida.mes, data_saida.ano);
    printf("Numero de pessoas: %i\n", hospedes);
    printf("Diarias: %i\n", diarias);
    printf("Status: %i\n", status);
    printf("\n");
};


int Estadia::getCodigo() {
    return codigo;
};

int Estadia::getCodigoCliente() {
    return codigo_cliente;
};


int Estadia::getNumQuarto() {
    return num_quarto;
};

int Estadia::defineQuarto() {
    Quarto quarto;
    Estadia estadia;
    fstream quartosFile("quartos.dat", ios::in | ios::out);
    fstream estadiasFile("estadias.dat", ios::in | ios::out);

    while (quartosFile.read((char*)&quarto, sizeof(quarto))) {
        if (quarto.getCapacidade() == hospedes) {
            bool quartoDisponivel = true;

            estadiasFile.clear();
            estadiasFile.seekg(0, ios::beg);

            while(estadiasFile.read((char*)&estadia, sizeof(estadia))) {
                if (estadia.num_quarto == quarto.getNumero()) {
                    // if (!estadia.data_saida.totalDias() && estadia.status == 1) {
                    if (estadia.status == 1) {
                        quartoDisponivel = false;
                        break;
                    }

                    if (((data_entrada.totalDias() >= estadia.data_entrada.totalDias() && data_entrada.totalDias() < estadia.data_saida.totalDias())
                        || (data_saida.totalDias() > estadia.data_entrada.totalDias() && data_saida.totalDias() <= estadia.data_saida.totalDias()))) {
                        quartoDisponivel = false;
                        break;
                    }
                }
            }

            if (quartoDisponivel) {
                num_quarto = quarto.getNumero();
                quartosFile.close();
                estadiasFile.close();
                return 1;
            }
        }
    }

    quartosFile.close();
    estadiasFile.close();
    return 0;
};


int Estadia::getDiarias() {
    return diarias;
};

int Estadia::setDiarias() {
    diarias = data_saida.totalDias() - data_entrada.totalDias();
    if (diarias < 1) {
        return 0;
    } else {
        return 1;
    }
};


int Estadia::getStatus() {
    return status;
};

void Estadia::setStatus(int s) {
    status = s;
};


// Estadia functions

void listarEstadias() {
    setlocale(LC_ALL, "Portuguese");

    Estadia estadia;
    fstream estadiasFile("estadias.dat", ios::in);

    if (!estadiasFile) {
        printf("Não foi possível abrir o arquivo!\n\n");
        return;
    }

    while (estadiasFile.read((char*)&estadia, sizeof(estadia))) {
        estadia.imprimir();
    }

    estadiasFile.close();
};

int darBaixaEstadia(int id) {
    setlocale(LC_ALL, "Portuguese");

    Estadia estadiaTemp;
    Estadia estadia;
    fstream estadiasFile("estadias.dat", ios::in | ios::out);
    int pos = 0;

    // Aqui fazemos a leitura do arquivo, procurando pelo número do quarto ou código da estadia
    estadiasFile.seekg(0, ios::beg); // Posiciona no início do arquivo
    while (estadiasFile.read((char*)&estadiaTemp, sizeof(estadiaTemp))) {
        if (estadiaTemp.getCodigo() == id || estadiaTemp.getNumQuarto() == id) {
            estadia = estadiaTemp;
            break;
        } else {
            pos++;
        }
    }

    if (!estadia.getCodigo()) {
        printf("Estadia nao encontrada!\n");
        return 0;
    }

    // Cálculo do valor total a pagar
    float valor_diaria = getQuartoCusto(estadia.getNumQuarto());
    float valor_total = (float)valor_diaria * estadia.getDiarias();

    // Aqui você marca a estadia como finalizada
    estadia.setStatus(0);

    int estadiaFilePos = pos * sizeof(Estadia);
    int fileSize = estadiasFile.tellg();

    estadiasFile.seekg(0, ios::beg);
    if (estadiaFilePos >= fileSize) {
        std::cout << "Posicao fora do arquivo.\n";
        estadiasFile.close();
        return 0;
    }

    estadiasFile.seekp(estadiaFilePos, ios::beg); // Posiciona logo antes da estadia a ser editada
    if (estadiasFile.fail()) {
        printf("Erro ao posicionar no arquivo.\n");
        estadiasFile.close();
        return 0;
    }

    estadiasFile.write((char*)&estadia, sizeof(Estadia));

    if (estadiasFile.fail()) {
        printf("Erro ao escrever no arquivo.\n");
        estadiasFile.close();
        return 0;
    }

    estadiasFile.flush();
    estadiasFile.close();

    // Exibindo o valor total a ser pago pelo cliente
    printf("Valor total a ser pago: R$%.2f", valor_total);
    return 1;
};