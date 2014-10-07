// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS_CPP
#define GERADOR_PISTAS__CPP

#include "../pista/Pista.cpp"
#include "../pista/PistaSumidoura.cpp"
#include "../pista/PistaFonte.cpp"
#include "../relogio/Relogio.cpp"
#include "../semaforo/Semaforo.cpp"
#include "../util/GeradorProbabilidades.cpp"
#include "../eventos/FuturoPeriodicoPistaFonte.cpp"

GeradorPistas::GeradorPistas(Relogio *relogio, GeradorSemaforo *geradorSemaforo) {
    this->relogio = relogio;
    this->geradorSemaforo = geradorSemaforo;
}

/** Pistas Sumidouras */
Pista* GeradorPistas::geraPistaO1Oeste(Relogio* relogio) {
    if(this->pistaO1Oeste == NULL) {
        this->pistaO1Oeste = new PistaSumidoura(relogio, 2000, 80);
    }
    return this->pistaO1Oeste;
}

Pista* GeradorPistas::geraPistaL1Leste(Relogio* relogio) {
    if(this->pistaL1Leste == NULL) {
        this->pistaL1Leste = new PistaSumidoura(relogio, 400, 30);
    }
    return this->pistaL1Leste;
}

Pista* GeradorPistas::geraPistaS1Sul(Relogio* relogio) {
    if(this->pistaS1Sul == NULL) {
        this->pistaS1Sul = new PistaSumidoura(relogio, 500, 60);
    }
    return this->pistaS1Sul;
}

Pista* GeradorPistas::geraPistaS2Sul(Relogio* relogio) {
    if(this->pistaS2Sul == NULL) {
        this->pistaS2Sul = new PistaSumidoura(relogio, 500, 40);
    } 
    return this->pistaS2Sul;
}

Pista* GeradorPistas::geraPistaN1Norte(Relogio* relogio) {
    if(this->pistaN1Norte == NULL) {
        this->pistaN1Norte = new PistaSumidoura(relogio, 500, 60);
    }
    return this->pistaN1Norte;
}

Pista* GeradorPistas::geraPistaN2Norte(Relogio* relogio) {
    if(this->pistaN2Norte == NULL) {
        this->pistaN2Norte = new PistaSumidoura(relogio, 500, 40);
    }
    return this->pistaN2Norte;
}


/* Pista Normal */ 

Pista* GeradorPistas::geraPistaC1Oeste(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaC1Oeste == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN1Norte(), 30);
        saidas->adiciona(this->geraPistaO1Oeste(), 40);
        saidas->adiciona(this->geraPistaS1Sul(), 30);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemC1oeste();
        this->pistaC1Oeste = new Pista(relogio, semaforo, 300, 60, saidas->pegaLista());
    }
    return this->pistaC1Oeste;
}

Pista* GeradorPistas::geraPistaC1Leste(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaC1Leste == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN2Norte(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        saidas->adiciona(this->geraPistaS2Sul(), 30);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemC1leste();
        this->pistaC1Leste = new Pista(relogio, semaforo, 300, 60, saidas->pegaLista());
    }
    return this->pistaC1Leste;
}

/** Pista Fonte */
Pista* GeradorPistas::geraPistaO1Leste(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaO1Leste == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaN1Norte(), 10);
        saidas->adiciona(this->geraPistaC1Leste(), 80);
        saida->adiciona(this->geraPistaS1Sul(), 10);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemO1leste();
        this->pistaO1Leste = new PistaFonte(relogio, semaforo, 2000, 80, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(this->pistaO1Leste, this->relogio, 8, 12);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaO1Leste;
}

Pista* GeradorPistas::geraPistaN1Sul(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaN1Sul == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaO1Oeste(), 10);
        saidas->adiciona(this->geraPistaS1Sul(), 10);
        saidas->adiciona(this->geraPistaC1Leste(), 80);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemN1sul();
        this->pistaN1Sul = new PistaFonte(relogio, semaforo, 500, 60, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(this->pistaN1Sul, this->relogio, 15, 25);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaN1Sul;
}

Pista* GeradorPistas::geraPistaN2Sul(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaN2Sul == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaC1Oeste(), 30);
        saidas->adiciona(this->geraPistaN2Sul(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemN2sul();
        this->pistaN2Sul = new PistaFonte(relogio, semaforo, 500, 40, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(this->pistaN2Sul, this->relogio, 15, 25);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaN2Sul;
}

Pista* GeradorPistas::geraPistaS1Norte(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaS1Norte == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaO1Oeste(), 10);
        saidas->adiciona(this->geraPistaN1Norte(), 10);
        saidas->adiciona(this->geraPistaC1Leste, 80);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemS1norte();
        this->pistaS1Norte = new PistaFonte(relogio, semaforo, 500, 60, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(this->pistaS1Norte, this->relogio, 23, 37);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaS1Norte;
}

Pista* GeradorPistas::geraPistaS2Norte(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaS2Norte == NULL) {
        GeradorProbabilidades<Pista*> saidas = new GeradorProbabilidades<Pista*>();
        saidas->adiciona(this->geraPistaC1Oeste(), 30);
        saidas->adiciona(this->geraPistaN2Norte(), 30);
        saidas->adiciona(this->geraPistaL1Leste(), 40);
        Semaforo* semaforo = this->geradorSemaforo->pegaSemS2norte();
        this->pistaS2Norte = new PistaFonte(relogio, semaforo, 500, 40, saidas->pegaLista());
        FuturoPeriodicoPistaFonte *futuro;
        futuro = new FuturoPeriodicoPistaFonte(this->pistaS2Norte, this->relogio, 45, 75);
        this->relogio->agenda(futuro);
        futuro->agendar();
    }
    return this->pistaS2Norte;
}

Pista* GeradorPistas::geraPistaL1Oeste(Relogio* relogio, Semaforo* semaforo) {
    if(this->pistaL1Oeste == NULL) {
        this->pistal1Oeste = new PistaFonte(relogio, semaforo, 400, 30);
    }
    return this->pistaL1Oeste;
}

ListaDupla<Pista*> GeradorPistas::geraPistas() {
    ListaDupla<Pista*> pistas = ListaDupla<Pista*>();
    
    pistas->adicionaDuplo(this->geraPistaO1Oeste());
    pistas->adicionaDuplo(this->geraPistaL1Leste());
    pistas->adicionaDuplo(this->geraPistaS1Sul());
    pistas->adicionaDuplo(this->geraPistaS2Sul());
    pistas->adicionaDuplo(this->geraPistaN1Norte());
    pistas->adicionaDuplo(this->geraPistaN2Norte());
    
    pistas->adicionaDuplo(this->geraPistaC1Oeste());
    pistas->adicionaDuplo(this->geraPistaC1Leste());
    
    pistas->adicionaDuplo(this->geraPistaO1Leste());
    pistas->adicionaDuplo(this->geraPistaL1Oeste());
    pistas->adicionaDuplo(this->geraPistaN1Sul());
    pistas->adicionaDuplo(this->geraPistaN2Sul());
    pistas->adicionaDuplo(this->geraPistaS1Norte());
    pistas->adicionaDuplo(this->geraPistaS2Norte());
    
    return pistas;
}

#endif
