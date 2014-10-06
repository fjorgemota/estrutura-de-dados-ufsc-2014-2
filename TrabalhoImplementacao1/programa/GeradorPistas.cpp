// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef GERADOR_PISTAS_CPP
#define GERADOR_PISTAS__CPP

PistaSumidoura GeradorPistas::geraViaO1Oeste(Relogio* relogio) {
    PistaSumidoura* viaO1Oeste = PistaSumidoura(relogio, 2000, 80);
}

PistaSumidoura GeradorPistas::geraViaL1Leste(Relogio* relogio) {
    PistaSumidoura* viaL1Leste = PistaSumidoura(relogio, 400, 30);
}

PistaSumidoura GeradorPistas::geraViaS1Sul(Relogio* relogio) {
    PistaSumidoura* viaS1Sul = PistaSumidoura(relogio, 500, 60);
}

PistaSumidoura GeradorPistas::geraViaS2Sul(Relogio* relogio) {
    PistaSumidoura* viaS2Sul = PistaSumidoura(relogio, 500, 40);
}

PistaSumidoura GeradorPistas::geraViaN1Norte(Relogio* relogio) {
    PistaSumidoura* viaN1Norte = PistaSumidoura(relogio, 500, 60);
}

PistaSumidoura GeradorPistas::geraViaN2Norte(Relogio* relogio) {
    PistaSumidoura* viaN2Norte = PistaSumidoura(relogio, 500, 40);
}

PistaFonte GeradorPistas::geraViaO1Leste(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaO1Leste = PistaFonte(relogio, semaforo, 2000, 80);
}

PistaFonte GeradorPistas::geraViaN1Sul(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaN1Sul = PistaFonte(relogio, semaforo, 500, 60);
}

PistaFonte GeradorPistas::geraViaN2Sul(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaN2Sul = PistaFonte(relogio, semaforo, 500, 40);
}

PistaFonte GeradorPistas::geraViaS1Norte(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaS1Norte = PistaFonte(relogio, semaforo, 500, 60);
}

PistaFonte GeradorPistas::geraViaS2Norte(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaS2Norte = PistaFonte(relogio, semaforo, 500, 40);
}

PistaFonte GeradorPistas::geraViaL1Oeste(Relogio* relogio, Semaforo* semaforo) {
    PistaFonte* viaO1Oeste = PistaFonte(relogio, semaforo, 400, 30);
}

Pista GeradorPistas::geraViaC1Oeste(Relogio* relogio, Semaforo* semaforo) {
    Pista* viaC1Oeste = PistaFonte(relogio, semaforo, 300, 60);
}

Pista GeradorPistas::geraViaC1Leste(Relogio* relogio, Semaforo* semaforo) {
    Pista* viaC1Leste = PistaFonte(relogio, semaforo, 300, 60);
}

GeradorPistas::geraPista(Relogio* relogio, int intervalo) {
    ListaDupla<Pista*> pistas = ListaDupla<Pista*>();
    GeradorSemaforo semaforo = new GeradorSemaforo(intervalo);
    
    Semaforo* sem = semaforo->semO1leste();
    Semaforo* sem2 = semaforo->semN1sul();
    Semaforo* sem3 = semaforo->semN2sul();
    Semaforo* sem4 = semaforo->semS1norte();
    Semaforo* sem5 = semaforo->semS2norte();
    Semaforo* sem6 = semaforo->semC1oeste();
    Semaforo* sem7 = semaforo->semC1leste();
    Semaforo* sem8 = semaforo->semL1oeste();
    
    Pista* fonte = this->geraViaO1Leste(relogio, sem);
    fonte->adicionaPistaSaida(this->geraViaC1Leste(relogio, sem7));
    fonte->adicionaPistaSaida(this->geraViaN1Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaS1Sul(relogio));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaC1Leste(relogio, sem7);
    fonte->adicionaPistaSaida(this->geraViaL1Leste(relogio));
    fonte->adicionaPistaSaida(this->geraViaN2Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaS2Sul(relogio));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaL1Oeste(relogio, sem8);
    fonte->adicionaPistaSaida(this->geraViaS2Sul(relogio));
    fonte->adicionaPistaSaida(this->geraViaN2Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaC1Oeste(relogio, sem6));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaC1Oeste(relogio sem6);
    fonte->adicionaPistaSaida(this->geraViaN1Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaS1Sul(relogio));
    fonte->adicionaPistaSaida(this->geraViaO1Oeste(relogio));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaS1Norte(relogio, sem4);
    fonte->adicionaPistaSaida(this->geraViaN1Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaC1Leste(relogio, sem7));
    fonte->adicionaPistaSaida(this->geraViaO1Oeste(relogio));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaN1Sul(relogio, sem2);
    fonte->adicionaPistaSaida(this->geraViaO1Oeste(relogio));
    fonte->adicionaPistaSaida(this->geraViaC1Leste(relogio, sem7));
    fonte->adicionaPistaSaida(this->geraViaO1Oeste(relogio));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaS2Norte(relogio, sem5);
    fonte->adicionaPistaSaida(this->geraViaN2Norte(relogio));
    fonte->adicionaPistaSaida(this->geraViaL1Leste(relogio));
    fonte->adicionaPistaSaida(this->geraViaC1Oeste(relogio, sem6));
    pistas->adicionaDuplo(fonte);
    
    fonte = this->geraViaN2Sul(relogio, sem3);
    fonte->adicionaPistaSaida(this->geraViaS2Sul(relogio));
    fonte->adicionaPistaSaida(this->geraViaL1Leste(relogio));
    fonte->adicionaPistaSaida(this->geraViaC1Oeste(relogio, sem6));
    pistas->adicionaDuplo(fonte);
    
    return pistas;
}

#endif
