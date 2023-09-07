#include <windows.h>

#include "Game.h"

#include "Field.h"
#include "Snake.h"
#include "Apple.h"
#include "Poisoned_apple.h"
#include "String.h"

#if defined NULL_P
void game(List* list) {

    Field* palya = new Field();
    Snake snake;
    Apple apple(Pos(27, 5), '@');
    PoisonedApple p_apple(Pos(20, 20), 'X');

    int timer = 0;
    bool win_game = false;
    bool game_exit = false;

    while (!snake.getState()) {
        palya->clearField();

        snake.getInput();
        snake.move(*palya);

        timer++;

        if (!snake.getState())
        {
            palya->setObject(snake.getSnakeHead(), snake.getPos());
            snake.drawTail(*palya);
            palya->setObject(apple.getFruit(), apple.getPos());
            palya->setObject(p_apple.getFruit(), p_apple.getPos());
        }
        if (snake.tailCollision())
        {
            snake.kill();
        }
        if (snake.fruitCollision(apple))
        {
            apple.setNewPos(*palya, snake);
        }
        if (timer == 50) {
            p_apple.setNewPos(*palya, snake);
            timer = 0;
        }
        if (snake.fruitCollision(p_apple)) {}

#if defined _WINDOWS_
        if (GetAsyncKeyState(27)) { game_exit = true; break; }
#endif

        if (snake.win()) { win_game = true; break; }

        palya->drawField();
        std::cout << "Score: " << snake.score() << " Lenght: " << snake.getLength() << std::endl;
        std::cout << "Press ESC to return to the menu\n";

#if defined _WINDOWS_
        Sleep(50);
#endif

        system("cls");
    }

    if (!game_exit) {
        system("cls");
        if (win_game) std::cout << "WIN! SCORE: " << snake.score() << std::endl;
        else std::cout << "GAME OVER! SCORE: " << snake.score() << std::endl;

        String gamer;
        std::cout << "Type your name: ";
        std::cin.clear();
        std::cin >> gamer;
        list->add(gamer, snake.score());
    }

    delete palya;
}
#endif
