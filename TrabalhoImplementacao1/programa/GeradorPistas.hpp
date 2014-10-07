// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS__HPP
#define GERADOR_PISTAS__HPP
#include "../pista/Pista.hpp"
#include "../pista/PistaSumidoura.hpp"

class GeradorPistas {
 private:
    PistaSumidoura geraViaO1Oeste(Relogio* relogio);
    PistaSumidoura geraViaL1Leste(Relogio* relogio);
    PistaSumidoura geraViaS1Sul(Relogio* relogio);
    PistaSumidoura geraViaS2Sul(Relogio* relogio);
    PistaSumidoura geraViaN1Norte(Relogio* relogio);
    PistaSumidoura geraViaN2Norte(Relogio* relogio);
    
    Pista geraViaC1Oeste(Relogio* relogio, Semaforo* semaforo);
    Pista geraViaC1Leste(Relogio* relogio, Semaforo* semaforo);
    
    PistaFonte geraViaO1Leste(Relogio* relogio, Semaforo* semaforo);
    PistaFonte geraViaL1Oeste(Relogio* relogio, Semaforo* semaforo);
    PistaFonte geraViaN1Sul(Relogio* relogio, Semaforo* semaforo);
    PistaFonte geraViaN2Sul(Relogio* relogio, Semaforo* semaforo);
    PistaFonte geraViaS1Norte(Relogio* relogio, Semaforo* semaforo);
    PistaFonte geraViaS2Norte(Relogio* relogio, Semaforo* semaforo);
    
    
 public:
    ListaDupla geraPista();
    
};

#endif