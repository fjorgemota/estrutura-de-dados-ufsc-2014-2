// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PISTA_SUMIDOURA_HPP
#define FUTURO_PISTA_SUMIDOURA_HPP
#include "../relogio/Futuro.cpp"
#include "../pista/PistaSumidoura.cpp"

/*
 * Evento que leva o carro ao percurso de uma pista 
 * sumidoura, ou seja, o fim do trajeto apresentado pela
 * simulação
 */
class FuturoPistaSumidoura : public Futuro {
 private:
    PistaSumidoura *pista;  //!< A pista em que o carro
                        //!< percorerrá o trajeto final da viagem

 public:
    /*
     * Constrói o evento para o trajeto do carro na pista sumidoura
     *
     * @param pista A pista sumidoura onde o carro irá
     */
    explicit FuturoPistaSumidoura(PistaSumidoura* pista);

    /*
     * Retira o carro da pista assim que ele chega no final da pista sumidoura
     */
    virtual void executar();
};

#include "FuturoPistaSumidoura.cpp"
#endif /* FUTURO_PISTA_SUMIDOURA_HPP */
