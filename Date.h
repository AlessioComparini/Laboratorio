//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_DATE_H
#define LABORATORIODIPROGRAMMAZIONE_DATE_H


class Date {
public:
    Date(int d, int m, int year);

    const int getDay() const;

    const int getMonth() const;

    const unsigned short getYear() const;
private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;
    int getMaxDays(int year, int month) const;


};


#endif //LABORATORIODIPROGRAMMAZIONE_DATE_H
