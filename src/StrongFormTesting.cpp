#include "gtest/gtest.h"
#include "assignment_1.h"

// Strong Form
TEST(TriangleTest, StrongFormTesting){
    // weak normal part
    EXPECT_EQ(Triangle(5, 5, 5), "Equilateral");
    EXPECT_EQ(Triangle(2, 2, 3), "Isosceles");
    EXPECT_EQ(Triangle(3, 4, 5), "Scalene");
    EXPECT_EQ(Triangle(4, 1, 2), "Not a triangle");
    // weak robust part
    EXPECT_EQ(Triangle(-1, 5, 5), "Value if a is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, -1, 5), "Value if b is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, 5, -1), "Value if c is not in the range of permitted values");
    EXPECT_EQ(Triangle(201, 5, 5), "Value if a is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, 201, 5), "Value if b is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, 5, 201), "Value if c is not in the range of permitted values");
    // strong robust part
    EXPECT_EQ(Triangle(-1, -1, 5), "Value if a, b is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, -1, -1), "Value if b, c is not in the range of permitted values");
    EXPECT_EQ(Triangle(-1, 5, -1), "Value if a, c is not in the range of permitted values");
    EXPECT_EQ(Triangle(-1, -1, -1), "Value if a, b, c is not in the range of permitted values");
    EXPECT_EQ(Triangle(201, 201, 5), "Value if a, b is not in the range of permitted values");
    EXPECT_EQ(Triangle(5, 201, 201), "Value if b, c is not in the range of permitted values");
    EXPECT_EQ(Triangle(201, 5, 201), "Value if a, c is not in the range of permitted values");
    EXPECT_EQ(Triangle(201, 201, 201), "Value if a, b, c is not in the range of permitted values");
}

TEST(NextDateTest, StrongFormTesting){
    //Weak Noraml part
    EXPECT_EQ(NextDate(6, 14, 2000), "6/15/2000");
    EXPECT_EQ(NextDate(7, 29, 1912), "7/30/1912");
    EXPECT_EQ(NextDate(2, 30, 1912), "Invalid input date");
    EXPECT_EQ(NextDate(6, 31, 1912), "Invalid input date");
    //Weak Robust part
    EXPECT_EQ(NextDate(6, 15, 1912), "6/16/1912");
    EXPECT_EQ(NextDate(-1, 15, 1912), "month not in 1...12");
    EXPECT_EQ(NextDate(13, 15, 1912), "month not in 1...12");
    EXPECT_EQ(NextDate(6, -1, 1912), "day not in 1...31");
    EXPECT_EQ(NextDate(6, 32, 1912), "day not in 1...31");
    EXPECT_EQ(NextDate(6, 15, 1811), "year not in 1812...2012");
    EXPECT_EQ(NextDate(6, 15, 2013), "year not in 1812...2012");
    //Strong Normal part
    EXPECT_EQ(NextDate(6, 14, 2000), "6/15/2000");
    EXPECT_EQ(NextDate(6, 14, 1996), "6/15/1996");
    EXPECT_EQ(NextDate(6, 14, 2002), "6/15/2002");
    EXPECT_EQ(NextDate(6, 29, 2000), "6/30/2000");
    EXPECT_EQ(NextDate(6, 29, 1996), "6/30/1996");
    EXPECT_EQ(NextDate(6, 29, 2002), "6/30/2002");
    EXPECT_EQ(NextDate(6, 30, 2000), "7/1/2000");
    EXPECT_EQ(NextDate(6, 30, 1996), "7/1/1996");
    EXPECT_EQ(NextDate(6, 30, 2002), "7/1/2002");
    EXPECT_EQ(NextDate(6, 31, 2000), "Invalid input date");
    EXPECT_EQ(NextDate(6, 31, 1996), "Invalid input date");
    EXPECT_EQ(NextDate(6, 31, 2002), "Invalid input date");
    EXPECT_EQ(NextDate(7, 14, 2000), "7/15/2000");
    EXPECT_EQ(NextDate(7, 14, 1996), "7/15/1996");
    EXPECT_EQ(NextDate(7, 14, 2002), "7/15/2002");
    EXPECT_EQ(NextDate(7, 29, 2000), "7/30/2000");
    EXPECT_EQ(NextDate(7, 29, 1996), "7/30/1996");
    EXPECT_EQ(NextDate(7, 29, 2002), "7/30/2002");
    EXPECT_EQ(NextDate(7, 30, 2000), "7/31/2000");
    EXPECT_EQ(NextDate(7, 30, 1996), "7/31/1996");
    //Strong Robust part
    EXPECT_EQ(NextDate(-1, 15, 1912), "month not in 1...12");
    EXPECT_EQ(NextDate(6, -1, 1912), "day not in 1...31");
    EXPECT_EQ(NextDate(6, 15, 1811), "year not in 1812...2012");
    EXPECT_EQ(NextDate(-1, -1, 1912), "month not in 1...12\nday not in 1...31");
    EXPECT_EQ(NextDate(6, -1, 1811), "day not in 1...31\nyear not in 1812...2012");
    EXPECT_EQ(NextDate(-1, 15, 1811), "month not in 1...12\nyear not in 1812...2012");
    EXPECT_EQ(NextDate(-1, -1, 1811), "month not in 1...12\nday not in 1...31\nyear not in 1812...2012");
}

TEST(CommissionTest, StrongFormTesting){
    //Weak Robust part
    EXPECT_EQ(Commission(10, 10, 10), "$100");
    EXPECT_EQ(Commission(-1, 40, 45), "Program terminates");
    EXPECT_EQ(Commission(-2, 40, 45), "locks not in 1...70");
    EXPECT_EQ(Commission(71, 40, 45), "locks not in 1...70");
    EXPECT_EQ(Commission(35, -1, 45), "stocks not in 1...80");
    EXPECT_EQ(Commission(35, 81, 45), "stocks not in 1...80");
    EXPECT_EQ(Commission(35, 40, -1), "barrels not in 1...90");
    EXPECT_EQ(Commission(35, 40, 91), "barrels not in 1...90");
    //Strong Robust part
    EXPECT_EQ(Commission(-2, 40, 45), "locks not in 1...70");
    EXPECT_EQ(Commission(35, -1, 45), "stocks not in 1...80");
    EXPECT_EQ(Commission(35, 40, -2), "barrels not in 1...90");
    EXPECT_EQ(Commission(-2, -1, 45), "locks not in 1...70\nstocks not in 1...80");
    EXPECT_EQ(Commission(-2, 40, -1), "locks not in 1...70\nbarrels not in 1...90");
    EXPECT_EQ(Commission(35, -1, -1), "stocks not in 1...80\nbarrels not in 1...90");
    EXPECT_EQ(Commission(-2, -1, -1), "locks not in 1...70\nstocks not in 1...80\nbarrels not in 1...90");
}