//
// Created by aleal on 21/08/2021.
//

#include <gtest/gtest.h>
#include "../Activity.h"

TEST(Activity , ActivityTest){
    Activity a = Activity ("null","null",Date(1,1),false);
    ASSERT_FALSE(a.isDone());
    a.setDone(true);
    ASSERT_EQ(a.isDone(),true);
}