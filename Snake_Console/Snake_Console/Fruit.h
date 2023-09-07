#ifndef FRUIT_H
#define FRUIT_H

class Snake;

class Fruit {
    Pos pos;
    char fruit;
public:
    Fruit(const Pos& pos, char fruit) :pos(pos), fruit(fruit) {};
    void setNewPos(Field& field, Snake& snake);
    Pos& getPos() { return pos; }
    char getFruit() { return fruit; }
    virtual void eatenBySnake(Snake* s) {};
};

#endif // FRUIT_H
