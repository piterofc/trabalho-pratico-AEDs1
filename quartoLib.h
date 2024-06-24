#ifndef QUARTOLIB_H_INCLUDED
#define QUARTOLIB_H_INCLUDED

/**
 * Menu de quartos.
 */
void menuQuartos();

/**
 * Classe Quarto
 * Representa um quarto de hotel, incluindo informações como número, capacidade e custo da diária.
 */
class Quarto {
    private:
        /** Número único do quarto. */
        int numero;
        /** Capacidade máxima de hóspedes no quarto. */
        int capacidade;
        /** Custo da diária do quarto. */
        float custo_diaria;
    public:
        /** Método para criar um quarto. */
        void criar();
        /** Método para imprimir as informações do quarto. */
        void imprimir();
        /** Método para obter o número do quarto. */
        int getNumero();
        /** Método para obter a capacidade do quarto. */
        int getCapacidade();
        /** Método para obter o custo da diária do quarto. */
        float getCustoDiaria();
};

/**
 * Verifica se um quarto com o número informado já existe.
 * @param num Número do quarto a ser verificado.
 * @return 1 se o quarto existe, 0 caso contrário
 */
int verificarQuarto(int num);

/**
 * Obtém o custo da diária de um quarto com base no número informado.
 * @param num Número do quarto
 * @return Custo da diária do quarto
 */
float getQuartoCusto(int num);

/**
 * Lista todos os quartos cadastrados.
 */
void listarQuartos();

#endif // QUARTOLIB_H_INCLUDED