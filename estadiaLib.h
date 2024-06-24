#ifndef ESTADIALIB_H_INCLUDED
#define ESTADIALIB_H_INCLUDED

/**
 * Menu de estadias.
 */
void menuEstadias();

/**
 * Classe Data
 * Representa uma data e hora específica, incluindo ano, mês, dia, horas, minutos e segundos.
 */
class Data {
    public:
    /** Dia do mês */
    int dia;
    /** Mês do ano */
    int mes;
    /** Ano */
    int ano;
    /** Horas do dia */
    int horas;
    /** Minutos da hora */
    int minutos;
    /** Segundos do minuto */
    int segundos;
    /**
     * Método criar - inicializa a data e hora com valores específicos fornecidos pelo usuário ou sistema.
     */
    void criar();
    /**
     * Método totalDias - calcula o total de dias desde a data 0/0/0 até a data atual.
     * @return Total de dias desde a data 0/0/0 até a data atual
     */
    int totalDias();
    /**
     * Método totalSegundos - calcula o total de segundos desde a hora 00:00:00 até a hora atual.
     * @return Total de segundos.
     */
    int totalSegundos();
};


/**
 * Classe Estadia
 * Representa uma estadia de um cliente em um quarto de hotel, incluindo informações como código, cliente, número de hóspedes, número do quarto, número de diárias, data de entrada e data de saída.
 */
class Estadia {
    private:
    /** Código único da estadia */
    int codigo;
    /** Código do cliente */
    int codigo_cliente;
    /** Número de hóspedes */
    int hospedes;
    /** Número do quarto */
    int num_quarto;
    /** Número de diárias */
    int diarias;
    /** Status da estadia (1 - ativa, 0 - finalizada) */
    int status = 1;
    /** Data de entrada */
    Data data_entrada;
    /** Data de saída */
    Data data_saida;
    public:
    /**
     * Método criar
     * Inicializa a estadia com valores específicos fornecidos pelo usuário ou sistema.
     */
    void criar();
    /**
     * Método setDiarias - define o número de diárias da estadia com base nas datas de entrada e saída.
     * @return Número de diárias
     */
    int setDiarias();
    /**
     * Método defineQuarto - define o número do quarto da estadia com base no número de hóspedes.
     * @return Número do quarto
     */
    int defineQuarto();
    /**
     * Método getStatus
     * @return Status da estadia (1 - ativa, 0 - finalizada)
     */
    int getStatus();
    /**
     * Método setStatus - define o status da estadia
     * @param s Status da estadia (1 - ativa, 0 - finalizada)
     */
    void setStatus(int s);
    /**
     * Método getCodigo
     * @return Código da estadia
     */
    int getCodigo();
    /**
     * Método getCodigoCliente
     * @return Código do cliente
     */
    int getCodigoCliente();
    /**
     * Método getNumQuarto
     * @return Número do quarto
     */
    int getNumQuarto();
    /**
     * Método getDiarias
     * @return Número de diárias
     */
    int getDiarias();
    /**
     * Método imprimir - imprime as informações da estadia.
     */
    void imprimir();
};

/**
 * Dar baixa em uma estadia.
 */
int darBaixaEstadia(int id);

/**
 * Lista todas as estadias cadastradas.
 */
void listarEstadias();

#endif // ESTADIALIB_H_INCLUDED