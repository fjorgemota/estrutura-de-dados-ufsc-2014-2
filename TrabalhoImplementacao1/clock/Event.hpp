// Copyright 2014 Caique Rodrigues Marques e Fernando Jorge Mota

#ifndef EVENTO_HPP
#define EVENTO_HPP

#define EVENT_FUTURE 1
#define EVENT_LOG 2
class Event {
 private:
    int time;
    int type;
    char *description;
 public:
    Event(int time, int type, char *description);
    Event(int time, int type);
    Event(int time, char *description);
    explicit Event(char *description);
    int getTime();
    void setTime(int time);
    int getType();
    virtual char* getDescription();
};

#endif /* EVENTO_HPP */
