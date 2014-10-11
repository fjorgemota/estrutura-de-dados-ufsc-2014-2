// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef RELOGIO_HPP
#define RELOGIO_HPP
#include "../util/ListaDupla.cpp"
#include "Evento.cpp"
#include "Futuro.cpp"

/*
 * Classe relógio que sincronizará e marcará os tempos ocorridos durante
 * a simulação do tráfego, onde os eventos são armazanados em listas duplamente
 * encadeadas
 */
class Relogio {
 private:
    ListaDupla<Evento*> *historico;  //!< Lista com o histórico de eventos
    ListaDupla<Futuro*> *futuros;  //!< Lista com os eventos futuros,
                                  //!< que ainda serão realizados
    int segundoAtual;  //!< Segundo atual do relógio
    bool paraExecucao;  //!< Para a execução do relógio,
                    //!<  ou seja, as sincronizações e salvamento
                    //!< de eventos são interrompidos
 public:
    /*
     * Constrói um relógio.
     */
    Relogio();

    /*
     * Destrói o relógio.
     */
    ~Relogio();

    /*
     * Retorna o segundo atual do relgio
     */
    int pegaSegundoAtual();

    /*
     * Conta quantos eventos de um determinado tipo estão presentes no histórico
     *
     * @param tipo O tipo de evento que será contabilizado
     */
    int contaEventosDoTipo(int tipo);

    /*
     * Adiciona um evento à lista de histórico
     *
     * @param ev Evento que será adicionado à lista
     */
    void registra(Evento *ev);

    /*
     * Adiciona um evento futuro à lista de eventos futuros
     *
     * @param fut O evento futuro que será registrado na lista
     */
    void agenda(Futuro *fut);

    /*
     * Adiciona um evento logo após a passagem de um tempo determinado
     *
     * @param fut O evento futuro a ser adicionado na lista
     * @param horaAtual O intervalo até o evento futuro acontecer
     */
    void agendaDaquiA(Futuro *fut, int horaAtual);

    /*
     * Para o relógio, isto é, sua sincronização e adição de eventos são interrompidos
     */
    void parar();

    /*
     * Apresenta o que está presente na lista de eventos futuros
     */
    void listaFuturos();

    /*
     * Apresenta o que está na lista de histórico
     */
    void listaHistorico();

    /*
     * Método onde o relógio realiza as suas funções, ou seja, as sincronizações e a realização dos eventos futuros
     * e os que estão na lista de histórico, assim como os resultados (tarefas feitas)
     */
    void executar();
};

#endif /* RELOGIO_HPP */
