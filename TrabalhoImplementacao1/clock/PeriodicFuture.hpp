// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef PERIODICEVENT_HPP
#define PERIODICEVENT_HPP

#include "Future.cpp"

class PeriodicFuture : public Future {
 public:
    PeriodicFuture(int interval, char* description);
    explicit PeriodicFuture(int interval);
    virtual bool canRun(int now);
    virtual bool canRemove();
};

#endif /* PERIODICEVENT_HPP */
