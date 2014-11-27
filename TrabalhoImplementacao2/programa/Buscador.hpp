#ifndef BUSCADOR_HPP
#define BUSCADOR_HPP

#include "../colecoes/Resultado.hpp"
#include "../modelos/ManPage.hpp"
#include <string.h>
#include <fstream>

using std::string;

/*!
 * Classe que procura atraves dos indices primario e
 * secundario os termos referenciados em uma pesquisa
 */
class Buscador {
 protected:
 	string *indicePrimario;  //!< string correspondente ao 
 							//!< indice primario
 	string *indiceSecundario;  //!< string correspondente ao
 							//!< indice secundario

 public:
 	/*!
 	 * Constroi um buscador
 	 *
 	 * @param indicePrimario Indice correspondente a busca de comandos
 	 * @param indiceSecundario Indice correspondente a busca de palavras
 	 */
 	Buscador(string *indicePrimario, string *indiceSecundario);

 	/*!
 	 *	Metodo que realiza busca pelo indice primario atras
 	 *  do termo referenciado
 	 *
 	 * @param termo O comando a ser encotrado na pesquisa
 	 */
 	ManPage* buscaNoIndicePrimario(string *termo);

 	/*!
 	 * Metodo que realiza busca pelo indice secundario atras
 	 * dos termos referenciados
 	 *
 	 * @param termos Vetor de palavras a ser encontrado na pesquisa
 	 */
 	Resultado<string>* buscaNoIndiceSecundario(ListaDupla<string*> *termos);
};

#include "Buscador.cpp"
#endif /* BUSCADOR_HPP */
