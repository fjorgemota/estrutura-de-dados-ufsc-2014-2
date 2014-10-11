// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_SEMAFORO_HPP
#define FUTURO_PERIODICO_SEMAFORO_HPP
#include "../relogio/FuturoPeriodico.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"

/*
 * Classe que representa os eventos referente aos semáforos,
 * isto é, as sinalizações e quais carros passaram pelo sinalizador
 */
class FuturoPeriodicoSemaforo : public FuturoPeriodico {
 private:
    ListaDupla<Semaforo*> *semaforos;  //!< Lista de todos os
                                    //!< semáforos do sistema
    int semaforoEscolhido;  //!< Verifica a posição do último semáforo da lista
    bool fechaTodos;  //!< Fecha todos os semáforos
 public:
    /*
     * Constrói o evento para a administração dos semáforos de um cruzamento
     *
     * @param semaforo A lista duplamente encadeada com todos os semáforos
     * @param intervalo O intervalo de alternância dos semáforos
     */
    FuturoPeriodicoSemaforo(ListaDupla<Semaforo*> *semaforo, int intervalo);
    
    /*
     * Destrói o evento que administra os semáforos de um cruzamento
     */
    ~FuturoPeriodicoSemaforo();

    /*
     * Método que executa/administra a sincronização dos semáforos de um cruzamento
     */
    virtual void executar();
};

#endif /* FUTURO_PERIODICO_SEMAFORO_HPP */
