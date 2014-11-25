#ifndef REMOVEDOR_LEXICO_CPP
#define REMOVEDOR_LEXICO_CPP
#include "RemovedorLexico.hpp"
#include "ListaDupla.hpp"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

RemovedorLexico::RemovedorLexico() {
	this->conectivosProibidos = new ListaDupla<string>();
	this->criar_lista_artigos();
	this->criar_lista_conjuncoes();
	this->criar_lista_preposicoes();
	this->criar_lista_pronomes();
}

RemovedorLexico::~RemovedorLexico() {
	delete this->conectivosProibidos;
}

bool RemovedorLexico::e_conectivo(string palavra) {
	return (palavra.size() > 2 && !(this->conectivosProibidos->contemDuplo(palavra)));
}

ListaDupla<string>* RemovedorLexico::separa_em_palavras(string busca) {
	ListaDupla<string> *termos = new ListaDupla<string>();
	string palavra;
	stringstream stream(busca);
	while (stream >> palavra) {
		termos->adicionaNoInicioDuplo(palavra);	
	}
	return termos;
}

ListaDupla<string>* RemovedorLexico::remove_conectivos(ListaDupla<string> *palavras) {
	ListaDupla<string> *resultado = new ListaDupla<string>();	
	int i = 0;
	int l = palavras->verUltimo();
	string *vetor = palavras->paraVetor();
	for(i = 0; i <= l; i++) {
		if (this->e_conectivo(vetor[i])) {
			resultado->adicionaNoInicioDuplo(vetor[i]);
		}
	}
	return resultado;
}

void RemovedorLexico::criar_lista_artigos() {
	this->conectivosProibidos->adicionaNoInicioDuplo("a");
	this->conectivosProibidos->adicionaNoInicioDuplo("an");
	this->conectivosProibidos->adicionaNoInicioDuplo("the");
	this->conectivosProibidos->adicionaNoInicioDuplo("no");
}

void RemovedorLexico::criar_lista_conjuncoes() {
	this->conectivosProibidos->adicionaNoInicioDuplo("for");
	this->conectivosProibidos->adicionaNoInicioDuplo("and");
	this->conectivosProibidos->adicionaNoInicioDuplo("nor");
	this->conectivosProibidos->adicionaNoInicioDuplo("but");
	this->conectivosProibidos->adicionaNoInicioDuplo("or");
	this->conectivosProibidos->adicionaNoInicioDuplo("yet");
	this->conectivosProibidos->adicionaNoInicioDuplo("so");
}

