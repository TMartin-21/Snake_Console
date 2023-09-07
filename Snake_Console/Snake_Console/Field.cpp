#include <iostream>
#include <fstream>

#include "Field.h"

Field::Field() :Height(0), Width(0) {
    std::ifstream file;
    char ch;

    file.open("map.txt");

    if (file.fail()) {
        throw("Error! File cannot be opened/File does not exist.");
    }
    else {
        int fieldArea = 0;
        while (!file.eof()) {
            file.get(ch);
            if (ch == '\n' || file.peek() == -1) {
                Height++;
            }
            fieldArea++;
        }
        Width = fieldArea / Height;
        file.close();
    }

    file.open("map.txt");

    if (file.fail()) {
        throw("Error! File cannot be opened/File does not exist.");
    }
    else {
        field = new char* [Height];
        int y = 0;
        int x = 0;
        while (!file.eof())
        {
            field[y] = new char[Width];
            while (file.get(ch) && ch != '\n')
            {
                field[y][x++] = ch;
            }
            y++;
            x = 0;
        }
        file.close();
    }
}

void Field::drawField() {
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            std::cout << field[y][x];
        }
        std::cout << std::endl;
    }
}

void Field::setObject(char ch, const Pos& p) {
    if (p.x >= Width || p.y >= Height)
        throw("Error");
    field[p.y][p.x] = ch;
}

void Field::clearField() {
    for (int y = 1; y < Height - 1; y++)
    {
        for (int x = 1; x < Width - 1; x++)
        {
            field[y][x] = ' ';
        }
    }
}

char Field::getField(int x, int y) {
    if (x >= Width || y >= Height)
        throw("Error");
    return field[y][x];
}

Field::~Field() {
    for (int y = 0; y < Height; y++)
    {
        delete[] field[y];
    }
    delete[] field;
}
