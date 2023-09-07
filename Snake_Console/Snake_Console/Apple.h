#ifndef APPLE_H
#define APPLE_H

#include "Fruit.h"
#include "Position.h"
#include "Snake.h"

class Apple : public Fruit {
public:
    Apple(const Pos& pos, char fruit) :Fruit(pos, fruit) {};

    void eatenBySnake(Snake* s) {
        s->grow(1);
    }
};

#endif // APPLE_H
