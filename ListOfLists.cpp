//
// Created by aleal on 05/09/2021.
//

#include "ListOfLists.h"
#include <iostream>

void ListOfLists::addList(const TodoList &l) {
    lists.push_back(l);
}


void ListOfLists::removeList(const TodoList &t) {
    lists.remove(t);
}

void ListOfLists::moveList(const std::string &source, const std::string &destination,const Activity &a) {
    addActivityToList(destination,a);
    removeActivityFromList(source,a);
}

void ListOfLists::printLists() const {
    for (const auto it : lists)
        std::cout<< it.getName() << std::endl;
}

TodoList ListOfLists::getList(const std::string &n) const {
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

bool ListOfLists::findList(const std::string &n) const {
    for (const auto it : lists){
        if (it.getName()== n)
            return true;
    }
    return false;
}

void ListOfLists::removeActivityFromList(const std::string &name, const Activity &a) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).removeActivity(a);
        }
        it++;
    }
}

void ListOfLists::removeActivityFromList(const std::string &name, int activityPos) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).removeActivity(activityPos);
            }
        it++;
    }


}

void ListOfLists::addActivityToList(const std::string &name, const Activity &a) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).addActivity(a);
        }
        it++;
    }
}

void ListOfLists::setActivityDone(const std::string &name, int activityPos) {
    auto it = lists.begin();
    while (it != lists.end()){
        if ((*it).getName()==name){
            (*it).setActivityDone(activityPos);
        }
        it++;
    }
}
