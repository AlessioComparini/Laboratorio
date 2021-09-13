//
// Created by aleal on 05/09/2021.
//

#include "ListOfLists.h"
#include <iostream>

void ListOfLists::addList(const TodoList &l) {
    lists.push_back(l);
}


void ListOfLists::removeList(TodoList &t) {
    lists.remove(t);
}

void ListOfLists::moveList(std::string &source, std::string &destination,Activity &a) {
    addActivityToList(destination,a);
    removeActivityFromList(source,a);
}

void ListOfLists::printLists() const {
    for (const auto it : lists)
        std::cout<< it.getName() << std::endl;
}

TodoList ListOfLists::getList(std::string &n) const {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==n){
            return (*it);
        }
        it++;
    }
}
TodoList ListOfLists::getList(int pos) const {
    auto it=lists.begin();
    for (int i = 0; i<pos;i++)
        it++;
    return *it;
    }


int ListOfLists::getSize() const {
    return lists.size();
}

bool ListOfLists::findList(std::string &n) const {
    for (const auto it : lists){
        if (it.getName()== n)
            return true;
    }
    return false;
}

void ListOfLists::removeActivityFromList(std::string &name, Activity &a) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).removeActivity(a);
        }
        it++;
    }
}

void ListOfLists::removeActivityFromList(std::string &name, int activityPos) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).removeActivity(activityPos);
            }
        it++;
    }


}

void ListOfLists::addActivityToList(std::string &name, const Activity &a) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).addActivity(a);
        }
        it++;
    }
}

void ListOfLists::setActivityDone(std::string &name, int activityPos) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).setActivityDone(activityPos);
        }
        it++;
    }
}
