#ifndef SERIALIZADOR_HPP
#define SERIALIZADOR_HPP

#include "../util/ListaDupla.hpp"
#include <iostream> //cout
#include <fstream> //fstream

using std::ofstream;
using std::ifstream;

/*!
 * Classe usada para verficar os arquivos referenciados
 * da ManPage, atraves de escritas e leituras, definindo
 * a importancia de quais dados a serem vistos
 */
template<typename T>
class Serializador {
 public:
 	/*!
 	 * Metodo que le um arquivo
 	 *
 	 * @param arquivo O arquivo a ser lido
 	 */
 	virtual T* le(ifstream *arquivo);

 	/*!
 	 * Metodo que escreve em um arquivo
 	 *
 	 * @param arquivo O arquivo a ser escrito
 	 * @param dado O dado a ser escrito no arquivo
 	 * @param tamanho O tamanho do arquivo
 	 */
 	virtual void escreve(ofstream *arquivo, T* dado, int tamanho);
 
 	/*!
 	 * Metodo que calcula a proxima posiçao de um arquivo
 	 *
 	 * @param arquivo O arquivo que sera verificado
 	 */
 	virtual void proximaPosicao(ifstream *arquivo);
};

#include "Serializador.cpp"

#endif /*SERIALIZADOR_HPP*/
