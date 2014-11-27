#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include "../colecoes/Resultado.hpp"
#include "../modelos/ManPage.hpp"
#include "../modelos/Word.hpp"
#include "../util/ListaDupla.hpp"
#include <string>

using std::string;

/*!
 * Classe que ira mostrar o funcionamento do programa
 * de pesquisa pelas manual pages na visao do usuario
 */
class Programa {
 private:
 	string *indicePrimario;
 	string *indiceSecundario;

 public:
 	/*!
 	 * Inicializa o programa
 	 */
 	Programa(string *indicePrimario, string *indiceSecundario);

 	/*!
 	 * Executa a ação especificada com os parâmetros especificados
 	 */
 	int executa(int argc, char **argv);

 	/*!
 	 * Indexaçao de um arquivo
 	 */
 	void indexar(ListaDupla<string* > *arquivos);

 	/*!
 	 * Metodo que procura pelo indice primario
 	 * o comando referenciado
 	 *
 	 * @param string O comando a ser verificado
 	 */
 	ManPage* procurarIndicePrimario(string *termo);

 	/*!
 	 * Metodo que procura pelo indice secundario
 	 * a palavra referenciada
 	 *
 	 * @param string A palavra a ser verificada
 	 */
 	Resultado<string>* procurarIndiceSecundario(ListaDupla<string* > *termos);
};

#include "Programa.cpp"
#endif /** PROGRAMA_HPP */
