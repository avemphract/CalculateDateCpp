#include "gtest/gtest.h"
#include "../DateFunctions.h"

TEST(ComputeNextDate, CommonNextDate){

    CDate currentDate;
    CDate expectedDate;
    createDate(1, 1, 2000, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(2, 1, 2000, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when common date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputeNextDate, LastDayOfMonthNextDate){
    CDate currentDate;
    CDate expectedDate;

    createDate(30, 6, 1995, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 7, 1995, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when last day of month date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    
    createDate(31, 8, 1995, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 9, 1995, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when last day of month date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

}

TEST(ComputeNextDate, LastDayOfYearNextDate){
    CDate currentDate;
    CDate expectedDate;

    createDate(31, 12, 1988, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 1, 1989, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when last day of year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    
    createDate(31, 12, 1975, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 1, 1976, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when last day of year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputeNextDate, LeapDayNextDate){

    CDate currentDate;
    CDate expectedDate;

    createDate(28, 2, 2004, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(29, 2, 2004, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(28, 2, 2012, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(29, 2, 2012, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputeNextDate, AfterLeapDayNextDate){

    CDate currentDate;
    CDate expectedDate;

    createDate(29, 2, 2008, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 3, 2008, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when after leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(29, 2, 2024, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 3, 2024, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when after leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputeNextDate, NonLeapDayNextDate){
    CDate currentDate;
    CDate expectedDate;
    
    createDate(28, 2, 2002, currentDate);
    currentDate = computeNextDate(currentDate);
    createDate(1, 3, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when non leap day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}

TEST(ComputeNextDate, MultipleNextDate){
    CDate currentDate;
    CDate expectedDate;
    
    createDate(4, 2, 2002, currentDate);
    for(size_t i = 0; i < 5; i++)
        currentDate = computeNextDate(currentDate);
    createDate(9, 2, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when next 5 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;


    createDate(4, 4, 2002, currentDate);
    for(size_t i = 0; i < 30; i++)
        currentDate = computeNextDate(currentDate);
    createDate(4, 5, 2002, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when next 30 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(4, 7, 2006, currentDate);
    for(size_t i = 0; i < 50; i++)
        currentDate = computeNextDate(currentDate);
    createDate(23, 8, 2006, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when next 50 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(4, 7, 2013, currentDate);
    for(size_t i = 0; i < 365; i++)
        currentDate = computeNextDate(currentDate);
    createDate(4, 7, 2014, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when next 365 day date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;

    createDate(15, 2, 2020, currentDate);
    for(size_t i = 0; i < 365; i++)
        currentDate = computeNextDate(currentDate);
    createDate(14, 2, 2021, expectedDate);
    EXPECT_TRUE(currentDate.mDay == expectedDate.mDay && currentDate.mMonth == expectedDate.mMonth && currentDate.mYear == expectedDate.mYear) << "ComputeNextDate get error when next 365 day in leap year date test."
    << " Expected: " << expectedDate.mDay << " ." << expectedDate.mMonth << " ." << expectedDate.mYear
    << " Actual: "<< currentDate.mDay << " ." << currentDate.mMonth << " ." << currentDate.mYear << std::endl;
}