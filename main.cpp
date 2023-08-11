#include <iostream>
#include "DateFunctions.h"

int main() {
    int day, month, year;

    std::cout << "Enter day: ";
    std::cin >> day;

    std::cout << "Enter month: ";
    std::cin >> month;

    std::cout << "Enter year: ";
    std::cin >> year;

    CDate inputDate;
    if (!createDate(day, month, year, inputDate)) {
        std::cout << "Invalid date." << std::endl;
        return 1;
    }

    char choice = ' ';

    do {
        std::cout << "Your date: " << inputDate.mDay << "/" << inputDate.mMonth << "/" << inputDate.mYear << std::endl;
        std::cout << "Enter 'n' to see the next day, 'p' to see the previous day, 'c' to exit: ";
        std::cin >> choice;

        if (choice == 'n') {
            CDate nextDate = computeNextDate(inputDate);
            std::cout << "Next day's date: " << nextDate.mDay << "/" << nextDate.mMonth << "/" << nextDate.mYear << std::endl;
            inputDate = nextDate; 
        } else if (choice == 'p') {
            CDate previousDate = computePreviousDate(inputDate);
            std::cout << "Previous day's date: " << previousDate.mDay << "/" << previousDate.mMonth << "/" << previousDate.mYear << std::endl;
            inputDate = previousDate;
        } else if (choice != 'c') {
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 'c');

    std::cout << "Exiting the program." << std::endl;
    return 0;
}
