#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Pos {
public:
    int x;
    int y;
    Pos(int x = 0, int y = 0) :x(x), y(y) {};
    void copyPos(const Pos& p) {
        x = p.x;
        y = p.y;
    }

    Pos& operator+=(const Pos& p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    bool operator!=(Pos pos) {
        if (this->x != pos.x && this->y != pos.y)
            return true;
        return false;
    }

    bool operator==(Pos pos) {
        if (this->x == pos.x && this->y == pos.y)
            return true;
        return false;
    }
};

#endif // POSITION_H
