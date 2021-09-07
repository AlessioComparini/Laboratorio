//
// Created by aleal on 07/09/2021.
//


#include <gtest/gtest.h>
#include "../Date.h"

TEST(Date , DateTest){
    Date a = Date (1,1,1999);
    ASSERT_EQ(a.getDay(),1);
    ASSERT_EQ(a.getMonth(),1);
    ASSERT_EQ(a.getYear(),1999);
    ASSERT_ANY_THROW(Date (29,2,2021));

}