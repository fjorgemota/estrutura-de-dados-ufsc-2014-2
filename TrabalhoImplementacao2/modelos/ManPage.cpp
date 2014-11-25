#ifndef MAN_PAGE_CPP
#define MAN_PAGE_CPP

bool ManPage::operator < (const ManPage& manpage) const {
	return *(this->conteudo) > *(manpage.conteudo);
}

bool ManPage::operator > (const ManPage& manpage) const {
	return *(this->conteudo) < *(manpage.conteudo);
}

#endif /** MAN_PAGE_CPP */