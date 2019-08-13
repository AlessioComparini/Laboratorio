//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H


#include <string>
#include "Date.h"

class Activity {
public:

private:
    std::string description;
    std::string title;
    Date expiration;
    bool done;

};


#endif //LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H
