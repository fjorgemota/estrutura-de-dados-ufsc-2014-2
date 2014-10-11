// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_SEMAFORO_HPP
#define GERADOR_SEMAFORO_HPP
#include "../semaforo/Semaforo.cpp"
#include "../util/ListaDupla.cpp"
#include "../relogio/Relogio.cpp"

/*
 * Classe que gerará os semáforos que estarão presentes em dois cruzamentos
 */
class GeradorSemaforo {
 private:
    Relogio *relogio;  //!< O relógio para sincronizar os semáforos
    Semaforo* semO1leste;
    Semaforo* semN1sul;
    Semaforo* semN2sul;
    Semaforo* semS1norte;
    Semaforo* semS2norte;
    Semaforo* semC1oeste;
    Semaforo* semC1leste;
    Semaforo* semL1oeste;

 public:
    /*
     * Constrói um gerador de semáforos
     *
     * @param relogio O relógio usado para sincronizar os semáforos
     */
    explicit GeradorSemaforo(Relogio *relogio);
    
    /*
     * Destrói o gerador de semáforos
     */
    ~GeradorSemaforo();

    /*
     * Método que irá atualizar os intervalos de alternância dos semáforos
     * dos primeiro e segundo cruzamentos, respectivamente
     *
     * @param intervalo O intervalo de alternância entre os estados dos semáforos (em segundos)
     */
    void agendaSemaforosS1(int intervalo);
    void agendaSemaforosS2(int intervalo);

    /*
     * Métodos que retornam os semáforos das respectivas pistas
     */
    Semaforo* pegaSemO1leste();
    Semaforo* pegaSemN1sul();
    Semaforo* pegaSemN2sul();
    Semaforo* pegaSemS1norte();
    Semaforo* pegaSemS2norte();
    Semaforo* pegaSemC1oeste();
    Semaforo* pegaSemC1leste();
    Semaforo* pegaSemL1oeste();

    /*
     * Listas duplamente encadeadas com os semáforos dos primeiro e segundo cruzamentos
     */
    ListaDupla<Semaforo*>* pegaSemaforosS1();
    ListaDupla<Semaforo*>* pegaSemaforosS2();
};

#endif /* GERADOR_SEMAFORO_HPP */
