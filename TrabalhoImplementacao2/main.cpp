#include "programa/Indexador.hpp"
#include "colecoes/IndicePrimario.hpp"
#include "colecoes/IndiceSecundario.hpp"
#include "colecoes/IndiceSecundario.hpp"
#include "util/RemovedorLexico.hpp"
#include <stdio.h>
#include <string>
#include <fstream> //fstream
#include <iostream> //cout

using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;


int main(int argc, char **argv) {
	RemovedorLexico *removedor = new RemovedorLexico();
	Indexador *indexer = new Indexador(removedor);
	for(int i=1; i<argc; i++) {
		printf("Indexando arquivo %d de %d\n", i-1, argc-2);
		indexer->indexaArquivo(argv[i]);	
	} 
	indexer->salvaIndicePrimario("manpages.dat");
	indexer->salvaIndiceSecundario("manwords.dat");
	delete removedor;
	delete indexer;
	
	return 0;
}