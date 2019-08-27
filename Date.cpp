//
// Created by Alessio Comparini on 2019-08-13.
//

#include "Date.h"

Date::Date(int d, int m) {
day=d;
month=m;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}
