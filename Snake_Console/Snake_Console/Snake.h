#ifndef SNAKE_H
#define SNAKE_H

#include "Field.h"
#include "Position.h"
#include "Fruit.h"

class Snake {
    static const int MAX_LENGTH = 25;
    Pos tail[MAX_LENGTH];
    Pos head;
    Pos speed;
    int length;
    bool dead;
    char sn;
public:
    Snake(int x = 10, int y = 10) :head(x, y), speed(1, 0), length(1), dead(false), sn('O') { tail[0] = Pos(9, 10); }
    void dir(int x, int y);
    void getInput();
    void move(Field& field);
    bool wallCollision(Field& field);
    void drawTail(Field& field);
    bool fruitCollision(Fruit& fruit);
    void eat(Fruit& fruit);
    void grow(int n);
    void kill() { dead = true; }
    Pos& getPos() { return head; }
    Pos& getTailPos() { return tail[length]; }
    char getSnakeHead() { return sn; }
    bool getState() { return dead; }
    int getLength() { return length; }
    int score() { return (length - 1) * 10; }

    int getTail_x(int indx) {
        if (indx >= length || indx < 0)
            throw("Out of bound error");
        return tail[indx].x;
    }

    int getTail_y(int indx) {
        if (indx >= length || indx < 0)
            throw("Out of bound error");
        return tail[indx].y;
    }

    bool tailCollision();
    bool win();
};

#endif // SNAKE_H
