// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_PISTA_FONTE_HPP
#define FUTURO_PERIODICO_PISTA_FONTE_HPP
#include "../pista/PistaFonte.cpp"
#include "../relogio/Relogio.cpp"
#include "../relogio/FuturoPeriodico.cpp"

/*
 * Classe que indica a entrada de um carro numa pista fonte, ou seja, na
 * pista de início do percurso.
 */
class FuturoPeriodicoPistaFonte : public FuturoPeriodico {
 private:
    PistaFonte *pista;  //!< A pista fonte em que o carro se iniciará o percurso
    Relogio *relogio;  //!< O relógio para a sincronização da pista
    int intervaloMinimo;  //!< O menor tempo de percurso do veículo na pista
    int intervaloMaximo;  //!< O maior tempo de percurso do veículo na pista

 public:
    /*
     * Constrói um evento periódico que adicionará carros na pista fonte
     *
     * @param pista A pista fonte em que o carro irá percorrer
     * @param relogio O relógio usado para sincronização
     * @param intervaloMinimo O menor tempo de percurso do veículo na pista
     * @param intervaloMaximo O maior tempo de percurso do veículo na pista
     */
    FuturoPeriodicoPistaFonte(PistaFonte *pista,  Relogio *relogio,
        int intervaloMinimo, int intervaloMaximo);

    /*
     * Sorteia um determinado intervalo para que o carro seja adicionado
     */
    void agendar();

    /*
     * Método que executa a inicialização de um carro na pista fonte
     */
    virtual void executar();

    /*
     * Método que indica se o evento pode ser executado ou não
     *
     * @param segundoAtual O segundo em que o evento ocorrerá
     */
    virtual bool podeExecutar(int segundoAtual);
};

#endif /* FUTURO_PERIODICO_PISTA_FONTE_HPP */
