// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS_CPP
#define GERADOR_PISTAS_CPP

#include "GeradorPistas.hpp"
#include "../pista/Pista.cpp"
#include "../pista/PistaSumidoura.cpp"
#include "../pista/PistaFonte.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/GeradorProbabilidades.cpp"
#include "../eventos/FuturoPeriodicoPistaFonte.cpp"

GeradorPistas::GeradorPistas(Relogio *relogio,
                    GeradorSemaforo *geradorSemaforo) {
    this->relogio = relogio;
    this->geradorSemaforo = geradorSemaforo;
    this->pistaO1Oeste = NULL;
    this->pistaL1Leste = NULL;
    this->pistaS1Sul = NULL;
    this->pistaS2Sul = NULL;
    this->pistaN1Norte = NULL;
    this->pistaN2Norte = NULL;
    this->pistaO1Leste = NULL;
    this->pistaN1Sul = NULL;
    this->pistaN2Sul = NULL;
    this->pistaS1Norte = NULL;
    this->pistaS2Norte = NULL;
    this->pistaL1Oeste = NULL;
    this->pistaC1Oeste = NULL;
    this->pistaC1Leste = NULL;
}


GeradorPistas::~GeradorPistas() {
    if (this->pistaO1Oeste != NULL) {
        delete this->pistaO1Oeste;
    }
    if (this->pistaL1Leste != NULL) {
        delete this->pistaL1Leste;
    }
    if (this->pistaS1Sul != NULL) {
        delete this->pistaS1Sul;
    }
    if (this->pistaS2Sul != NULL) {
        delete this->pistaS2Sul;
    }
    if (this->pistaN1Norte != NULL) {
        delete this->pistaN1Norte;
    }
    if (this->pistaN2Norte != NULL) {
        delete this->pistaN2Norte;
    }
    if (this->pistaO1Leste != NULL) {
        delete this->pistaO1Leste;
    }
    if (this->pistaN1Sul != NULL) {
        delete this->pistaN1Sul;
    }
    if (this->pistaN2Sul != NULL) {
        delete this->pistaN2Sul;
    }
    if (this->pistaS1Norte != NULL) {
        delete this->pistaS1Norte;
    }
    if (this->pistaS2Norte != NULL) {
        delete this->pistaS2Norte;
    }
    if (this->pistaL1Oeste != NULL) {
        delete this->pistaL1Oeste;
    }
    if (this->pistaC1Oeste != NULL) {
        delete this->pistaC1Oeste;
    }
    if (this->pistaC1Leste != NULL) {
        delete this->pistaC1Leste;
    }
}

/** Pistas Sumidouras */
Pista* GeradorPistas::geraPistaO1Oeste() {
    if (this->pistaO1Oeste == NULL) {
        this->pistaO1Oeste = new PistaSumidoura(this->relogio, 2000, 80);
    }
    return this->pistaO1Oeste;
}

Pista* GeradorPistas::geraPistaL1Leste() {
    if (this->pistaL1Leste == NULL) {
        this->pistaL1Leste = new PistaSumidoura(this->relogio, 400, 30);
    }
    return this->pistaL1Leste;
}

Pista* GeradorPistas::geraPistaS1Sul() {
    if (this->pistaS1Sul == NULL) {
        this->pistaS1Sul = new PistaSumidoura(this->relogio, 500, 60);
    }
    return this->pistaS1Sul;
}

Pista* GeradorPistas::geraPistaS2Sul() {
    if (this->pistaS2Sul == NULL) {
        this->pistaS2Sul = new PistaSumidoura(this->relogio, 500, 40);
    }
    return this->pistaS2Sul;
}

Pista* GeradorPistas::geraPistaN1Norte() {
    if (this->pistaN1Norte == NULL) {
        this->pistaN1Norte = new PistaSumidoura(this->relogio, 500, 60);
    }
    return this->pistaN1Norte;
}

Pista* GeradorPistas::geraPistaN2Norte() {
    if (this->pistaN2Norte == NULL) {
        this->pistaN2Norte = new PistaSumidoura(this->relogio, 500, 40);
    }
    return this->pistaN2Norte;
}

/* Pista Normal */
Pista* GeradorPistas::geraPistaC1Oeste() {
    if (this->pistaC1Oeste == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN1Norte(), 30);
        saidas->adiciona(this->geraPistaO1Oeste(), 40);
        saidas->adiciona(this->geraPistaS1Sul(), 30);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemC1oeste();
        this->pistaC1Oeste = new Pista(this->relogio, semaforo, 300, 60,
                                                        saidas->pegaLista());
    }
    return this->pistaC1Oeste;
}

