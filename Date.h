//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_DATE_H
#define LABORATORIODIPROGRAMMAZIONE_DATE_H


class Date {
public:
    Date(int d, int m, int year);

    int getDay() const;

    int getMonth() const;

private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;
public:
    unsigned short getYear() const;

private:

    int getMaxDays(int year);
};


#endif //LABORATORIODIPROGRAMMAZIONE_DATE_H