void RemovedorLexico::criar_lista_preposicoes() {
	this->conectivosProibidos->adicionaNoInicioDuplo("aboard");
	this->conectivosProibidos->adicionaNoInicioDuplo("about");
	this->conectivosProibidos->adicionaNoInicioDuplo("above");
	this->conectivosProibidos->adicionaNoInicioDuplo("across");
	this->conectivosProibidos->adicionaNoInicioDuplo("after");
	this->conectivosProibidos->adicionaNoInicioDuplo("against");
	this->conectivosProibidos->adicionaNoInicioDuplo("ahead");
	this->conectivosProibidos->adicionaNoInicioDuplo("along");
	this->conectivosProibidos->adicionaNoInicioDuplo("amid");
	this->conectivosProibidos->adicionaNoInicioDuplo("amidst");
	this->conectivosProibidos->adicionaNoInicioDuplo("among");
	this->conectivosProibidos->adicionaNoInicioDuplo("around");
	this->conectivosProibidos->adicionaNoInicioDuplo("as");
	this->conectivosProibidos->adicionaNoInicioDuplo("aside");
	this->conectivosProibidos->adicionaNoInicioDuplo("at");
	this->conectivosProibidos->adicionaNoInicioDuplo("athwart");
	this->conectivosProibidos->adicionaNoInicioDuplo("atop");
	this->conectivosProibidos->adicionaNoInicioDuplo("barring");
	this->conectivosProibidos->adicionaNoInicioDuplo("because");
	this->conectivosProibidos->adicionaNoInicioDuplo("before");
	this->conectivosProibidos->adicionaNoInicioDuplo("behind");
	this->conectivosProibidos->adicionaNoInicioDuplo("below");
	this->conectivosProibidos->adicionaNoInicioDuplo("beneath");
	this->conectivosProibidos->adicionaNoInicioDuplo("beside");
	this->conectivosProibidos->adicionaNoInicioDuplo("besides");
	this->conectivosProibidos->adicionaNoInicioDuplo("between");
	this->conectivosProibidos->adicionaNoInicioDuplo("beyond");
	this->conectivosProibidos->adicionaNoInicioDuplo("but");
	this->conectivosProibidos->adicionaNoInicioDuplo("by");
	this->conectivosProibidos->adicionaNoInicioDuplo("circa");
	this->conectivosProibidos->adicionaNoInicioDuplo("concerning");
	this->conectivosProibidos->adicionaNoInicioDuplo("despite");
	this->conectivosProibidos->adicionaNoInicioDuplo("down");
	this->conectivosProibidos->adicionaNoInicioDuplo("during");
	this->conectivosProibidos->adicionaNoInicioDuplo("except");
	this->conectivosProibidos->adicionaNoInicioDuplo("excluding");
	this->conectivosProibidos->adicionaNoInicioDuplo("following");
	this->conectivosProibidos->adicionaNoInicioDuplo("for");
	this->conectivosProibidos->adicionaNoInicioDuplo("from");
	this->conectivosProibidos->adicionaNoInicioDuplo("in");
	this->conectivosProibidos->adicionaNoInicioDuplo("including");
	this->conectivosProibidos->adicionaNoInicioDuplo("inside");
	this->conectivosProibidos->adicionaNoInicioDuplo("instead");
	this->conectivosProibidos->adicionaNoInicioDuplo("into");
	this->conectivosProibidos->adicionaNoInicioDuplo("like");
	this->conectivosProibidos->adicionaNoInicioDuplo("minus");
	this->conectivosProibidos->adicionaNoInicioDuplo("near");
	this->conectivosProibidos->adicionaNoInicioDuplo("of");
	this->conectivosProibidos->adicionaNoInicioDuplo("off");
	this->conectivosProibidos->adicionaNoInicioDuplo("on");
	this->conectivosProibidos->adicionaNoInicioDuplo("onto");
	this->conectivosProibidos->adicionaNoInicioDuplo("opposite");
	this->conectivosProibidos->adicionaNoInicioDuplo("out");
	this->conectivosProibidos->adicionaNoInicioDuplo("outside");
	this->conectivosProibidos->adicionaNoInicioDuplo("over");
	this->conectivosProibidos->adicionaNoInicioDuplo("past");
	this->conectivosProibidos->adicionaNoInicioDuplo("plus");
	this->conectivosProibidos->adicionaNoInicioDuplo("prior");
	this->conectivosProibidos->adicionaNoInicioDuplo("regarding");
	this->conectivosProibidos->adicionaNoInicioDuplo("regardless");
	this->conectivosProibidos->adicionaNoInicioDuplo("save");
	this->conectivosProibidos->adicionaNoInicioDuplo("since");
	this->conectivosProibidos->adicionaNoInicioDuplo("tan");
	this->conectivosProibidos->adicionaNoInicioDuplo("through");
	this->conectivosProibidos->adicionaNoInicioDuplo("till");
	this->conectivosProibidos->adicionaNoInicioDuplo("to");
	this->conectivosProibidos->adicionaNoInicioDuplo("toward");
	this->conectivosProibidos->adicionaNoInicioDuplo("towards");
	this->conectivosProibidos->adicionaNoInicioDuplo("under");
	this->conectivosProibidos->adicionaNoInicioDuplo("underneath");
	this->conectivosProibidos->adicionaNoInicioDuplo("unlike");
	this->conectivosProibidos->adicionaNoInicioDuplo("until");
	this->conectivosProibidos->adicionaNoInicioDuplo("up");
	this->conectivosProibidos->adicionaNoInicioDuplo("upon");
	this->conectivosProibidos->adicionaNoInicioDuplo("versus");
	this->conectivosProibidos->adicionaNoInicioDuplo("via");
	this->conectivosProibidos->adicionaNoInicioDuplo("with");
	this->conectivosProibidos->adicionaNoInicioDuplo("within");
	this->conectivosProibidos->adicionaNoInicioDuplo("without");
}

