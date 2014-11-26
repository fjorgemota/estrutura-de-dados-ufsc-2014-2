#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

/*!
 * Classe que ira mostrar o funcionamento do programa
 * de pesquisa pelas manual pages na visao do usuario
 */
class Programa {
 public:
 	/*!
 	 * Indexaçao de um arquivo
 	 */
 	void indexar();

 	/*!
 	 * Metodo que procura pelo indice primario
 	 * o comando referenciado
 	 *
 	 * @param string O comando a ser verificado
 	 */
 	void procurarIndicePrimario(char *string);

 	/*!
 	 * Metodo que procura pelo indice secundario
 	 * a palavra referenciada
 	 *
 	 * @param string A palavra a ser verificada
 	 */
 	void procurarIndiceSecundario(char *string);
};

#include "Programa.cpp"
#endif /** PROGRAMA_HPP */
