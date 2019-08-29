//
// Created by Alessio Comparini on 2019-08-13.
//

#include <iostream>
#include "TodoList.h"

void TodoList::printAllActivities() {
    int num = 1;
    for (auto it : list){
        std::cout << num++ << ")" << std::endl;
        it.display();
        std::cout<<std::endl;
    }
}

void TodoList::printActivitiesTodo() {
    for (auto it : list){
        if (!it.isDone()) {
            it.display();
            std::cout<<std::endl;
        }
    }

}

void TodoList::printActivitiesDone() {
    for (auto it : list) {
        if (it.isDone())
            it.display();
    }
}

void TodoList::addActivity(Activity a) {
    list.push_back(a);
}

void TodoList::removeActivity(Activity a) {
    list.remove(a);

}

void TodoList::setActivityDone(Activity a) {
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

int TodoList::getSize() {
    return list.size();
}

void TodoList::setActivityDone(int position) {
    auto it=list.begin();
    for (int i=0;i<position;i++)
        it++;
    list.remove(*it);
}