#include "gtest/gtest.h"
#include "assignment_2_1.h"

// C0_Testing
TEST(TriangleTest, MCDC_Testing){
    // R1
    EXPECT_EQ(Triangle(500, 100, 100), "Value if a is not in the range of permitted values");
    // R2
    EXPECT_EQ(Triangle(100, 500, 100), "Value if b is not in the range of permitted values");
    // R3
    EXPECT_EQ(Triangle(100, 100, 500), "Value if c is not in the range of permitted values");
    // R4
    EXPECT_EQ(Triangle(100, 100, 200), "Not a triangle");
    // R5
    EXPECT_EQ(Triangle(100, 100, 101), "Isosceles");
    // R6
    // mathmatically impossible
    // R7
    EXPECT_EQ(Triangle(100, 100, 100), "Equilateral");
    // R8
    EXPECT_EQ(Triangle(99, 100, 101), "Scalene");
}