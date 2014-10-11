// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef NUMERO_ALEATORIO_HPP
#define NUMERO_ALEATORIO_HPP
#include <cstdlib>
#include <ctime>
#define INICIALIZA_NUMEROS_ALEATORIOS() srand(time(NULL))
#define SORTEIA(min, max) static_cast<int>(min + (rand() % (1+(max-min))))

#endif
