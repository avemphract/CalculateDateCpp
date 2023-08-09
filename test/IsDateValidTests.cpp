#include <gtest/gtest.h>
#include <limits.h>
#include "../DateFunctions.h"

TEST(IsDateValid, ValidDates){
    CDate date;
    date.mDay = 1;
    date.mMonth = 1;
    date.mYear = 2000;
    EXPECT_TRUE(isDateValid(date));

    date.mDay = 31;
    date.mMonth = 12;
    date.mYear = 2000;
    EXPECT_TRUE(isDateValid(date));
    
    date.mDay = 29;
    date.mMonth = 2;
    date.mYear = 2000;
    EXPECT_TRUE(isDateValid(date));

    date.mDay = 28;
    date.mMonth = 2;
    date.mYear = 2100;
    EXPECT_TRUE(isDateValid(date));

    date.mDay = 4;
    date.mMonth = 9;
    date.mYear = INT32_MAX;
    EXPECT_TRUE(isDateValid(date));

    date.mDay = 15;
    date.mMonth = 10;
    date.mYear = INT32_MIN;
    EXPECT_TRUE(isDateValid(date));
}

TEST(IsDateValid, InvalidDayNumber){
    CDate date;

    date.mDay = 50;
    date.mMonth = 2;
    date.mYear = 2000;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;
        
    date.mDay = 35;
    date.mMonth = 2;
    date.mYear = 2020;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;

    date.mDay = 32;
    date.mMonth = 3;
    date.mYear = 2030;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;

    
    date.mDay = 31;
    date.mMonth = 4;
    date.mYear = 2100;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;
    
    date.mDay = -1;
    date.mMonth = 9;
    date.mYear = 1945;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;
}

TEST(IsDateValid, InvalidMonthNumber){
    CDate date;

    date.mDay = 15;
    date.mMonth = 0;
    date.mYear = 2120;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;
        
    date.mDay = 4;
    date.mMonth = -2;
    date.mYear = 2456;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;

    date.mDay = 32;
    date.mMonth = 13;
    date.mYear = 984;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;

    
    date.mDay = 31;
    date.mMonth = 80;
    date.mYear = 1970;
    EXPECT_FALSE(isDateValid(date)) << "Invalid Date. Date: " << date.mDay << "." << date.mMonth << "." << date.mYear;
}