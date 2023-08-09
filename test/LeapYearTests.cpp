#include <gtest/gtest.h>
#include "../DateFunctions.h"

TEST(IsLeapYear, IsLeapYearMod4){    
    EXPECT_TRUE(isLeapYear(1600));
    EXPECT_TRUE(isLeapYear(2000));

    EXPECT_TRUE(isLeapYear(2004));
    EXPECT_TRUE(isLeapYear(2008));
    EXPECT_TRUE(isLeapYear(2012));
    EXPECT_TRUE(isLeapYear(2016));
    EXPECT_TRUE(isLeapYear(2020));
}

TEST(IsLeapYear, IsLeapYearMod100){

    EXPECT_FALSE(isLeapYear(1700));
    EXPECT_FALSE(isLeapYear(1800));
    EXPECT_FALSE(isLeapYear(1900));
}

TEST(IsLeapYear, IsLeapYearMod400){

    EXPECT_TRUE(isLeapYear(1200));
    EXPECT_TRUE(isLeapYear(1600));
    EXPECT_TRUE(isLeapYear(2000));
}

TEST(IsLeapYear, IsLeapYearModOthers){

    EXPECT_FALSE(isLeapYear(2001));
    EXPECT_FALSE(isLeapYear(2002));
    EXPECT_FALSE(isLeapYear(2003));
    EXPECT_FALSE(isLeapYear(2005));
    EXPECT_FALSE(isLeapYear(2006));
    EXPECT_FALSE(isLeapYear(2007));
}