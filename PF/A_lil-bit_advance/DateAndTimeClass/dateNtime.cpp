/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-06-28.

  TIME: 12:49 AM.
*/
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0; // Should never reach here
    }
}

void convertTime(int total_seconds) {
    const int SECONDS_PER_MINUTE = 60;
    const int SECONDS_PER_HOUR = 3600;
    const int SECONDS_PER_DAY = 86400;


    int year = 1970;
    int month = 1;
    int day = 1;

    int days = total_seconds / SECONDS_PER_DAY;
    total_seconds %= SECONDS_PER_DAY;

    int hours = total_seconds / SECONDS_PER_HOUR;
    total_seconds %= SECONDS_PER_HOUR;

    int minutes = total_seconds / SECONDS_PER_MINUTE;
    int seconds = total_seconds % SECONDS_PER_MINUTE;

    while (days >= (isLeapYear(year) ? 366 : 365)) {
        days -= isLeapYear(year) ? 366 : 365;
        year++;
    }

    while (days >= daysInMonth(month, year)) {
        days -= daysInMonth(month, year);
        month++;
    }

    day += days;

    cout << setfill('0') << setw(4) << year << "-"
         << setw(2) << month << "-"
         << setw(2) << day << " "
         << setw(2) << hours << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds;
}

int main() {
    time_t now = time(0);

    cout << "Current UTC date and time: ";
    convertTime(now);

    // Pakistan Standard Time (PKT) = UTC+05:00 hrs
    cout << "\nCurrent Pakistan date and time: ";
    convertTime(now + (5 * 3600));

    return 0;
}