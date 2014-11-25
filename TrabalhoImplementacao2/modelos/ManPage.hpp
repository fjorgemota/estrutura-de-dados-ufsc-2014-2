#ifndef MAN_PAGE_HPP
#define MAN_PAGE_HPP

#include <string>

using std::string;

class ManPage {
 public:
	string *comando;
	string *conteudo;

 	bool operator < (const ManPage& manpage)const;

 	bool operator > (const ManPage& manpage) const;
};

#include "ManPage.cpp"

#endif /** MAN_PAGE_HPP */