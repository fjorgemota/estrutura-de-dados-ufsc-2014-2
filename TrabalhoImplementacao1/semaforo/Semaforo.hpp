// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

#include <string>
#include "../util/ListaEnc.cpp"
#include "../relogio/Relogio.cpp"

#define SEMAFORO_ABERTO true
#define SEMAFORO_FECHADO false

using std::string;

/*
 * Semáforo é o sinal de transito que manterá a ordem na pista, informando aos carros
 * quando podem ou não passar para a próxima pista
 */
class Semaforo {
 private:
    string descricao;  //!< Descrição, informando o que
                      //!< cada semáforo está fazendo no momento
    Relogio *relogio;  //!< Relógio usado para sincronizar o semáforo
    bool aberto;  //!< Variável booleana indicando que
                 //!< está aberto (true) ou fechado (false)
    int contador;  //!< Contador que indica quantos
                //!< carros passaram pelo semáforo

 public:
    /*
     * Constrói um semáforo
     *
     * @param descricao A descrição que será acompanhada ao semáforo
     * @param relogio Relógio usado para sincronizar o semáforo
     */
    Semaforo(string descricao, Relogio *relogio);

    /*
     * Retorna a quantidade de carros que passou pelo semáforo
     */
    int pegaContador();

    /*
     * Retorna a situação atual do semáforo, conforme a sua descrição
     */
    string pegaDescricao();

    /*
     * Acrescenta mais um no contador de veículos
     */
    void acrescentaContador();

    /*
     * Verifica se o semáforo está aberto 
     */
    bool estaAberto();

    /* 
     * Verifica se o semáforo está fechado
     */
    bool estaFechado();

    /*
     * Muda o sinal do semáforo para aberto (verde/true)
     */
    void abre();

    /*
     * Muda o sinal do semáforo para fechado (vermelho/false)
     */
    void fecha();
};

#endif /* SEMAFORO_HPP */
