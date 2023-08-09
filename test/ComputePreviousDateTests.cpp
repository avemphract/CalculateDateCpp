#include "gtest/gtest.h"
#include "../DateFunctions.h"

TEST(ComputePreviousDate, CommonPreviousDate){
    CDate currentDate;
    CDate expectedDate;

    createDate(20, 1, 2000, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(19, 1, 2000, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when common date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputePreviousDate, FirstDayOfMonthPreviousDate){
    CDate currentDate;
    CDate expectedDate;

    createDate(1, 6, 1995, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(31, 5, 1995, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when last day of month date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    
    createDate(1, 9, 1995, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(31, 8, 1995, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when last day of month date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

}

TEST(ComputePreviousDate, FirstDayOfYearPreviousDate){
    CDate currentDate;
    CDate expectedDate;

    createDate(1, 1, 1989, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(31, 12, 1988, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when last day of year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    
    createDate(1, 1, 1976, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(31, 12, 1975, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when last day of year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputePreviousDate, LeapDayPreviousDate){

    CDate currentDate;
    CDate expectedDate;

    createDate(1, 3, 2004, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(29, 2, 2004, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(1, 3, 2012, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(29, 2, 2012, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputePreviousDate, NonLeapDayPreviousDate){

    CDate currentDate;
    CDate expectedDate;
    
    createDate(1, 3, 2002, currentDate);
    currentDate = computePreviousDate(currentDate);
    createDate(28, 2, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when after leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputePreviousDate, MultiplePreviousDate){
    CDate currentDate;
    CDate expectedDate;
    
    createDate(9, 2, 2002, currentDate);
    for(size_t i = 0; i < 5; i++)
        currentDate = computePreviousDate(currentDate);
    createDate(4, 2, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when Previous 5 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;


    createDate(4, 5, 2002, currentDate);
    for(size_t i = 0; i < 30; i++)
        currentDate = computePreviousDate(currentDate);
    createDate(4, 4, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when Previous 30 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(23, 8, 2006, currentDate);
    for(size_t i = 0; i < 50; i++)
        currentDate = computePreviousDate(currentDate);
    createDate(4, 7, 2006, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when Previous 50 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(4, 7, 2014, currentDate);
    for(size_t i = 0; i < 365; i++)
        currentDate = computePreviousDate(currentDate);
    createDate(4, 7, 2013, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when Previous 365 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(15, 2, 2021, currentDate);
    for(size_t i = 0; i < 365; i++)
        currentDate = computePreviousDate(currentDate);
    createDate(16, 2, 2020, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputePreviousDate get error when Previous 365 day in leap year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}