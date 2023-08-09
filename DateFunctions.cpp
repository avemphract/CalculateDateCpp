#include "DateFunctions.h"

CDate computeNextDate(CDate currentDate)
{
    CDate nextDate = currentDate;
    nextDate.mDay++;
    if (!isDateValid(nextDate))
    {
        nextDate.mMonth++;
        nextDate.mDay = 1;
        if(!isDateValid(nextDate)){
            nextDate.mYear++;
            nextDate.mMonth = 1;
        }
    }
    return nextDate;
};

CDate computePreviousDate(CDate currentDate)
{
    CDate previousDate = currentDate;
    previousDate.mDay--;
    if (!isDateValid(previousDate))
    {
        previousDate.mMonth--;
        previousDate.mDay = getDayOfMonth(previousDate.mMonth, previousDate.mYear);
        if(!isDateValid(previousDate)){
            previousDate.mYear--;
            previousDate.mMonth = 12;
            previousDate.mDay = getDayOfMonth(12, previousDate.mYear);
        }
    }
    return previousDate;
};

bool isDateValid(CDate date)
{
    bool valid = true;
    switch (date.mMonth)
    {
        case 12:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 11:
            valid = (1 <= date.mDay && date.mDay <= 30);
            break;
        case 10:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 9:
            valid = (1 <= date.mDay && date.mDay <= 30);
            break;
        case 8:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 7:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 6:
            valid = (1 <= date.mDay && date.mDay <= 30);
            break;
        case 5:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 4:
            valid = (1 <= date.mDay && date.mDay <= 30);
            break;
        case 3:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        case 2:
            valid = (1 <= date.mDay && date.mDay <= (isLeapYear(date.mYear) ? 29:28));
            break;
        case 1:
            valid = (1 <= date.mDay && date.mDay <= 31);
            break;
        default:
            return false;
    }
    return valid;
};

bool createDate(int day, int month, int year, CDate &date){
    date.mDay = day;
    date.mMonth = month;
    date.mYear = year;
    if (isDateValid(date))
    {
        return true;
    }
    else{
        return false;
    }
};

bool isLeapYear(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        else
            return true;
    }
    else
      return false;
};


int getDayOfMonth(int month, int year){
    switch (month)
    {
        case 12:
        case 10:
        case 8:
        case 7:
        case 5:
        case 3:
        case 1:
            return 31;
        case 11:
        case 9:
        case 6:
        case 4:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else 
                return 28;
    }
};