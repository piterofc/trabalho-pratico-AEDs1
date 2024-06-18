#ifndef QUARTOLIB_H_INCLUDED
#define QUARTOLIB_H_INCLUDED

class Quarto {
    private:
        int numero;
        int quantidade_hospedes;
        float custo_diaria;
        int status = 0;
    public:
        void adicionarQuarto();
        void imprimeQuarto();

        int getNumero();
        int getQuantidadeHospedes();
        float getCustoDiaria();
        int getStatus();
};

int verificarQuarto(int num);
void listarQuartos();

#endif // QUARTOLIB_H_INCLUDED