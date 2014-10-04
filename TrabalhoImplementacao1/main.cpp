// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef MAIN_CPP
#define MAIN_CPP
#include <cstdlib>
#include <cstdio>
#include "clock/Clock.cpp"
#include "clock/PeriodicFuture.cpp"

class Hi : public PeriodicFuture {
 private:
    Clock *clock;
 public:
    explicit Hi(Clock *clock):PeriodicFuture(1, const_cast<char*>("Hi Loop")) {
        this->clock = clock;
    }

    virtual void run() {
        printf("Hey\n");
        this->clock->add(new Event(const_cast<char*>("Said 'hey'")));
    }
};

class Bye : public Future {
 private:
    Clock *clock;
 public:
    explicit Bye(Clock *clock) : Future(5, const_cast<char*>("Bye Future")) {
        this->clock = clock;
    }

    virtual void run() {
        printf("Bye\n");
        this->clock->listFutures();
        this->clock->listHistoric();
    }
};

int main(int argc, char** argv) {
    Clock clock = Clock();
    clock.schedule(new Hi(&clock));
    clock.schedule(new Bye(&clock));
    clock.run();
    return 0;
}
#endif
