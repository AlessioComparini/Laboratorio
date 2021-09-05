//
// Created by Alessio Comparini on 2019-08-13.
//

#include "Date.h"
#include <iostream>

Date::Date(int aDay, int aMonth, int aYear) {
    if (aYear < 0)
        throw std::runtime_error("Year < 0");
    if (aDay < 0)
        throw std::runtime_error("Days < 0");
    if (aMonth < 0 || aMonth > 12)
        throw std::runtime_error("Error in month number");
    this->month = aMonth;
    this->year = aYear;
    if (aDay > getMaxDays(this->year))
        throw std::runtime_error("Error in number of days");
    this->day = aDay;

}

int Date::getMaxDays(int year) {
    short unsigned int maxDay = 31;
    switch (this->month) {
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

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

unsigned short Date::getYear() const {
    return year;
}
