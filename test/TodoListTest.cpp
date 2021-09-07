//
// Created by aleal on 21/08/2021.
//

#include <gtest/gtest.h>
#include "../TodoList.h"



TEST(TodoList , TodoListSizeTest){
    Activity a = Activity("a","a",Date(1,1,1999),false);
    TodoList tl("lista 1");
    EXPECT_EQ(tl.getSize(),0);
    tl.addActivity(a);
    EXPECT_EQ(tl.getSize(),1);
    tl.addActivity(a);
    tl.removeActivity(1);
    tl.removeActivity(a);
    EXPECT_EQ(tl.getSize(),0);
}