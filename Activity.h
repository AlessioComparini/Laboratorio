//
// Created by Alessio Comparini on 2019-08-13.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H


#include <string>
#include "Date.h"

class Activity {
public:
    Activity (std::string d, std::string t, Date e, bool done);

    bool operator==(Activity right) const;

    void display()const;

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const Date &getExpiration() const;

    void setExpiration(const Date &expiration);

    bool isDone() const;

    void setDone(bool done);

private:
    std::string description;
    std::string title;
    Date expiration;
    bool done;

};


#endif //LABORATORIODIPROGRAMMAZIONE_ACTIVITY_H
