#include "library.h"
#include <stdio.h>

int day_of_the_year(struct Date date) {
    int totalDays = 0;

    if (!exists_date(date)) {
        return -1;
    }

    if (date.month == 1) {
        return date.day;
    }

    for (int i = 1; i <= date.month-1; i++) {
        totalDays += get_days_for_month(i, date.year);
    }
    totalDays += date.day;

    return totalDays;
}

struct Date input_date() {
    struct Date date;

    do {
        printf("Jahr Eingeben: ");
        scanf(" %i", &date.year);

        do {
            printf("Tag Eingeben: ");
            scanf(" %i", &date.day);
            if (date.day < 1 || date.day > 31) {
                printf("Der Tag muss zwischen 1 und 31 liegen\n");
            }
        } while (date.day < 1 || date.day > 31);

        do {
            printf("Monat Eingeben: ");
            scanf(" %i", &date.month);
            if (date.month < 1 || date.month > 12) {
                printf("Der Monat muss zwischen 1 und 12 liegen\n");
            }
        } while (date.month < 1 || date.month > 12);
    } while (date.day > get_days_for_month(date.month, date.year));

    return date;
}


int is_leapyear(int year) {
    if (year < 1582) {
        printf("Das Jahr darf nicht kleiner als 1582 sein");
        return 0;
    }

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    }

    return 0;
}


int get_days_for_month(int month, int year) {
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (year < 1582 || year > 2400 || month < 1 || month > 12) {
        printf("Ungültiger Monat oder Jahr\n");
        return -1;
    }

    if (month == 2 && is_leapyear(year)) {
        return 29;
    }

    return days_per_month[month-1];
}


int exists_date(struct Date date) {
    if (date.year < 1582 || date.year > 2400) {
        printf("Ungültiges Jahr übergeben\n");
        return 0;
    }

    return 1;
}


int weekday_for_the_date(int day, int month, int year) {
    if (month == 1 || month == 2) {
        month += 10;
        year -= 1;
    } else {
        month -= 2;
    }

    int modYear = year % 100;
    int divYear = year / 100;

    int weekday = (day + ((26 * month - 2) /10) + modYear + (modYear / 4) + (divYear / 4) - 2 * divYear) % 7;

    if (weekday < 0) {
        weekday += 7;
    }

    return weekday;
}

void print_weekday(int weekday)
{
    switch (weekday) {
        case 0:
            printf("Der Wochtag is ein Sonntag\n");
            break;
        case 1:
            printf("Der Wochtag is ein Montag\n");
            break;
        case 2:
            printf("Der Wochtag is ein Dienstag\n");
            break;
        case 3:
            printf("Der Wochtag is ein Mittwoch\n");
            break;
        case 4:
            printf("Der Wochtag is ein Donnerstag\n");
            break;
        case 5:
            printf("Der Wochtag is ein Freitag\n");
            break;
        case 6:
            printf("Der Wochtag is ein Smastag\n");
    }
}

int get_weekday_for_first_day_of_year(int year)
{
    int weekday = weekday_for_the_date(1,1,year);

    if (weekday >= 5 || weekday == 0) {
        return 0;
    }

    return 1;
}

int get_calender_week(int dayOfTheYear, int year)
{
    int firstDay = get_weekday_for_first_day_of_year(year);

    int firstCalenderWeek = firstDay + 7;

    int calenderWeeksCounter = 1;

    while (dayOfTheYear > firstCalenderWeek) {
        dayOfTheYear -= 7;
        calenderWeeksCounter++;
    }

    return calenderWeeksCounter;
}