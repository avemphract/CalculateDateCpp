# Calculate Date

In this project, i write calculate date from integers, Get next dates and get previous dates. 

# Project Description

Project main purpose is find next date and previous date. So first two functions is calculateNextDate and calculatePrivousDate. Other 4 functions are help to run first two's but they can be used seperately. 

```cpp
CDate computeNextDate(CDate currentDate);
```
Return next date of given date.

```cpp
CDate computePreviousDate(CDate currentDate);
```
Return previous date of given date.

```cpp
bool isDateValid(CDate date);
```
Check date is valid or not.

```cpp
bool createDate(int day, int month, int year, CDate &date);
```
Try to create date. If date valid return true and set date from date parameter.

```cpp
bool isLeapYear(int year);
```
Find the year which is leap year or not

```cpp
int getDayOfMonth(int month, int year);
```
Get total day of wanted month

Also project has own unit tests which is inside of test directiory.

# Requirement

### Cmake 

Cmake using form build automation and more. Cmake provide to ide and operator system indipendent development. Also I write commands in CMakeList.txt which is download required library and add project. After download add enviroment variable cmake in windows.

Cmake leaves to free decide how the project should be created. I use 'Visual Studio 17 2022' project. If you want to different ide, read more details in cmake generators.

### VS 2022 (Optional)
I run with VS 2022 compiler but you can use other ide with other generators. Also I added VS 2022 compiler command(MSBuild.exe) to enviroment variables for using shortcut.

# How to Install and Run the Project

Firstly we create project to build directory with cmake.
```
cmake -S . -B build -G "Visual Studio 17 2022"
```

After created project we can compile solution. This gives me exe files.
```
MSBuild.exe build/CppHomework_4.sln
```

All left is run compiled project. I didn't make executable to main project but you can run unit tests.
```
build/test/Debug/UnitTests.exe 
```

# Unit Test Details

I write unit tests for 4 functions.

### ComputeNextDate Function Tests
1. For common date's results must valid.
    - Next date of 1.1.2000 must be equals 2.1.2000
2. Next date of last day of month equal to date of next month's first day
    - Next date of 30.6.1995 must be equals 1.7.1995
    - Next date of 31.8.1995 must be equals 1.9.1995
3. Next date of Last day of year must be equal to date of next year's first day
    - Next date of 31.12.1988 must be equals 1.1.1989
    - Next date of 31.12.1975 must be equals 1.9.1976
4. Next date of 27 February in a leap year must be 28 February
    - Next date of 28.2.2004 must be equals 29.2.2004
    - Next date of 28.2.2012 must be equals 29.2.2012
5. Next date of 28 February in a leap year must be 1 March
    - Next date of 29.2.2008 must be equals 1.3.2004
    - Next date of 29.2.2012 must be equals 1.3.2012
6. Next date of 27 February in non leap year must be 1 March
    - Next date of 28.2.2002 must be equals 1.3.2002
7. If next date used multiple results must be valid
    - 5 days after 4.2.2002 must be equals 9.2.2002
    - 30 days after 4.4.2002 must be equals 4.5.2002
    - 50 days after 4.7.2006 must be equals 23.8.2006
    - 365 days after 4.7.2013 must be equals 4.7.2014
    - 365 days after 15.2.2020 must be eqauls 14.2.2021 (absent one beacuse of leap year)

### ComputePreviousDate Function Tests
1. For common date's results must valid.
    - Previous date of 2.1.2000 must be equals 1.1.2000
2. Previous date of first day of month equal to date of previous month's last day
    - Previous date of 1.7.1995 must be equals 30.6.1995
    - Previous date of 1.9.1995 must be equals 31.8.1995
3. Previous date of first day of year must be equal to date of previous year's last day
    - Previous date of 1.1.1989 must be equals 31.12.1988
    - Previous date of 1.1.1976 must be equals 31.12.1975
4. Previous date of 29 February in a leap year must be 28 February
    - Previous date of 29.2.2004 must be equals 28.2.2004
    - Previous date of 29.2.2012 must be equals 28.2.2012
5. Previous date of 1 March in a leap year must be 28 February
    - Previous date of 1.3.2008 must be equals 29.3.2004
    - Previous date of 1.3.2012 must be equals 29.3.2012
6. Previous date of 1 March in non leap year must be 28 February
    - Previous date of 1.3.2002 must be equals 28.2.2002
7. If previous date used multiple results must be valid
    - 5 days previous 9.2.2002 must be equals 9.2.2002
    - 30 days previous 4.5.2002 must be equals 4.4.2002
    - 50 days previous 23.8.2006 must be equals 4.7.2006
    - 365 days previous 4.7.2014 must be equals 4.7.2013
    - 365 days previous 15.2.2021 must be eqauls 16.2.2020 (plus one beacuse of leap year)

### IsValidDate Function Tests
1. Valid date must be return true.
    - 1.1.2020 must be true
    - 31.12.2020 must be true
    - 29.2.2000 must be true
    - 28.2.2100 must be true
    - 4.9.2147483647 must be true (when year is maximum integer value)
    - 4.9.-2147483648 must be true (when year is minimum integer value)
2. Return false, when day number is invalid.
    - 50.2.2000 must be false
    - 35.2.2020 must be false
    - 32.3.2030 must be false
    - 31.4.2100 must be false
    - -1.9.1945 must be false
3. Return false, when month number is invalid.
    - 15.0.2120 must be false
    - 4.-2.2456 must be false
    - 32.13.2030 must be false
    - 31.80.2100 must be false
### IsLeapYear Function Tests
1. When year's mod 4 is zero return true
    - 1600 is must be Leap Year
    - 2000 is must be Leap Year
    - 2008 is must be Leap Year
    - 2012 is must be Leap Year
    - 2016 is must be Leap Year
    - 2020 is must be Leap Year
2. When year's mod 100 is 0 return false
    - 1700 is must be not Leap Year
    - 1800 is must be not Leap Year
    - 1900 is must be not Leap Year
3. When year's mod 400 is 0 return true
    - 1200 is must be Leap Year
    - 1600 is must be Leap Year
    - 2000 is must be Leap Year
4. When year's mod 4 is zero return true
    - 2001 is must be not Leap Year
    - 2002 is must be not Leap Year
    - 2003 is must be not Leap Year
    - 2005 is must be not Leap Year
    - 2006 is must be not Leap Year
    - 2007 is must be not Leap Year