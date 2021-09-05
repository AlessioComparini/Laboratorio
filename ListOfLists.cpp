//
// Created by aleal on 05/09/2021.
//

#include "ListOfLists.h"
#include <iostream>

void ListOfLists::addList(TodoList l) {
    lists.push_back(l);
}


void ListOfLists::removeList(TodoList t) {
    lists.remove(t);
}

void ListOfLists::moveList(TodoList source, TodoList destination, Activity a) {
    destination.addActivity(a);
    source.removeActivity(a);
}

void ListOfLists::printLists() {
    for (const auto it : lists)
        std::cout<< it.getName() << std::endl;
}

TodoList ListOfLists::getList(std::string n) {
    for (const auto it : lists){
        if (it.getName()== n)
            return it;
    }
}

int ListOfLists::getSize() {
    return lists.size();
}

bool ListOfLists::findList(std::string n) {
    for (const auto it : lists){
        if (it.getName()== n)
            return true;
    }
    return false;
}