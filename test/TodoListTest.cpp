//
// Created by aleal on 21/08/2021.
//

#include <gtest/gtest.h>
#include "../TodoList.h"
#include "../Activity.h"



TEST(TodoList , TodoListSizeTest){
    Activity a = Activity("a","a",Date(1,1),false);
    TodoList tl;
    EXPECT_EQ(tl.getSize(),0);
    tl.addActivity(a);
    EXPECT_EQ(tl.getSize(),1);
    tl.addActivity(a);
    tl.removeActivity(1);
    tl.removeActivity(a);
    EXPECT_EQ(tl.getSize(),0);
}