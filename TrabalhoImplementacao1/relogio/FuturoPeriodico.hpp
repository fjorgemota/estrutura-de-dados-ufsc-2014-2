// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_PERIODICO_HPP
#define FUTURO_PERIODICO_HPP

#include <string>
#include "Futuro.cpp"

using std::string;

/*
 * Futuro Periódico trata-se de um evento futuro que ocorrerá por
 * um determinado periódo e será verificado mais vezes
 */
class FuturoPeriodico : public Futuro {
 public:
    /*
     * Constrói um evento de futuro periódico
     *
     * @param intervalo Quanto tempo durará o evento
     * @param description A descrição do evento
     */
    FuturoPeriodico(int intervalo, string description);

    /*
     * Constrói um evento de futuro periódico
     *
     * @param intervalo Quanto tempo durará o evento
     */
    explicit FuturoPeriodico(int intervalo);

    /*
     * Constrói um evento de futuro periódico
     *
     * @param description A descrição do evento
     */
    explicit FuturoPeriodico(string description);

    /*
     * Constrói um evento de futuro periódico
     */
    FuturoPeriodico();

    /*
     * Destrói um evento de futuro periódico
     */
    ~FuturoPeriodico();

    /*
     * Configura a excução de um evento futuro periódico a partir
     * do segundo pré-estabelecido
     *
     * @param agora O segundo a ser contabilizado para realização do evento
     */
    virtual bool podeExecutar(int agora);

    /*
     * Método que indica a remoção do evento
     */
    virtual bool podeRemover();
};

#endif /* FUTURO_PERIODICO_HPP */
