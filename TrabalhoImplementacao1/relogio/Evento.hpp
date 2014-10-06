// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef EVENTO_HPP
#define EVENTO_HPP

#define EVENTO_FUTURO 1
#define EVENTO_LOG 2
class Evento {
 private:
    int hora;
    int tipo;
    char *descricao;
 public:
    Evento(int hora, int tipo, char *descricao);
    Evento(int hora, int tipo);
    Evento(int hora, char *descricao);
    explicit Evento(char *descricao);
    virtual ~Evento();
    int pegaHora();
    void configuraHora(int hora);
    int pegaTipo();
    virtual char* pegaDescricao();
};

#endif /* EVENTO_HPP */
