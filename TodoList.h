//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIODIPROGRAMMAZIONE_TODOLIST_H


#include <list>
#include "Activity.h"

class TodoList : public std::error_code {
public:
    explicit TodoList(std::string n);
    void printAllActivities();
    void printActivitiesTodo();
    void printActivitiesDone();
    void addActivity(Activity a);
    void removeActivity(Activity a);
    void removeActivity(int pos);
    void setActivityDone(Activity a);
    void setActivityDone(int position);
    const int getSize();
    Activity getActivityy(int position);
private:
public:
    const std::string &getName() const;

private:
    std::list<Activity> list;
    std::string name;

};


#endif //LABORATORIODIPROGRAMMAZIONE_TODOLIST_H
