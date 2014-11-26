#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include "../util/ListaDupla.hpp"
#include "../colecoes/Resultado.hpp"
#include <string>

using std::string;

/*!
 * Classe que ira mostrar o funcionamento do programa
 * de pesquisa pelas manual pages na visao do usuario
 */
class Programa {
 private:
 	string indicePrimario;
 	string indiceSecundario;

 public:
 	/*!
 	 * Inicializa o programa
 	 */
 	Programa(string indicePrimario, string indiceSecundario);

 	/*!
 	 * Executa a ação especificada com os parâmetros especificados
 	 */
 	int executar(string acao, char **argv);

 	/*!
 	 * Indexaçao de um arquivo
 	 */
 	void indexar(ListaDupla<string> *arquivos);

 	/*!
 	 * Metodo que procura pelo indice primario
 	 * o comando referenciado
 	 *
 	 * @param string O comando a ser verificado
 	 */
 	Resultado<ManPage>* procurarIndicePrimario(string *termo);

 	/*!
 	 * Metodo que procura pelo indice secundario
 	 * a palavra referenciada
 	 *
 	 * @param string A palavra a ser verificada
 	 */
 	Resultado<string>* void procurarIndiceSecundario(ListaDupla<string* > *termos);
};

#include "Programa.cpp"
#endif /** PROGRAMA_HPP */
