#include <windows.h>

#include "Snake.h"

void Snake::dir(int x, int y) {
    speed = Pos(x, y);
}

void Snake::getInput() {
#if defined _WINDOWS_
    if (GetAsyncKeyState(VK_UP) && speed != Pos(0, 1)) {
        dir(0, -1);
    }
    else if (GetAsyncKeyState(VK_LEFT) && speed != Pos(1, 0)) {
        dir(-1, 0);
    }
    else if (GetAsyncKeyState(VK_DOWN) && speed != Pos(0, -1)) {
        dir(0, 1);
    }
    else if (GetAsyncKeyState(VK_RIGHT) && speed != Pos(-1, 0)) {
        dir(1, 0);
    }
#endif
}

void Snake::move(Field& field) {
    for (int i = 0; i < length - 1; i++)
    {
        tail[i] = tail[i + 1];
    }
    tail[length - 1] = head;
    head += speed;
    if (wallCollision(field)) {
        this->kill();
    }
}

bool Snake::wallCollision(Field& field) {
    if (head.x < 1 || head.y < 1 || head.y >= field.getHeight() - 1 || head.x >= field.getWidth() - 1) {
        return true;
    }
    return false;
}

void Snake::drawTail(Field& field) {
    for (int i = 0; i < length; i++)
    {
        field.setObject(sn, tail[i]);
    }
}

bool Snake::fruitCollision(Fruit& fruit) {
    if (head.x == fruit.getPos().x && head.y == fruit.getPos().y)
    {
        eat(fruit);
        return true;
    }
    return false;
}

void Snake::eat(Fruit& fruit) {
    fruit.eatenBySnake(this);
}

void Snake::grow(int n) {
    length += n;
}

bool Snake::tailCollision() {
    for (int i = 0; i < length - 1; i++) {
        if (tail[i] == head)
            return true;
    }
    return false;
}

bool Snake::win() {
    if (length == MAX_LENGTH)
        return true;
    return false;
}
