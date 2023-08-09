#include "CDate.cpp"

CDate computeNextDate(CDate currentDate);

CDate computePreviousDate(CDate currentDate);

bool isDateValid(CDate date);

bool createDate(int day, int month, int year, CDate &date);

bool isLeapYear(int year);

int getDayOfMonth(int month, int year);
