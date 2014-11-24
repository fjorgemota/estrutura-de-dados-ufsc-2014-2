#ifdef REMOVEDOR_LEXICO_CPP
#define REMOVEDOR_LEXICO_CPP
#include "RemovedorLexico.hpp"

using namespace std;

RemovedorLexico::RemovedorLexico() {
	this->conectivosProibidos = new ListaDupla<string>();
}

string RemovedorLexico::remover_conectivo_unica_palavra(string palavra) {
	if (palavra.size() > 2 && !(conectivosProibidos.contemDuplo(palavra))) {
		return palavra;
	}
	return "";
}

vector<string> RemovedorLexico::separar_em_palavras(string busca) {
	vector<string> termos;
	string temp;
	stringstream stream(busca);
	while (stream >> temp) {
		termos.push_back(temp);
	}
		
	return termos;
}

void RemovedorLexico::criar_lista_conectivos_artigos() {
	conectivosProibidos.adicionaNoInicioDuplo("a");
	conectivosProibidos.adicionaNoInicioDuplo("an");
	conectivosProibidos.adicionaNoInicioDuplo("the");
	conectivosProibidos.adicionaNoInicioDuplo("no");
}

void RemovedorLexico::criar_lista_conectivos_conjuncoes() {
	conectivosProibidos.adicionaNoInicioDuplo("for");
	conectivosProibidos.adicionaNoInicioDuplo("and");
	conectivosProibidos.adicionaNoInicioDuplo("nor");
	conectivosProibidos.adicionaNoInicioDuplo("but");
	conectivosProibidos.adicionaNoInicioDuplo("or");
	conectivosProibidos.adicionaNoInicioDuplo("yet");
	conectivosProibidos.adicionaNoInicioDuplo("so");
}

