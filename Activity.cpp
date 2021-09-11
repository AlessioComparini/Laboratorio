//
// Created by Alessio Comparini on 2019-08-13.
//

#include <iostream>
#include "Activity.h"

Activity::Activity(std::string d, std::string t, Date e, bool done) : expiration(e) {
    description=d;
    title=t;
    this->done=done;

}

bool Activity::operator==(Activity right) const {
    return description==right.description && title==right.title;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const std::string &Activity::getTitle() const {
    return title;
}

void Activity::setTitle(const std::string &title) {
    Activity::title = title;
}

const Date &Activity::getExpiration() const {
    return expiration;
}

void Activity::setExpiration(const Date &expiration) {
    Activity::expiration = expiration;
}

bool Activity::isDone() const {
    return done;
}

void Activity::setDone(bool done) {
    Activity::done = done;
}

void Activity::display() const {
    std::cout<<"Titolo:       " << title << std::endl;
    std::cout<<"Descrizione:  " << description << std::endl;
    std::cout<<"Scadenza:     " << expiration.getDay() << "/" << expiration.getMonth() << "/"<< expiration.getYear() << std::endl;
}
