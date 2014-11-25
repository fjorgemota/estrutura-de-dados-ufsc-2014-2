#ifndef INDEXADOR_HPP
#define INDEXADOR_HPP

#include "../colecoes/IndicePrimario.hpp"
#include "../colecoes/IndiceSecundario.hpp"
#include "../util/RemovedorLexico.hpp"

class Indexador {
 private:
 	IndicePrimario *indicePrimario;
 	IndiceSecundario *indiceSecundario;
 	RemovedorLexico *removedor;

 	char* retiraExtensao(char *nome);

 	string* leConteudo(char *nome);

 public:
 	explicit Indexador(RemovedorLexico *removedor);

 	void indexaArquivo(char *nome);

 	void salvaIndicePrimario(char *nome);

 	void salvaIndiceSecundario(char *nome);

 	void executa();
};

#include "Indexador.cpp"

#endif /** INDEXADOR_HPP */