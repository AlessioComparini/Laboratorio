//
// Created by Alessio Comparini on 2019-08-13.
//

#include <iostream>
#include "TodoList.h"

TodoList::TodoList(std::string n) {
    this->name = n;
}

const void TodoList::printAllActivities() const {
    int num = 1;
    if (list.size()) {
        for (auto it : list) {
            std::cout << num++ << ")";
            if (it.isDone())
                std::cout << "DONE";
            std::cout << std::endl;
            it.display();
            std::cout << std::endl;
        }
    }
    else {
        std::cout<<"List is empty"<<std::endl;
    }
}

const void TodoList::printActivitiesTodo() const {
    for (auto it : list){
        if (!it.isDone()) {
            it.display();
            std::cout<<std::endl;
        }
    }

}

const void TodoList::printActivitiesDone() const {
    for (auto it : list) {
        if (it.isDone())
            it.display();
    }
}

void TodoList::addActivity(const Activity &a) {
    list.push_back(a);
}

void TodoList::removeActivity(Activity &a) {
    list.remove(a);

}

void TodoList::setActivityDone(Activity &a) {
    for (auto it : list){
        if (it==a)
            it.setDone(true);
    }
}

void TodoList::removeActivity(int pos) {
    auto it =list.begin();
    for (int i=1;i<pos;i++)
        it++;
    list.remove(*it);
}

int TodoList::getSize() const {
    return list.size();
}

void TodoList::setActivityDone(int position) {
    auto it=list.begin();
    for (int i=1;i<position;i++)
        it++;
    (*it).setDone(true);
}

Activity TodoList::getActivityy(int position) const {
    auto it=list.begin();
    for (int i=1;i<position;i++)
        it++;
    return *it;
}

const std::string &TodoList::getName() const {
    return name;
}

int TodoList::getActivityToDo() const {
    int count = 0;
    auto it=list.begin();
    while ( it != list.end()){
        if (!(*it).isDone())
            count++;
        it++;
    }
    return count;
}
