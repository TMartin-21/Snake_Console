#include <fstream>

#include "ScoreList.h"

#if defined NULL_P
void List::add(String& name, int _score) {
    ListItem* moving = list;
    ListItem* lagging = 0;

    ListItem* newItem = new ListItem();
    newItem->name = name;
    newItem->score = _score;
    newItem->next = list;

    while (moving != 0 && moving->score > _score) {
        lagging = moving;
        moving = moving->next;
    }
    if (lagging == 0) {
        newItem->next = list;
        list = newItem;
    }
    else {
        lagging->next = newItem;
        newItem->next = moving;
    }
}

void List::print() {
    if (list == 0)
        return;
    ListItem* moving;
    for (moving = list; moving != 0; moving = moving->next)
        std::cout << moving->name << " " << moving->score << "\n";
}

void List::read_from_file() {
    std::ifstream in;
    in.open("ScoreList.txt");

    if (in.fail()) {
        throw("List is empty!\n");
    }
    else {
        String name;
        int score;
        while (!in.eof()) {
            in >> name >> score;
            this->add(name, score);
        }
        in.close();
    }
}

void List::write_in_file() {
    std::ofstream out;
    out.open("ScoreList.txt");

    if (out.fail() || list == NULL) {
        throw("Failed to write to file!\n");
    }
    else {
        ListItem* moving;
        for (moving = list; moving->next != 0; moving = moving->next) {
            out << moving->name << " " << moving->score << std::endl;
        }
        out << moving->name << " " << moving->score;
        out.close();
    }
}

bool List::first() {
    if (list == 0)
        return true;
    return false;
}

List::~List() {
    while (list != 0) {
        ListItem* temp = list->next;
        delete list;
        list = temp;
    }
}
#endif // defined
