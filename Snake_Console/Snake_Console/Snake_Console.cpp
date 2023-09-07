#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>

#include "Game.h"
#include "ScoreList.h"


int main()
{
    setbuf(stdout, 0);
    List* list = new List();

    bool empty = false;
    String exc;

    try {
        list->read_from_file();
    }
    catch (const char* exception) {
        exc = exception;
        empty = true;
    }

    int menu;

    bool exit;

#if defined _WINDOWS_
    exit = false;
#else
    exit = true;
#endif

    while (!exit) {
        cin.clear();
        fflush(stdin);

        std::cout << "1. START\n2. STATISTIC\n3. EXIT\n";
        std::cout << "MODE: ";
        std::cin >> menu;
        if (menu == 1) {
            game(list);
            menu = 0;
        }
        else if (menu == 2) {
            system("cls");
            if (empty && list->first()) {
                std::cout << exc;

#if defined _WINDOWS_
                while (!GetAsyncKeyState(27)) {
                    continue;
                }
#endif

                menu = 0;
            }
            else {
                std::cout << "PLAYER STATISTIC (NAME SCORE) / Step back: ESC\n";
                list->print();

#if defined _WINDOWS_
                while (!GetAsyncKeyState(27)) {
                    continue;
                }
#endif
                menu = 0;
            }
        }
        else if (menu == 3) {
            exit = true;
        }

        try {
            if (menu != 1 && menu != 2 && menu != 3 && menu != 0)
                throw("Wrong menu!");
        }
        catch (const char* str) {
            std::cout << str;

#if defined _WINDOWS_
            while (!GetAsyncKeyState(27)) {
                continue;
            }
#endif
        }
        system("cls");
    }

    try {
        list->write_in_file();
    }
    catch (const  char* kivetel2) {
        std::cout << kivetel2;
    }

    delete list;

    return 0;
}
