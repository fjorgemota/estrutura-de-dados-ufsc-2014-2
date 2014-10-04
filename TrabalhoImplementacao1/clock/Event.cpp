/* 
 * File:   Evento.cpp
 * Author: fernando
 * 
 * Created on 2 de Outubro de 2014, 23:27
 */
#ifndef EVENT_CPP
#define	EVENT_CPP
#include "Event.hpp"

Event::Event(int time, int type, char* description) {
    this->time = time;
    this->type = type;
    this->description = description;
}

Event::Event(int time, int type) {
    this->time = time;
    this->type = type;
    this->description = (char*) "Without description";
}

Event::Event(int type, char* description) {
    this->time = -1;
    this->type = type;
    this->description = description;
}

Event::Event(char* description) {
    this->time = -1;
    this->type = EVENT_LOG;
    this->description = description;
}

int Event::getTime() {
    return this->time;
}

void Event::setTime(int time) {
    this->time = time;
}

int Event::getType() {
    return this->type;
}

char* Event::getDescription() {
    return this->description;
}
#endif
