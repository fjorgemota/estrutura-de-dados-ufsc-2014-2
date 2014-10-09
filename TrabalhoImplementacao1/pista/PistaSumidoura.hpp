// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_SUMIDOURA_HPP
#define PISTA_SUMIDOURA_HPP
#include "Pista.cpp"

/*
 * Pista sumidoura é o percurso final dos veículos de viagem, como qualquer pista, tem um
 * tamanho máximo e um limite de velocidade.
 */
class PistaSumidoura: public Pista {
 protected:
    /*
     * Método que informa em quanto tempo um novo carro deverá ser adicionado, de acordo
     * com o seu tamanho máximo e velocidade
     */
    virtual void agendaNovoCarro();

 public:
    /*
     * Constrói uma pista sumidoura
     *
     * @param relogio O relógio para sincronizar as pistas
     * @param tamanho O tamanho total da pista sumidoura
     * @param velocidade A velocidade máxima permitida pela pista
     */
    PistaSumidoura(Relogio *relogio, int tamanho, int velocidade);
};

#endif /* PISTA_SUMIDOURA_HPP */
