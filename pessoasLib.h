#ifndef PESSOASLIB_H_INCLUDED
#define PESSOASLIB_H_INCLUDED

/**
 * Menu de clientes.
 */
void menuClientes();

/**
 * Menu de funcionários.
 */
void menuFuncionarios();



/**
 * Classe Cliente
 * Representa um cliente com informações básicas como código, nome, endereço e telefone.
 */
class Cliente {
    private:
    /** Identificador único para o cliente */
    int codigo;
    /** Endereço do cliente, armazenado como array de caracteres */
    char endereco[100];
    /** Telefone do cliente, armazenado como array de caracteres */
    char telefone[15];
    public:
    /** Nome do cliente, armazenado como array de caracteres */
    char nome[50];
    /** Método para criar o cliente */
    void criar();
    /** Método para imprimir as informações do cliente */
    void imprimir();
    /** Método para obter o código do cliente */
    int getCodigo();
    /** Método para obter a fidelidade do cliente */
    int getFidelidade();
};

/**
 * Verifica se um cliente com o código informado já existe.
 * @param codigo Código do cliente a ser verificado.
 * @return 1 se o cliente existe, 0 caso contrário
 */
int verificarCliente(int codigo);

/**
 * Lista todos os clientes cadastrados.
 */
void listarClientes();

/**
 * Calcula os pontos de fidelidade de um cliente com base no código informado.
 * @param codigo Código do cliente
 */
void calcularPontosFidelidade(int codigo);

/**
 * Lista todas as estadias de um cliente com base no código informado.
 * @param codigo Código do cliente
 */
void listarEstadiasCliente(int codigo);



/**
 * Classe Funcionario
 * Representa um funcionário com informações básicas como código, nome, telefone, cargo e salário.
 */
class Funcionario {
    private:
    /** Identificador único para o funcionário */
    int codigo;
    /** Telefone do funcionário, armazenado como array de caracteres */
    char telefone[15];
    /** Cargo do funcionário, armazenado como array de caracteres */
    char cargo[50];
    /** Salário do funcionário */
    float salario;
    public:
    /** Nome do funcionário, armazenado como array de caracteres */
    char nome[50];
    /** Método para criar o funcionário */
    void criar();
    /** Método para imprimir as informações do funcionário */
    void imprimir();
    /** Método para obter o código do funcionário */
    int getCodigo();
};

/**
 * Verifica se um funcionário com o código informado já existe.
 * @param codigo Código do funcionário a ser verificado.
 * @return 1 se o funcionário existe, 0 caso contrário
 */
int verificarFuncionario(int codigo);

/**
 * Lista todos os funcionários cadastrados.
 */
void listarFuncionarios();

#endif // PESSOASLIB_H_INCLUDED