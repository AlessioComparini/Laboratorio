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
    void moveList (const std::string &source,const std::string &destination, Activity &a );
    void printLists () const;
    TodoList getList (std::string &n) const;
    TodoList getList (int n) const;
    int getSize() const;
    bool findList(const std::string &n) const;
    void addActivityToList (const std::string &name, const Activity &a);
    void removeActivityFromList (const std::string &name, Activity &a);
    void removeActivityFromList (const std::string &name, int activityPos);
    void setActivityDone (const std::string &name, int activityPos);
private:
    std::list<TodoList> lists;
};


#endif //LABORATORIODIPROGRAMMAZIONE_LISTOFLISTS_H
