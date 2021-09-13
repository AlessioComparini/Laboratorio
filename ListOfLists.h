//
// Created by aleal on 05/09/2021.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H
#define LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H

#include <iostream>
#include "TodoList.h"

class ListOfLists {
public:
    void addList (const TodoList &l);
    void removeList (TodoList &t);
    void moveList (std::string &source,std::string &destination, Activity &a );
    void printLists () const;
    TodoList getList (std::string &n) const;
    TodoList getList (int n) const;
    int getSize() const;
    bool findList(std::string &n) const;
    void addActivityToList (std::string &name, const Activity &a);
    void removeActivityFromList (std::string &name, Activity &a);
    void removeActivityFromList (std::string &name, int activityPos);
    void setActivityDone (std::string &name, int activityPos);
private:
    std::list<TodoList> lists;
};


#endif //LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H