void RemovedorLexico::criar_lista_pronomes() {
	this->conectivosProibidos->adicionaNoInicioDuplo("I");
	this->conectivosProibidos->adicionaNoInicioDuplo("me");
	this->conectivosProibidos->adicionaNoInicioDuplo("we");
	this->conectivosProibidos->adicionaNoInicioDuplo("us");
	this->conectivosProibidos->adicionaNoInicioDuplo("you");
	this->conectivosProibidos->adicionaNoInicioDuplo("she");
	this->conectivosProibidos->adicionaNoInicioDuplo("her");
	this->conectivosProibidos->adicionaNoInicioDuplo("he");
	this->conectivosProibidos->adicionaNoInicioDuplo("him");
	this->conectivosProibidos->adicionaNoInicioDuplo("it");
	this->conectivosProibidos->adicionaNoInicioDuplo("they");
	this->conectivosProibidos->adicionaNoInicioDuplo("them");
	this->conectivosProibidos->adicionaNoInicioDuplo("what");
	this->conectivosProibidos->adicionaNoInicioDuplo("which");
	this->conectivosProibidos->adicionaNoInicioDuplo("who");
	this->conectivosProibidos->adicionaNoInicioDuplo("whom");
	this->conectivosProibidos->adicionaNoInicioDuplo("whose");
	this->conectivosProibidos->adicionaNoInicioDuplo("whichever");
	this->conectivosProibidos->adicionaNoInicioDuplo("whoever");
	this->conectivosProibidos->adicionaNoInicioDuplo("whomever");
	this->conectivosProibidos->adicionaNoInicioDuplo("this");
	this->conectivosProibidos->adicionaNoInicioDuplo("these");
	this->conectivosProibidos->adicionaNoInicioDuplo("that");
	this->conectivosProibidos->adicionaNoInicioDuplo("those");
	this->conectivosProibidos->adicionaNoInicioDuplo("anybody");
	this->conectivosProibidos->adicionaNoInicioDuplo("anyone");
	this->conectivosProibidos->adicionaNoInicioDuplo("anything");
	this->conectivosProibidos->adicionaNoInicioDuplo("each");
	this->conectivosProibidos->adicionaNoInicioDuplo("either");
	this->conectivosProibidos->adicionaNoInicioDuplo("everybody");
	this->conectivosProibidos->adicionaNoInicioDuplo("everyone");
	this->conectivosProibidos->adicionaNoInicioDuplo("everything");
	this->conectivosProibidos->adicionaNoInicioDuplo("neither");
	this->conectivosProibidos->adicionaNoInicioDuplo("nobody");
	this->conectivosProibidos->adicionaNoInicioDuplo("nothing");
	this->conectivosProibidos->adicionaNoInicioDuplo("one");
	this->conectivosProibidos->adicionaNoInicioDuplo("somebody");
	this->conectivosProibidos->adicionaNoInicioDuplo("someone");
	this->conectivosProibidos->adicionaNoInicioDuplo("something");
	this->conectivosProibidos->adicionaNoInicioDuplo("both");
	this->conectivosProibidos->adicionaNoInicioDuplo("few");
	this->conectivosProibidos->adicionaNoInicioDuplo("many");
	this->conectivosProibidos->adicionaNoInicioDuplo("several");
	this->conectivosProibidos->adicionaNoInicioDuplo("all");
	this->conectivosProibidos->adicionaNoInicioDuplo("any");
	this->conectivosProibidos->adicionaNoInicioDuplo("most");
	this->conectivosProibidos->adicionaNoInicioDuplo("none");
	this->conectivosProibidos->adicionaNoInicioDuplo("some");
	this->conectivosProibidos->adicionaNoInicioDuplo("myself");
	this->conectivosProibidos->adicionaNoInicioDuplo("ourselves");
	this->conectivosProibidos->adicionaNoInicioDuplo("yourself");
	this->conectivosProibidos->adicionaNoInicioDuplo("yourselves");
	this->conectivosProibidos->adicionaNoInicioDuplo("himself");
	this->conectivosProibidos->adicionaNoInicioDuplo("herself");
	this->conectivosProibidos->adicionaNoInicioDuplo("itself");
	this->conectivosProibidos->adicionaNoInicioDuplo("themselves");
	this->conectivosProibidos->adicionaNoInicioDuplo("my");
	this->conectivosProibidos->adicionaNoInicioDuplo("your");
	this->conectivosProibidos->adicionaNoInicioDuplo("his");
	this->conectivosProibidos->adicionaNoInicioDuplo("its");
	this->conectivosProibidos->adicionaNoInicioDuplo("is");
	this->conectivosProibidos->adicionaNoInicioDuplo("our");
	this->conectivosProibidos->adicionaNoInicioDuplo("your");
	this->conectivosProibidos->adicionaNoInicioDuplo("their");
	this->conectivosProibidos->adicionaNoInicioDuplo("mine");
	this->conectivosProibidos->adicionaNoInicioDuplo("yours");
	this->conectivosProibidos->adicionaNoInicioDuplo("his");
	this->conectivosProibidos->adicionaNoInicioDuplo("hers");
	this->conectivosProibidos->adicionaNoInicioDuplo("ours");
	this->conectivosProibidos->adicionaNoInicioDuplo("yours");
	this->conectivosProibidos->adicionaNoInicioDuplo("theirs");
}

#endif /* REMOVEDOR_LEXICO_CPP */
