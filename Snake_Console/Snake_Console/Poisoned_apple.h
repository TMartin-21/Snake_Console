#ifndef POISONED_APPLE_H
#define POISONED_APPLE_H

#include "Fruit.h"
#include "Position.h"
#include "Snake.h"

class PoisonedApple : public Fruit {
public:
    PoisonedApple(const Pos& pos, char fruit) :Fruit(pos, fruit) {};

    void eatenBySnake(Snake* s) {
        s->kill();
    }
};

#endif // POISONED_APPLE_H
