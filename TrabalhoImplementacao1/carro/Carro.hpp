// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef CARRO_HPP
#define CARRO_HPP

/*
 * Carro, meio de transporte utilizado para trafegar pela pista, respeitando os limites impostos
 * pela pista e pelo semáforo
 */
class Carro {
 private:
    int tamanho;  //!< O tamanho do carro (em metros)

 public:
    /*
     * Constrói um carro
     */
    Carro();

    /*
     * Destrói o carro
     */
    ~Carro();

    /*
     * Retorna o tamanho do carro
     */
    int pegaTamanho();
};

#endif /* CARRO_HPP */
