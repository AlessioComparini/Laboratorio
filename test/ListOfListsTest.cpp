//
// Created by aleal on 07/09/2021.
//

#include <gtest/gtest.h>
#include "../ListOfLists.h"
#include "../TodoList.h"


class TodoTester : public ::testing::Test {

protected:
    virtual void SetUp() {
        TodoList I=TodoList("Lista1");
        TodoList II=TodoList("Lista2");
        TodoList III=TodoList("Lista3");
        c.addList(I);
        c.addList(II);
        c.addList(III);
    }

    ListOfLists c;
};


TEST_F (TodoTester, SaveTest) {
    Activity a = Activity("Comprare pasta e ragu","Fare la spesa",Date(19,07,2021),false);
    Activity aa = Activity("Comprare matite e pennarelli","Andare in cartoleria",Date(21,07,2021),false);
    Activity aaa = Activity("Torneo di 3v3 pallacanestro presso il giardino dell'Anello","Pallacanestro",Date(20,07,2021),false);
    c.addActivityToList("Lista1",a);
    c.addActivityToList("Lista2",aa);
    c.addActivityToList("Lista3",aaa);
    EXPECT_EQ(3, c.getSize());
    c.moveList("Lista1", "Lista2",a);
    EXPECT_EQ(3, c.getSize());
    EXPECT_EQ(0, c.getList("Lista1").getSize());
    EXPECT_EQ(2, c.getList("Lista2").getSize());

}