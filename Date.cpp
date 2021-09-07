//
// Created by Alessio Comparini on 2019-08-13.
//

#include "Date.h"
#include <iostream>

Date::Date(int aDay, int aMonth, int aYear) {
    if (aYear < 0 or aDay < 1 or aMonth < 1 or aMonth > 12 or aDay > getMaxDays(aYear, aMonth)){
        throw std::runtime_error ("Date not valid");
    }
    this->day = aDay;
    this->month = aMonth;
    this->year = aYear;
}

int Date::getMaxDays(int year, int month) const {
    short unsigned int maxDay = 31;
    switch (month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
        maxDay = 30;
        break;
        case 2: {

            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        maxDay = 29;
                    } else {
                        maxDay = 28;
                    }
                } else {
                    maxDay = 29;
                }
            } else {
                maxDay = 28;
            }
        }
    }
    return maxDay;
}

const int Date::getDay() const {
    return day;
}

const int Date::getMonth() const {
    return month;
}

const unsigned short Date::getYear() const {
    return year;
}
