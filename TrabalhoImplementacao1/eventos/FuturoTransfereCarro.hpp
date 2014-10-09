// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_TRANSFERE_CARRO_HPP
#define FUTURO_TRANSFERE_CARRO_HPP
#include "../pista/Pista.cpp"
#include "../relogio/Futuro.cpp"
#include "../semaforo/Semaforo.cpp"

/*
 * Classe que leva um carro de uma pista para outra,
 * conforme as saídas das rodovias especificadas na
 * classe Pista
 */
class FuturoTransfereCarro : public Futuro {
 private:
    Pista* pista;  //!< A pista que terá o primeiro carro da
                  //!< fila passado para a próxima
    Semaforo* semaforo;  //!< Semáforo da pista que o carro sairá
    Relogio* relogio;  //!< O relógio para sincronização
    bool tentativa; //!< Indica se é uma nova tentativa ou não
    
    /*
     * Constrói um evento para uma nova tentativa de transferência do carro a outra pista
     *
     * @param futuro O objeto FuturoTransfereCarro anterior
     */
    FuturoTransfereCarro(FuturoTransfereCarro *futuro);
 public:
    /*
     * Constrói um evento para a transferência do carro a outra pista
     *
     * @param pista A pista que o carro sairá
     * @param semaforo O semáforo da pista em que o carro sairá
     * @param relogio O relógio para sincronizar o tempo
     */
    FuturoTransfereCarro(Pista* pista, Semaforo* semaforo, Relogio *relogio);

    /*
     * Método que realiza a transferência do carro para a outra pista
     */
    virtual void executar();
};
#include "FuturoTransfereCarro.cpp"
#endif /* FUTURO_TRANSFERE_CARRO_HPP */
