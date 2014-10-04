/* 
 * File:   main.cpp
 * Author: fernando
 *
 * Created on 4 de Outubro de 2014, 00:20
 */

#include <cstdlib>
#include <stdio.h>
#include "clock/Clock.cpp"
#include "clock/PeriodicFuture.cpp"

using namespace std;

class Hi : public PeriodicFuture {
private:
    Clock *clock;
public:    
    Hi(Clock *clock) : PeriodicFuture(1) { 
        this->clock = clock;
    };
    virtual char* getDescription() {
        return (char *) "Test";
    }

    virtual void run() {
        printf("Hey\n");
        this->clock->add(new Event((char*)"Said 'hey'"));
    }

};

class Bye : public Future {
private:
    Clock *clock;
public:
    Bye(Clock *clock) : Future(5) {
        this->clock = clock;
    };
    virtual char* getDescription() {
        return (char *) "Test 2";
    }

    virtual void run() {
        printf("Bye\n");
        this->clock->list();
    }

};
/*
 * 
 */
int main(int argc, char** argv) {
    Clock clock = Clock();
    clock.schedule(new Hi(&clock));
    clock.schedule(new Bye(&clock));
    clock.run();
    return 0;
}