void RemovedorLexico::criar_lista_conectivos_preposicoes() {
	conectivosProibidos.adicionaNoInicioDuplo("aboard");
	conectivosProibidos.adicionaNoInicioDuplo("about");
	conectivosProibidos.adicionaNoInicioDuplo("above");
	conectivosProibidos.adicionaNoInicioDuplo("across");
	conectivosProibidos.adicionaNoInicioDuplo("after");
	conectivosProibidos.adicionaNoInicioDuplo("against");
	conectivosProibidos.adicionaNoInicioDuplo("ahead");
	conectivosProibidos.adicionaNoInicioDuplo("along");
	conectivosProibidos.adicionaNoInicioDuplo("amid");
	conectivosProibidos.adicionaNoInicioDuplo("amidst");
	conectivosProibidos.adicionaNoInicioDuplo("among");
	conectivosProibidos.adicionaNoInicioDuplo("around");
	conectivosProibidos.adicionaNoInicioDuplo("as");
	conectivosProibidos.adicionaNoInicioDuplo("aside");
	conectivosProibidos.adicionaNoInicioDuplo("at");
	conectivosProibidos.adicionaNoInicioDuplo("athwart");
	conectivosProibidos.adicionaNoInicioDuplo("atop");
	conectivosProibidos.adicionaNoInicioDuplo("barring");
	conectivosProibidos.adicionaNoInicioDuplo("because");
	conectivosProibidos.adicionaNoInicioDuplo("before");
	conectivosProibidos.adicionaNoInicioDuplo("behind");
	conectivosProibidos.adicionaNoInicioDuplo("below");
	conectivosProibidos.adicionaNoInicioDuplo("beneath");
	conectivosProibidos.adicionaNoInicioDuplo("beside");
	conectivosProibidos.adicionaNoInicioDuplo("besides");
	conectivosProibidos.adicionaNoInicioDuplo("between");
	conectivosProibidos.adicionaNoInicioDuplo("beyond");
	conectivosProibidos.adicionaNoInicioDuplo("but");
	conectivosProibidos.adicionaNoInicioDuplo("by");
	conectivosProibidos.adicionaNoInicioDuplo("circa");
	conectivosProibidos.adicionaNoInicioDuplo("concerning");
	conectivosProibidos.adicionaNoInicioDuplo("despite");
	conectivosProibidos.adicionaNoInicioDuplo("down");
	conectivosProibidos.adicionaNoInicioDuplo("during");
	conectivosProibidos.adicionaNoInicioDuplo("except");
	conectivosProibidos.adicionaNoInicioDuplo("excluding");
	conectivosProibidos.adicionaNoInicioDuplo("following");
	conectivosProibidos.adicionaNoInicioDuplo("for");
	conectivosProibidos.adicionaNoInicioDuplo("from");
	conectivosProibidos.adicionaNoInicioDuplo("in");
	conectivosProibidos.adicionaNoInicioDuplo("including");
	conectivosProibidos.adicionaNoInicioDuplo("inside");
	conectivosProibidos.adicionaNoInicioDuplo("instead");
	conectivosProibidos.adicionaNoInicioDuplo("into");
	conectivosProibidos.adicionaNoInicioDuplo("like");
	conectivosProibidos.adicionaNoInicioDuplo("minus");
	conectivosProibidos.adicionaNoInicioDuplo("near");
	conectivosProibidos.adicionaNoInicioDuplo("of");
	conectivosProibidos.adicionaNoInicioDuplo("off");
	conectivosProibidos.adicionaNoInicioDuplo("on");
	conectivosProibidos.adicionaNoInicioDuplo("onto");
	conectivosProibidos.adicionaNoInicioDuplo("opposite");
	conectivosProibidos.adicionaNoInicioDuplo("out");
	conectivosProibidos.adicionaNoInicioDuplo("outside");
	conectivosProibidos.adicionaNoInicioDuplo("over");
	conectivosProibidos.adicionaNoInicioDuplo("past");
	conectivosProibidos.adicionaNoInicioDuplo("plus");
	conectivosProibidos.adicionaNoInicioDuplo("prior");
	conectivosProibidos.adicionaNoInicioDuplo("regarding");
	conectivosProibidos.adicionaNoInicioDuplo("regardless");
	conectivosProibidos.adicionaNoInicioDuplo("save");
	conectivosProibidos.adicionaNoInicioDuplo("since");
	conectivosProibidos.adicionaNoInicioDuplo("tan");
	conectivosProibidos.adicionaNoInicioDuplo("through");
	conectivosProibidos.adicionaNoInicioDuplo("till");
	conectivosProibidos.adicionaNoInicioDuplo("to");
	conectivosProibidos.adicionaNoInicioDuplo("toward");
	conectivosProibidos.adicionaNoInicioDuplo("towards");
	conectivosProibidos.adicionaNoInicioDuplo("under");
	conectivosProibidos.adicionaNoInicioDuplo("underneath");
	conectivosProibidos.adicionaNoInicioDuplo("unlike");
	conectivosProibidos.adicionaNoInicioDuplo("until");
	conectivosProibidos.adicionaNoInicioDuplo("up");
	conectivosProibidos.adicionaNoInicioDuplo("upon");
	conectivosProibidos.adicionaNoInicioDuplo("versus");
	conectivosProibidos.adicionaNoInicioDuplo("via");
	conectivosProibidos.adicionaNoInicioDuplo("with");
	conectivosProibidos.adicionaNoInicioDuplo("within");
	conectivosProibidos.adicionaNoInicioDuplo("without");
}

