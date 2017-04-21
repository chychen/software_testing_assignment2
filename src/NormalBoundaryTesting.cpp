#include "gtest/gtest.h"
#include "assignment_1.h"

TEST(TriangleTest, NormalBoundaryTesting){
    // test cases for a
    EXPECT_EQ(Triangle(100, 100, 1), "Isosceles");
    EXPECT_EQ(Triangle(100, 100, 2), "Isosceles");
    EXPECT_EQ(Triangle(100, 100, 100), "Equilateral");
    EXPECT_EQ(Triangle(100, 100, 199), "Isosceles");
    EXPECT_EQ(Triangle(100, 100, 200), "Not a triangle");

    // test cases for b
    EXPECT_EQ(Triangle(100, 1, 100), "Isosceles");
    EXPECT_EQ(Triangle(100, 2, 100), "Isosceles");
    // EXPECT_EQ(Triangle(100, 100, 100), "Equilateral");
    EXPECT_EQ(Triangle(100, 199, 100), "Isosceles");
    EXPECT_EQ(Triangle(100, 200, 100), "Not a triangle");

    // test cases for c
    EXPECT_EQ(Triangle(1, 100, 100), "Isosceles");
    EXPECT_EQ(Triangle(2, 100, 100), "Isosceles");
    // EXPECT_EQ(Triangle(100, 100, 100), "Equilateral");
    EXPECT_EQ(Triangle(199, 100, 100), "Isosceles");
    EXPECT_EQ(Triangle(200, 100, 100), "Not a triangle");
}