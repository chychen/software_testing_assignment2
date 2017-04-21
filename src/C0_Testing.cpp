#include "gtest/gtest.h"
#include "assignment_2_1.h"

// C0_Testing
TEST(TriangleTest, C0_Testing){
    // C01
    EXPECT_EQ(Triangle(500, 500, 500), "Value if a, b, c is not in the range of permitted values");
    // C02
    EXPECT_EQ(Triangle(100, 500, 500), "Value if b, c is not in the range of permitted values");
    // C03
    EXPECT_EQ(Triangle(100, 100, 500), "Value if c is not in the range of permitted values");
    // C04
    EXPECT_EQ(Triangle(100, 100, 101), "Isosceles");
    // C05
    // mathmatically impossible
    // C06
    EXPECT_EQ(Triangle(100, 100, 100), "Equilateral");
    // C07
    EXPECT_EQ(Triangle(99, 100, 101), "Scalene");
    // C08
    EXPECT_EQ(Triangle(100, 100, 200), "Not a triangle");
}