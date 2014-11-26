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
 		//!< Arvore de indice primario que armazenara
 		//!< os comandos referenciados pelos arquivos 
 	IndiceSecundario *indiceSecundario;
 		//!< Arvore de indice secundario que armazenara
 		//!< as palavras referenciadas pelos arquivos
 	RemovedorLexico *removedor;
 		//!< Conectivos que serao ignorados na indexaçao

 	/*!
 	 * Metodo que remove a extensao '.txt' do
 	 * arquivo manual page
 	 *
 	 * @param nome O nome do arquivo que sera verificado
 	 */
 	string* retiraExtensao(char *nome);

 	/*!
 	 * Metodo que le os conteudos do arquivo 
 	 * manual page referenciado
 	 *
 	 * @param nome O nome do arquivo que sera lido
 	 */
 	string* leConteudo(char *nome);

 public:
 	/*!
 	 * Controi um indexador
 	 *
 	 * @param removedor A lista de conectivos ignorados
 	 * para a indexaçao
 	 */
 	explicit Indexador(RemovedorLexico *removedor);

 	/*!
 	 * Indexa (identifica) um arquivo
 	 *
 	 * @param nome O nome do arquivo que sera indexado
 	 */
 	void indexaArquivo(char *nome);

 	/*!
 	 * Metodo que gera e salva os arquivos na arvore
 	 * de indice primario
 	 *
 	 * @param nome O nome do arquivo a ser salvo
 	 */
 	void salvaIndicePrimario(char *nome);

 	/*!
 	 * Metodo que gera e salva os arquivos na arvore
 	 * de indice secundario
 	 *
 	 * @param nome O nome do arquivo a ser salvo
 	 */
 	void salvaIndiceSecundario(char *nome);
};

#include "Indexador.cpp"

#endif /** INDEXADOR_HPP */
