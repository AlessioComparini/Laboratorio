//
// Created by aleal on 05/09/2021.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H
#define LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H

#include <iostream>
#include "TodoList.h"

class ListOfLists {
public:
    void addList (TodoList l);
    void removeList (TodoList t);
    void moveList (TodoList source,TodoList destination, Activity a );
    void printLists ();
    TodoList getList (std::string n);
    int getSize();
    bool findList(std::string n);
private:
    std::list<TodoList> lists;
};


#endif //LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H