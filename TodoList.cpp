//
// Created by Alessio Comparini on 2019-08-13.
//

#include "TodoList.h"

void TodoList::printAllActivities() {
    for (auto it : list)
        it.display();
}

void TodoList::printActivitiesTodo() {
    for (auto it : list){
        if (!it.isDone())
            it.display();
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


void TodoList::setActivityDone(int position) {
    auto it=list.begin();
    for (int i=0;i<position;i++)
        it++;
    list.remove(*it);
}
