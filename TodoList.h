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
    const void printAllActivities() const;
    const void printActivitiesTodo() const;
    const void printActivitiesDone() const;
    void addActivity(const Activity &a);
    void removeActivity(Activity &a);
    void removeActivity(int pos);
    void setActivityDone(Activity &a);
    void setActivityDone(int position);
    int getSize() const;
    int getActivityToDo () const;
    Activity getActivityy(int position) const;
    const std::string &getName() const;
private:
    std::list<Activity> list;
    std::string name;

};


#endif //LABORATORIODIPROGRAMMAZIONE_TODOLIST_H