Pista* GeradorPistas::geraPistaC1Leste() {
    if (this->pistaC1Leste == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN2Norte(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        saidas->adiciona(this->geraPistaS2Sul(), 30);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemC1leste();
        this->pistaC1Leste = new Pista(this->relogio, semaforo, 300, 60,
                                                        saidas->pegaLista());
    }
    return this->pistaC1Leste;
}

/** Pista Fonte */
Pista* GeradorPistas::geraPistaO1Leste() {
    if (this->pistaO1Leste == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN1Norte(), 10);
        saidas->adiciona(this->geraPistaC1Leste(), 80);
        saidas->adiciona(this->geraPistaS1Sul(), 10);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemO1leste();
        this->pistaO1Leste = new PistaFonte(this->relogio, semaforo,
                                            2000, 80, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte((PistaFonte*) this->pistaO1Leste,
                                                    this->relogio, 8, 12);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaO1Leste;
}

Pista* GeradorPistas::geraPistaN1Sul() {
    if (this->pistaN1Sul == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaO1Oeste(), 10);
        saidas->adiciona(this->geraPistaS1Sul(), 10);
        saidas->adiciona(this->geraPistaC1Leste(), 80);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemN1sul();
        this->pistaN1Sul = new PistaFonte(this->relogio, semaforo, 500, 60,
                                                saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte((PistaFonte*) this->pistaN1Sul,
                                                    this->relogio, 15, 25);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaN1Sul;
}

Pista* GeradorPistas::geraPistaN2Sul() {
    if (this->pistaN2Sul == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaC1Oeste(), 30);
        saidas->adiciona(this->geraPistaS2Sul(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemN2sul();
        this->pistaN2Sul = new PistaFonte(this->relogio, semaforo, 500, 40,
                                                    saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte((PistaFonte*) this->pistaN2Sul,
                                                        this->relogio, 15, 25);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaN2Sul;
}

Pista* GeradorPistas::geraPistaS1Norte() {
    if (this->pistaS1Norte == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaO1Oeste(), 10);
        saidas->adiciona(this->geraPistaN1Norte(), 10);
        saidas->adiciona(this->geraPistaC1Leste(), 80);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemS1norte();
        this->pistaS1Norte = new PistaFonte(this->relogio, semaforo, 500,
                                        60, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte((PistaFonte*) this->pistaS1Norte,
                                                    this->relogio, 23, 37);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaS1Norte;
}

Pista* GeradorPistas::geraPistaS2Norte() {
    if (this->pistaS2Norte == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaC1Oeste(), 30);
        saidas->adiciona(this->geraPistaN2Norte(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemS2norte();
        this->pistaS2Norte = new PistaFonte(this->relogio, semaforo, 500,
                                                    40, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(
            (PistaFonte*) this->pistaS2Norte,
                    this->relogio, 45, 75);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaS2Norte;
}

Pista* GeradorPistas::geraPistaL1Oeste() {
    if (this->pistaL1Oeste == NULL) {
        GeradorProbabilidades<Pista*> *saidas =
                        new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN2Norte(), 40);
        saidas->adiciona(this->geraPistaC1Oeste(), 30);
        saidas->adiciona(this->geraPistaS2Sul(), 30);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemL1oeste();
        this->pistaL1Oeste = new PistaFonte(this->relogio,
                            semaforo, 400, 30, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte((PistaFonte*) this->pistaL1Oeste,
                                                    this->relogio, 8, 12);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaL1Oeste;
}

void GeradorPistas::geraPistas() {
    /* Pistas sumidouras*/
    this->geraPistaO1Oeste();
    this->geraPistaL1Leste();
    this->geraPistaS1Sul();
    this->geraPistaS2Sul();
    this->geraPistaN1Norte();
    this->geraPistaN2Norte();
    /* Pistas normais */
    this->geraPistaC1Oeste();
    this->geraPistaC1Leste();
    /* Pistas fontes */
    this->geraPistaO1Leste();
    this->geraPistaL1Oeste();
    this->geraPistaN1Sul();
    this->geraPistaN2Sul();
    this->geraPistaS1Norte();
    this->geraPistaS2Norte();
}

#endif
