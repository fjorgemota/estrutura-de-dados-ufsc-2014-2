// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_FONTE_HPP
#define PISTA_FONTE_HPP
#include "Pista.cpp"

/*
 * Pista Fonte é o primeiro ponto onde os carros passam durante a viagem, como uma pista qualquer,
 * possui um limite de velocidade e um tamanho máximo.
 */
class PistaFonte: public Pista {
 public:
    /*
     * Constrói uma pista fonte
     *
     * @param relogio O relogio para a sincronização da pista fonte
     * @param semaforo O semaforo que será conectado ao final da pista, sinalizando os carros
     * @param tamanho O tamanho da pista
     * @param velocidade A velocidade máxima permitida na pista
     * @param pistasSaida A lista das respectivas pistas de saída
     */
    PistaFonte(Relogio *relogio, Semaforo *semaforo, int tamanho,
        int velocidade, ListaDupla<Pista*> *pistasSaida);
};

#endif /* PISTA_FONTE_HPP */
