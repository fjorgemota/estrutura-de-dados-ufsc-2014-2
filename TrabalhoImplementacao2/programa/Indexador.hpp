#ifndef INDEXADOR_HPP
#define INDEXADOR_HPP

#include "../colecoes/IndicePrimario.hpp"
#include "../colecoes/IndiceSecundario.hpp"
#include "../util/RemovedorLexico.hpp"

/*!
 * Classe que indexa (indentifica) um registro
 * a fim de usa-los como referencia para a
 * pesquisa pelas manual pages
 */
class Indexador {
 private:
 	IndicePrimario *indicePrimario;
 	IndiceSecundario *indiceSecundario;
 	RemovedorLexico *removedor;

 	string* retiraExtensao(char *nome);

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
