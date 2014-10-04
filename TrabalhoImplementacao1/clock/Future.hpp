// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef FUTURE_HPP
#define FUTURE_HPP

#include "Event.cpp"
#include "Callback.hpp"

class Future: public Event, public Callback {
 private:
     bool remove;
 public:
    Future(int interval, char *description);
    explicit Future(int interval);
    virtual bool canRun(int now);
    virtual bool canRemove();
};

#endif /* FUTURE_HPP */
