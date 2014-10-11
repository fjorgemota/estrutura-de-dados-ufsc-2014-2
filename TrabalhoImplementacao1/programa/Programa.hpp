// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include "GeradorPistas.cpp"
#include "GeradorSemaforo.cpp"
#include "../pista/Pista.cpp"
#include "../util/ListaDupla.cpp"

/*
 * Classe que irá dar funcionamento ao Trabalho de Implementação 1
 */
class Programa {
 private:
    Relogio *relogio;  //!< Relógio usado para sincronizar as pistas e semáforos
    GeradorSemaforo* geradorSemaforos;  //!< Gerador de semáforos
    GeradorPistas* geradorPistas;  //!< Gerador de pistas

    /*
     * Método que pergunta ao usuário qual será o tempo (em segundos)
     * que o programa permanecerá em funcionamento
     */
    void perguntaTempoDuracao();

    /*
     * Método que pergunta ao usuário qual será o intervalo (em segundos) de alternância
     * dos semáforos
     */
    void perguntaIntervaloSemaforo();
    
    /*
     * Método que pergunta ao usuário se ele deseja exibir a lista de eventos que
     * ocorreram no sistema após o fim do programa
     */
    bool perguntaMostraEventos();

 public:
    /*
     * Constrói o programa, onde o gerador de pista, o gerador de semáforos e o relógio
     * são incializados
     */
    explicit Programa(Relogio *relogio);
    
    /*
     * Destrói o programa, apagando o gerador de pista e o gerador de semáforos.
     */
    ~Programa();

    /*
     * Método onde o programa é realizado.
     */
    void executar();
};

#endif /* PROGRAMA_HPP */
