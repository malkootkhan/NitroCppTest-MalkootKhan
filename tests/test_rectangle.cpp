#include "rectangle.hpp"
#include <gtest/gtest.h>

TEST(RectangleTest, Intersection) {
    Rectangle rect1;
    rect1.setRecData(100, 100, 150, 150);

    Rectangle rect2;
    rect2.setRecData(120, 120, 150, 150);

    ASSERT_TRUE(rect1 & rect2);

    Rectangle intersection = getShadedRec(rect1, rect2);
    EXPECT_EQ(intersection.getULeft_point().getXcord(), 120);
    EXPECT_EQ(intersection.getULeft_point().getYcord(), 100);
    EXPECT_EQ(intersection.getWidth(), 130);
    EXPECT_EQ(intersection.getHeight(), 130);
}

TEST(RectangleTest, NoIntersection) {
    Rectangle rect1;
    rect1.setRecData(100, 100, 150, 150);

    Rectangle rect2;
    rect2.setRecData(300, 300, 150, 150);

    ASSERT_FALSE(rect1 & rect2);
}

