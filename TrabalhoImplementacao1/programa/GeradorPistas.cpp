// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS_CPP
#define GERADOR_PISTAS__CPP

#include "../pista/Pista.cpp"
#include "../pista/PistaSumidoura.cpp"
#include "../pista/PistaFonte.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/GeradorProbabilidades.cpp"

PistaSumidoura GeradorPistas::geraViaO1Oeste(Relogio* relogio) {
    PistaSumidoura* viaO1Oeste = PistaSumidoura(relogio, 2000, 80);
    return viaO1Oeste;
}

PistaSumidoura GeradorPistas::geraViaL1Leste(Relogio* relogio) {
    PistaSumidoura* viaL1Leste = PistaSumidoura(relogio, 400, 30);
    return viaL1Leste;
}

PistaSumidoura GeradorPistas::geraViaS1Sul(Relogio* relogio) {
    PistaSumidoura* viaS1Sul = PistaSumidoura(relogio, 500, 60);
    return viaS1Sul;
}

PistaSumidoura GeradorPistas::geraViaS2Sul(Relogio* relogio) {
    PistaSumidoura* viaS2Sul = PistaSumidoura(relogio, 500, 40);
    return viaS2Sul;
}

PistaSumidoura GeradorPistas::geraViaN1Norte(Relogio* relogio) {
    PistaSumidoura* viaN1Norte = PistaSumidoura(relogio, 500, 60);
    return viaN1Norte;
}

PistaSumidoura GeradorPistas::geraViaN2Norte(Relogio* relogio) {
    PistaSumidoura* viaN2Norte = PistaSumidoura(relogio, 500, 40);
    return viaN2Norte;
}

PistaFonte GeradorPistas::geraViaO1Leste(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaO1Leste = PistaFonte(relogio, semaforo, 2000, 80);
    return viaO1Leste;
}

PistaFonte GeradorPistas::geraViaN1Sul(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaN1Sul = PistaFonte(relogio, semaforo, 500, 60);
    return viaN1Sul;
}

PistaFonte GeradorPistas::geraViaN2Sul(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaN2Sul = PistaFonte(relogio, semaforo, 500, 40);
    return viaN2Sul;
}

PistaFonte GeradorPistas::geraViaS1Norte(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaS1Norte = PistaFonte(relogio, semaforo, 500, 60);
    return viaS1Norte;
}

PistaFonte GeradorPistas::geraViaS2Norte(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaS2Norte = PistaFonte(relogio, semaforo, 500, 40);
    return viaS2Norte;
}

PistaFonte GeradorPistas::geraViaL1Oeste(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaO1Oeste = PistaFonte(relogio, semaforo, 400, 30);
    return viaO1Oeste;
}

Pista GeradorPistas::geraViaC1Oeste(Relogio* relogio, Semaforo* semaforo) {
    Pista* viaC1Oeste = PistaFonte(relogio, semaforo, 300, 60);
    return viaC1Oeste;
}

Pista GeradorPistas::geraViaC1Leste(Relogio* relogio, Semaforo* semaforo) {
    Pista* viaC1Leste = PistaFonte(relogio, semaforo, 300, 60);
    return viaC1Leste;
}

GeradorPistas::geraPista(Relogio* relogio, int intervalo) {
    ListaDupla<Pista*> pistas = ListaDupla<Pista*>();
    GeradorSemaforo semaforo = new GeradorSemaforo(intervalo);
    
    // Pistas Sumidouras:
    Pista* o1oeste, l1leste, s1sul, s2sul, n1norte, n2norte;
    
    o1oeste = this->geraViaO1Oeste(relogio, sem);
    pistas->adicionaDuplo(o1oeste);
    
    l1leste = this->geraViaL1Leste(relogio, sem);
    pistas->adicionaDuplo(l1leste);
    
    s1sul = this->geraViaS1Sul(relogio, sem);
    pistas->adicionaDuplo(s1sul);
    
    s2sul = this->geraViaS2Sul(relogio, sem);
    pistas->adicionaDuplo(s21sul);
    
    n1norte = this->geraViaN1Norte(relogio, sem);
    pistas->adicionaDuplo(n1norte);
    
    n2norte = this->geraViaN2Norte(relogio, sem);
    pistas->adicionaDuplo(n2norte);
    
    
    // Pistas Normais
    Pista* c1oeste, c1leste;
    Semaforo* semC1oeste, semC1leste;
    
    c1oeste = this->geraViaC1Oeste(relogio, sem);
    c1oeste->adicionaPistaSaida(n1norte);
    c1oeste->adicionaPistaSaida(o1oeste);
    c1oeste->adicionaPistaSaida(s1sul);
    pistas->adicionaDuplo(c1oeste);
    
    c1leste = this->geraViaC1Leste(relogio, sem);
    c1leste->adicionaPistaSaida(n2norte);
    c1leste->adicionaPistaSaida(l1leste);
    c1leste->adicionaPistaSaida(s2sul);
    pistas->adicionaDuplo(c1leste);
    
    // Pistas Fontes:
    Pista* o1leste, l1oeste, n1sul, n2sul, s1norte, s2norte;
    Semaforo* semO1leste, semL1oeste, semN1sul, semN2sul, semS1norte, semS2norte;
    
    o1leste = this->geraViaO1Oeste(relogio, sem);
    o1leste->adicionaPistaSaida(n1norte);
    o1leste->adicionaPistaSaida(c1leste);
    o1leste->adicionaPistaSaida(s1sul);
    pistas->adicionaDuplo(o1leste);
    
    l1oeste = this->geraViaL1Oeste(relogio, sem);
    l1oeste->adicionaPistaSaida(n2norte);
    l1oeste->adicionaPistaSaida(c1oeste);
    l1oeste->adicionaPistaSaida(s2sul);
    pistas->adicionaDuplo(l1oeste);
    
    
    n1sul = this->geraViaN1Sul(relogio, sem);
    n1sul->adicionaPistaSaida(o1oeste);
    n1sul->adicionaPistaSaida(s1sul);
    n1sul->adicionaPistaSaida(c1leste);
    pistas->adicionaDuplo(n1sul);
    
    n2sul = this->geraViaN2Sul(relogio, sem);
    n2sul->adicionaPistaSaida(c1oeste);
    n2sul->adicionaPistaSaida(s2sul);
    n2sul->adicionaPistaSaida(l1leste);
    pistas->adicionaDuplo(n2sul);
    
    s1norte = this->geraViaS2Norte(relogio, sem);
    s1norte->adicionaPistaSaida(o1oeste);
    s1norte->adicionaPistaSaida(n1norte);
    s1norte->adicionaPistaSaida(c1leste);
    pistas->adicionaDuplo(s1norte);
    
    s2norte = this->geraViaS2Norte(relogio, sem);
    s2norte->adicionaPistaSaida(c1oeste);
    s2norte->adicionaPistaSaida(n2norte);
    s2norte->adicionaPistaSaida(l1leste);
    pistas->adicionaDuplo(s2norte);
    
    return pistas;
}

#endif
