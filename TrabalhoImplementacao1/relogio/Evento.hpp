// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>

#define EVENTO_FUTURO 1
#define EVENTO_LOG 2
#define EVENTO_TROCA_ESTADO_SEMAFORO 3
#define EVENTO_TROCA_PISTA 4
#define EVENTO_CARRO_ENTRA_PISTA 5
#define EVENTO_CARRO_CHEGA_SEMAFORO 6

using std::string;

/*
 * Classe que cria os momentos apresentados durante a simulação do tráfego
 */
class Evento {
 private:
    int segundo;  //!< Segundo que representa a passagem do tempo do evento
    int tipo;  //!< Define o tipo do evento
    string descricao;  //!< Descrição do evento gravado

 public:
    /*
     * Constrói um evento
     *
     * @param segundo Os segundos que durarão o evento
     * @param tipo O tipo de evento a ser marcado
     * @param descricao A descrição do evento
     */
    Evento(int segundo, int tipo, string descricao);

    /*
     * Constrói um evento
     *
     * @param segundo Os segundos que durarão o evento
     * @param tipo O tipo de evento a ser marcado
     */
    Evento(int segundo, int tipo);

    /*
     * Constrói um evento
     *
     * @param segundo Os segundos que durarão o evento
     * @param descricao A descrição do evento
     */
    Evento(int segundo, string descricao);

    /*
     * Constrói um evento
     *
     * @param descricao A descrição do evento
     */
    explicit Evento(string descricao);

    /*
     * Destrói o evento
     */
    virtual ~Evento();

    /*
     * Retorna os segundos que compõem o evento
     */
    int pegaSegundo();

    /*
     * Ajusta os segundos da duração do evento
     *
     * @param segundo Os segundos que derará o evento
     */
    void configuraSegundo(int segundo);

    /*
     * Retorna o tipo em que o evento se classifica
     */
    int pegaTipo();

    /*
     * Retorna a descrição do evento
     */
    virtual string pegaDescricao();
};

#endif /* EVENTO_HPP */
