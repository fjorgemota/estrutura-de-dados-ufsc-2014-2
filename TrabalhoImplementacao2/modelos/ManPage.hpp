#ifndef MAN_PAGE_HPP
#define MAN_PAGE_HPP

class ManPage {
 public:
	char comando[512];
	char conteudo[1024576];

 	bool operator < (const ManPage& manpage)const;

 	bool operator > (const ManPage& manpage) const;
};

#include "ManPage.cpp"

#endif /** MAN_PAGE_HPP */