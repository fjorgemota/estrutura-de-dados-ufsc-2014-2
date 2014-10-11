// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_FIM_HPP
#define FUTURO_FIM_HPP

#include "../relogio/Futuro.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"

/*
 * Classe que realiza as estatísticas finais do programa, dentre eles, as informações
 * do semáforo, do carro e do sistema
 */
class FuturoFim : public Futuro {
 private:
    Relogio *relogio;  //!< O relógio para sincronização
    ListaDupla<Semaforo*> *semaforosS1, *semaforosS2;
        //!< As listas duplamente encadeadas que contém
        //!< os semáforos dos cruzamentos S1 e S2
    bool mostraEventos; //!< Flag que indica se é para 
        //!< mostrar eventos no final da execução do programa.

 public:
    /*
     * Construtor do evento responsável por terminar o programa 
     * e mostrar estatísticas relacionadas à sua execução
     *
     * @param relogio O relógio para a sincronização do evento
     * @param semaforosS1 A lista de semáforos do cruzamento S1
     * @param semaforosS2 A lista de semáforos do cruzamento S2
     * @param mostraEventos Indica se é para mostrar eventos no fim da execução
     * @param pararEm Tempo no qual o objeto deverá ser executado
     */
    FuturoFim(Relogio *relogio, ListaDupla<Semaforo*> *semaforosS1,
        ListaDupla<Semaforo*> *semaforosS2, bool mostraEventos,
        int pararEm);

    /*
     * Método que terminará o programa e mostrará suas estatísticas finais
     */
    virtual void executar();
};

#endif /* FUTURO_FIM_HPP */