void RemovedorLexico::criar_lista_conectivos_pronomes() {
	conectivosProibidos.adicionaNoInicioDuplo("I");
	conectivosProibidos.adicionaNoInicioDuplo("me");
	conectivosProibidos.adicionaNoInicioDuplo("we");
	conectivosProibidos.adicionaNoInicioDuplo("us");
	conectivosProibidos.adicionaNoInicioDuplo("you");
	conectivosProibidos.adicionaNoInicioDuplo("she");
	conectivosProibidos.adicionaNoInicioDuplo("her");
	conectivosProibidos.adicionaNoInicioDuplo("he");
	conectivosProibidos.adicionaNoInicioDuplo("him");
	conectivosProibidos.adicionaNoInicioDuplo("it");
	conectivosProibidos.adicionaNoInicioDuplo("they");
	conectivosProibidos.adicionaNoInicioDuplo("them");
	conectivosProibidos.adicionaNoInicioDuplo("what");
	conectivosProibidos.adicionaNoInicioDuplo("which");
	conectivosProibidos.adicionaNoInicioDuplo("who");
	conectivosProibidos.adicionaNoInicioDuplo("whom");
	conectivosProibidos.adicionaNoInicioDuplo("whose");
	conectivosProibidos.adicionaNoInicioDuplo("whichever");
	conectivosProibidos.adicionaNoInicioDuplo("whoever");
	conectivosProibidos.adicionaNoInicioDuplo("whomever");
	conectivosProibidos.adicionaNoInicioDuplo("this");
	conectivosProibidos.adicionaNoInicioDuplo("these");
	conectivosProibidos.adicionaNoInicioDuplo("that");
	conectivosProibidos.adicionaNoInicioDuplo("those");
	conectivosProibidos.adicionaNoInicioDuplo("anybody");
	conectivosProibidos.adicionaNoInicioDuplo("anyone");
	conectivosProibidos.adicionaNoInicioDuplo("anything");
	conectivosProibidos.adicionaNoInicioDuplo("each");
	conectivosProibidos.adicionaNoInicioDuplo("either");
	conectivosProibidos.adicionaNoInicioDuplo("everybody");
	conectivosProibidos.adicionaNoInicioDuplo("everyone");
	conectivosProibidos.adicionaNoInicioDuplo("everything");
	conectivosProibidos.adicionaNoInicioDuplo("neither");
	conectivosProibidos.adicionaNoInicioDuplo("nobody");
	conectivosProibidos.adicionaNoInicioDuplo("nothing");
	conectivosProibidos.adicionaNoInicioDuplo("one");
	conectivosProibidos.adicionaNoInicioDuplo("somebody");
	conectivosProibidos.adicionaNoInicioDuplo("someone");
	conectivosProibidos.adicionaNoInicioDuplo("something");
	conectivosProibidos.adicionaNoInicioDuplo("both");
	conectivosProibidos.adicionaNoInicioDuplo("few");
	conectivosProibidos.adicionaNoInicioDuplo("many");
	conectivosProibidos.adicionaNoInicioDuplo("several");
	conectivosProibidos.adicionaNoInicioDuplo("all");
	conectivosProibidos.adicionaNoInicioDuplo("any");
	conectivosProibidos.adicionaNoInicioDuplo("most");
	conectivosProibidos.adicionaNoInicioDuplo("none");
	conectivosProibidos.adicionaNoInicioDuplo("some");
	conectivosProibidos.adicionaNoInicioDuplo("myself");
	conectivosProibidos.adicionaNoInicioDuplo("ourselves");
	conectivosProibidos.adicionaNoInicioDuplo("yourself");
	conectivosProibidos.adicionaNoInicioDuplo("yourselves");
	conectivosProibidos.adicionaNoInicioDuplo("himself");
	conectivosProibidos.adicionaNoInicioDuplo("herself");
	conectivosProibidos.adicionaNoInicioDuplo("itself");
	conectivosProibidos.adicionaNoInicioDuplo("themselves");
	conectivosProibidos.adicionaNoInicioDuplo("my");
	conectivosProibidos.adicionaNoInicioDuplo("your");
	conectivosProibidos.adicionaNoInicioDuplo("his");
	conectivosProibidos.adicionaNoInicioDuplo("its");
	conectivosProibidos.adicionaNoInicioDuplo("is");
	conectivosProibidos.adicionaNoInicioDuplo("our");
	conectivosProibidos.adicionaNoInicioDuplo("your");
	conectivosProibidos.adicionaNoInicioDuplo("their");
	conectivosProibidos.adicionaNoInicioDuplo("mine");
	conectivosProibidos.adicionaNoInicioDuplo("yours");
	conectivosProibidos.adicionaNoInicioDuplo("his");
	conectivosProibidos.adicionaNoInicioDuplo("hers");
	conectivosProibidos.adicionaNoInicioDuplo("ours");
	conectivosProibidos.adicionaNoInicioDuplo("yours");
	conectivosProibidos.adicionaNoInicioDuplo("theirs");
}

#endif /* REMOVEDOR_LEXICO_CPP */
