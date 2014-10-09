// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURO_HPP
#define FUTURO_HPP

#include <string>
#include "Evento.cpp"
#include "Retorno.hpp"

using std::string;

/*
 * Classe futuro, que representa um evento que ainda irá ocorrer
 * (mas está "pré-agendado") e será verificado uma vez
 */
class Futuro: public Evento, public Retorno {
 private:
    bool remover;  //!< Variável booleana indicando a remoção do evento

 public:
    /*
     * Constrói um evento futuro
     *
     * @param intervalo Quanto tempo durará o evento
     * @param descricao Descrição do evento futuro
     */
    Futuro(int intervalo, string descricao);

    /*
     * Constrói um evento futuro
     *
     * @param intervalo Quanto tempo durará o evento
     */
    explicit Futuro(int intervalo);

    /*
     * Constrói um evento futuro
     *
     * @param descricao Descrição do evento futuro
     */
    explicit Futuro(string descricao);

    /*
     * Constrói um evento futuro
     */
    Futuro();

    /*
     * Destroi o evento futuro
     */
    ~Futuro();

    /*
     * Configura a execução de um evento futuro, a partir do atual momento
     *
     * @param segundoAtual O segundo que inicializará o evento
     */
    virtual bool podeExecutar(int segundoAtual);

    /*
     * Método que indica a remoção do evento
     */
    virtual bool podeRemover();
};

#endif /* FUTURO_HPP */
