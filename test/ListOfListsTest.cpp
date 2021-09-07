//
// Created by aleal on 07/09/2021.
//

#include <gtest/gtest.h>
#include "../ListOfLists.h"
#include "../TodoList.h"


class TodoTester : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.addList(TodoList("Lista1"));
        c.addList(TodoList("Lista2"));
        c.addList(TodoList("Lista3"));
    }

    ListOfLists c;
};


TEST_F (TodoTester, SaveTest) {
    Activity a = Activity("Comprare pasta e ragu","Fare la spesa",Date(19,07,2021),false);
    c.addActivityToList("Lista1",a);
    c.addActivityToList("Lista2",Activity("Comprare matite e pennarelli","Andare in cartoleria",Date(21,07,2021),false));
    c.addActivityToList("Lista3",Activity("Torneo di 3v3 pallacanestro presso il giardino dell'Anello","Pallacanestro",Date(20,07,2021),false));
    EXPECT_EQ(3, c.getSize());
    c.moveList("Lista1", "Lista2",a);
    EXPECT_EQ(3, c.getSize());
    EXPECT_EQ(0, c.getList("Lista1").getSize());
    EXPECT_EQ(2, c.getList("Lista2").getSize());

}