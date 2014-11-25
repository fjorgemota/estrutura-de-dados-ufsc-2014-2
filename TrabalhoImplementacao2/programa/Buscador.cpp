#ifndef BUSCADOR_CPP
#define BUSCADOR_CPP
#include "Buscador.hpp"

Buscador::Buscador(string indicePrimario, string indiceSecundario) {
	this->indicePrimario = indicePrimario;
	this->indiceSecundario = indiceSecundario;
}

Resultado<ManPage>* Buscador::buscaNoIndicePrimario(string termo) {
	int contador;
	string *comparar, *resposta;
	ifstream *arquivo;
	Resultado<ManPage> *resultados = new Resultado<ManPage>();
	SerializadorManPage manpage = new SerializadorManPage();
	Serializador<int> serializadorInt = new Serializador<int>();
	int tamanho = *(serializadorInt->le(arquivo));

	for (contador = 0; contador <= tamanho; contador++) {
		comparar = manpage->leComando(arquivo); 
		if (comparar == termo) {
			resposta = manpage->leConteudo(arquivo);
			cout << "Termo procurado: " << resposta << endl;
		} else {
			manpage->pulaConteudo(arquivo);
		}
	}

	delete serializadorInt;
	delete manpage;
	return resultados;
}


#endif /* BUSCADOR_CPP */
