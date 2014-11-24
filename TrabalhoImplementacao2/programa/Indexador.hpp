#ifndef INDEXADOR_HPP
#define INDEXADOR_HPP

#include "../colecoes/IndicePrimario.hpp"
#include "../colecoes/indiceSecundario.hpp"

class Indexador {
 private:
 	IndicePrimario indicePrimario;
 	indiceSecundario indiceSecundario;

 	void listaArquivos();

 	void indexaArquivo(char *filename);


 public:
 	explicit Indexador(char *filename, IndicePrimario indicePrimario,
 		IndicePrimario indiceSecundario);

 	void executa();
};

#include "Indexador.cpp"

#endif /** INDEXADOR_HPP */