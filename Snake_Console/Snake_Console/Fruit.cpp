#include <iostream>

#include "Field.h"
#include "Fruit.h"
#include "Snake.h"

void Fruit::setNewPos(Field& field, Snake& snake) {
    int x = 0;
    int y = 0;

    while ((x == 0 || y == 0) || (x == field.getWidth() || y == field.getHeight())) {
        x = rand() % field.getWidth();
        y = rand() % field.getHeight();
    }

    for (int i = 0; i < snake.getLength(); i++) {
        while ((x == 0 || y == 0) || (x == field.getWidth() || y == field.getHeight()) || x == snake.getTail_x(i) || y == snake.getTail_y(i)) {
            x = rand() % field.getWidth();
            y = rand() % field.getHeight();
        }
    }

    pos.x = x;
    pos.y = y;
}
