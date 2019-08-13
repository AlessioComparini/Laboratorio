//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIODIPROGRAMMAZIONE_TODOLIST_H


#include <list>
#include "Activity.h"

class TodoList {
public:
    void printAllActivities();
    void printActivitiesTodo();
    void printActivitiesDone();
    void addActivity(Activity a);
    void removeActivity(Activity a);
    void setActivityDone();
private:
    std::list<Activity> list;
};


#endif //LABORATORIODIPROGRAMMAZIONE_TODOLIST_H
