// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.hpp"

class Pista: private FilaEnc<Carro*> {
 private:
    Semaforo *semaforo;  //!< Semaforo conectado à saída da pista
    int tamanhoMaximo;  //!< O tamanho maximo da pista, definida em metros
    int velocidade;  //!< A velocidade limite que a pista possui,
                     // os carros andarao nesta velocidade
    int tamanhoDisponivel;   //!< O tamanho que esta disponivel, ou seja,
                             // definira se ela suportara mais carros
    ListaDupla<Pista*> pistasSaida;

 protected:
    Relogio *relogio;  //!< Relogio a ser usado pela pista para sincronização
    virtual void agendaNovoCarro();

 public:
    Pista(Relogio *relogio, Semaforo *semaforo, int tamanhoMaximo,
        int velocidade, ListaDupla<Pista> pistasSaida);
    int pegaTamanhoMaximo();
    int pegaVelocidade();
    bool adiciona(Carro* carro);
    Carro sairDaPista();
    Pista* sorteiaPista();
    bool estaCheia(Carro* carro);
};

#endif /* PISTA_HPP */
