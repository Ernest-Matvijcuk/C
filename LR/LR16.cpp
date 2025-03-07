#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date today() {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date currentDate;
    currentDate.year = tl.tm_year + 1900;
    currentDate.month = tl.tm_mon + 1;
    currentDate.day = tl.tm_mday;
    return currentDate;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

int daysBetween(Date birth, Date current) {
    int totalDays = 0;

    for (int m = birth.month; m <= 12; m++) {
        if (m == birth.month) {
            totalDays += monthLength(birth.year, m) - birth.day;
        } else {
            totalDays += monthLength(birth.year, m);
        }
    }

    for (int y = birth.year + 1; y < current.year; y++) {
        totalDays += isLeap(y) ? 366 : 365;
    }

    for (int m = 1; m < current.month; m++) {
        totalDays += monthLength(current.year, m);
    }
    totalDays += current.day;

    return totalDays;
}

int main() {
    Date birthDate;
    cout << "Введіть вашу дату народження (РРРР ММ ДД): ";
    cin >> birthDate.year >> birthDate.month >> birthDate.day;

    Date currentDate = today();

    cout << "Сьогодні: " << currentDate.year << "-" << currentDate.month << "-" << currentDate.day << endl;
    cout << "Пройшло днів: " << daysBetween(birthDate, currentDate) << endl;

    return 0;
}
