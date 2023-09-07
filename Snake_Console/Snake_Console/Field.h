#ifndef FIELD_H
#define FIELD_H

#include "Position.h"

class Field {
    int Height;
    int Width;
    char** field;
public:
    Field();
    void drawField();
    void setObject(char ch, const Pos& p);
    void clearField();
    int getHeight() { return Height; }
    int getWidth() { return Width; }
    char getField(int x, int y);
    ~Field();
};

#endif // FIELD_H
