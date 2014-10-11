// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS__HPP
#define GERADOR_PISTAS__HPP
#include "../pista/Pista.hpp"
#include "../pista/PistaSumidoura.hpp"
#include "../util/ListaDupla.cpp"
#include "../programa/GeradorSemaforo.cpp"

/*
 * Classe que gerará as pistas de dois cruzamentos, associando-os aos seus respectivos semáforos
 */
class GeradorPistas {
 private:
    Relogio *relogio;  //!< Relógio usado para sincronizar os cruzamentos
    GeradorSemaforo *geradorSemaforo;  //!< Os semáforos que
                    //!< serão adicionados às respectivas pistas

    Pista* pistaO1Oeste;
    Pista* pistaL1Leste;
    Pista* pistaS1Sul;
    Pista* pistaS2Sul;
    Pista* pistaN1Norte;
    Pista* pistaN2Norte;
    Pista* pistaO1Leste;
    Pista* pistaN1Sul;
    Pista* pistaN2Sul;
    Pista* pistaS1Norte;
    Pista* pistaS2Norte;
    Pista* pistaL1Oeste;
    Pista* pistaC1Oeste;
    Pista* pistaC1Leste;

    Pista* geraPistaO1Oeste();
    Pista* geraPistaL1Leste();
    Pista* geraPistaS1Sul();
    Pista* geraPistaS2Sul();
    Pista* geraPistaN1Norte();
    Pista* geraPistaN2Norte();

    Pista* geraPistaC1Oeste();
    Pista* geraPistaC1Leste();

    Pista* geraPistaO1Leste();
    Pista* geraPistaL1Oeste();
    Pista* geraPistaN1Sul();
    Pista* geraPistaN2Sul();
    Pista* geraPistaS1Norte();
    Pista* geraPistaS2Norte();


 public:
    /*
     * Constrói um gerador de pistas
     *
     * @param relogio O relógio que manterá a sincronização das pistas
     * @param geradorSemaforo Os semáforos que serão associados às respectivas pistas
     */
    GeradorPistas(Relogio *relogio, GeradorSemaforo *geradorSemaforo);
    
    /*
     * Destrói o gerador de pistas
     */
    ~GeradorPistas();

    /*
     * Método que irá chamar os construtores de todas as pistas dos dois cruzamentos
     */
    void geraPistas();
};
#include "GeradorPistas.cpp"
#endif
