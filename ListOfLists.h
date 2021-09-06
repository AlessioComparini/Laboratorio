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
    void moveList (std::string source,std::string destination, Activity a );
    void printLists ();
    TodoList getList (std::string n);
    TodoList getList (int n);
    int getSize();
    bool findList(std::string n);
    void addActivityToList (std::string name, Activity a);
    void removeActivityFromList (std::string name, Activity a);
    void removeActivityFromList (std::string name, int activityPos);
    void setActivityDone (std::string name, int activityPos);
private:
    std::list<TodoList> lists;
};


#endif //LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H
