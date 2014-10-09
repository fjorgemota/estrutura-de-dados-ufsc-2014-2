// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PISTA_HPP
#define PISTA_HPP
#include "../util/FilaEnc.cpp"
#include "../carro/Carro.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.hpp"

/*
 * Classe pista, uma herança da classe Fila Encadeada, onde os carros irão percorrer seguindo a
 * velocidade nela apresentada num tamanho máximo. Cada pista possui uma lista duplamente encadeada com as suas respectivas
 * saídas
 */
class Pista: private FilaEnc<Carro*> {
 protected:
    Semaforo *semaforo;  //!< Semaforo conectado à saída da pista
    int tamanhoMaximo;  //!< O tamanho maximo da pista, definida em metros
    int tamanhoDisponivel;   //!< O tamanho que esta disponivel, ou seja,
                             // definira se ela suportara mais carros
    ListaDupla<Pista*> *pistasSaida;
    Relogio *relogio;  //!< Relogio a ser usado pela pista para sincronização
    int velocidade;  //!< A velocidade limite que a pista possui,
                     // os carros andarao nesta velocidade (em km/h)

    /*
     * Método que adiciona um novo carro à pista de acordo com o tempo, calculado a partir da velocidade e tamanho
     * da pista
     */
    virtual void agendaNovoCarro();

 public:
    /*
     * Constrói uma pista
     *
     * @param relogio O relógio para sincronização das pistas 
     * @param semaforo O semáforo que será conectado à saída da pista 
     * @param tamanhoMaximo O tamanho total da pista, em metros
     * @param velocidade A velocidade em que os carros percorerrão ao andar na pista
     * @param pistasSaida Uma lista com as pistas de saída de cada uma
     */
    Pista(Relogio *relogio, Semaforo *semaforo, int tamanhoMaximo,
        int velocidade, ListaDupla<Pista*> *pistasSaida);
    
    /*
     * Destrói a pista
     */
    ~Pista();
        
    /*
     * Retorna o tamanho total da pista
     */
    int pegaTamanhoMaximo();

    /*
     * Retorna a valocidade permitida na pista
     */
    int pegaVelocidade();

    /*
     * Adiciona um carro à pista, se estiver cheia, ela será bloqueada e nenhum novo carro poderá entrar
     *
     * @param carro O carro a ser adicionado na pista
     */
    bool adiciona(Carro* carro);

    /*
     * Retira o carro que está no fim da pista, ou seja, que a percorreu toda
     */
    Carro* sairDaPista();

    /*
     * Retorna o carro que está no começo da pista, ou seja, que acabou de entrar
     */
    Carro* ultimoCarro();

    /*
     * Escolhe aleatoriamente uma das três pistas de saída
     */
    Pista* sorteiaPista();

    /*
     * Verifica se a pista está lotada
     */
    bool estaCheia(Carro* carro);
};

#endif /* PISTA_HPP */
