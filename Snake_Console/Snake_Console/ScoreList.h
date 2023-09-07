#ifndef DICSOSEGLISTA_H
#define DICSOSEGLISTA_H

#include "String.h"

#define NULL_P

struct ListItem {
    int score;
    String name;
    ListItem* next;

    ListItem() { this->score = 0; }
};

class List {
    ListItem* list;
public:
#if defined NULL_P
    List() { list = 0; }
    void add(String& name, int _score);
    void print();
    void read_from_file();
    void write_in_file();
    bool first();
    ListItem* getList() { return list; }
    const char* getName() { return list->name.c_str(); }
    int getScore() { return list->score; }

    ~List();
#endif // defined
};

#endif // DICSOSEGLISTA_H
