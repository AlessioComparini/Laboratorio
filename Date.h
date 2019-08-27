//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_DATE_H
#define LABORATORIODIPROGRAMMAZIONE_DATE_H


class Date {
public:
    Date(int d, int m);

    int getDay() const;

    int getMonth() const;

private:
    int day;
    int month;
};


#endif //LABORATORIODIPROGRAMMAZIONE_DATE_H
