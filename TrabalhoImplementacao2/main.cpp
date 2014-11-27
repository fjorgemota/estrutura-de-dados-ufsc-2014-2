#include "programa/Programa.hpp"


int main(int argc, char **argv) {
	Programa *programa = new Programa(new string("manpages.dat"), new string("manwords.dat"));

	return programa->executa(argc, argv);
}