// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS__HPP
#define GERADOR_PISTAS__HPP
#include "../pista/Pista.hpp"
#include "../pista/PistaSumidoura.hpp"
#include "../util/ListaDupla.cpp"

class GeradorPistas {
 private:
    Relogio *relogio;
    GeradorSemaforo *geradorSemaforo;
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
    
    
    Pista* geraPistaO1Oeste(Relogio* relogio);
    Pista* geraPistaL1Leste(Relogio* relogio);
    Pista* geraPistaS1Sul(Relogio* relogio);
    Pista* geraPistaS2Sul(Relogio* relogio);
    Pista* geraPistaN1Norte(Relogio* relogio);
    Pista* geraPistaN2Norte(Relogio* relogio);
    
    Pista* geraPistaC1Oeste(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaC1Leste(Relogio* relogio, Semaforo* semaforo);
    
    Pista* geraPistaO1Leste(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaL1Oeste(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaN1Sul(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaN2Sul(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaS1Norte(Relogio* relogio, Semaforo* semaforo);
    Pista* geraPistaS2Norte(Relogio* relogio, Semaforo* semaforo);
    
    
 public:
    GeradorPistas(Relogio *relogio, GeradorSemaforo *geradorSemaforo);
    ListaDupla<Pista*> geraPistas();
    
};

#endif