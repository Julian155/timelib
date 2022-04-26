/**
 *
 * Autor: Julian Sommer
 * Erstellt am: 29.03.2022
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int weekday_for_the_date(int day, int month, int year);
void print_weekday(int weekday);
int get_day_for_first_monday(int year);
int get_calender_week(int dayOfTheYear, int year);

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    input_date(&day, &month, &year);

    int dayOfTheYear = day_of_the_year(day, month, year);

    printf("Es ist der %i. Tag im Jahr %i\n", dayOfTheYear, year);
    print_weekday(weekday_for_the_date(day, month, year));
    printf("Es ist die %i. Kalenderwoche\n", get_calender_week(dayOfTheYear, year));
    return 0;
}
/** Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1. */
int day_of_the_year(int day, int month, int year) {
    int totalDays = 0;

    if (!exists_date(day, month, year)) {
        return -1;
    }

    if (month == 1) {
        return day;
    }

    for (int i = 1; i <= month-1; i++) {
        totalDays += get_days_for_month(i, year);
    }
    totalDays += day;

    return totalDays;
}

/** Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde. */
void input_date(int *day, int *month, int *year) {
    do {
        printf("Jahr Eingeben: ");
        scanf(" %i", year);

        do {
            printf("Tag Eingeben: ");
            scanf(" %i", day);
            if (*day < 1 || *day > 31) {
                printf("Der Tag muss zwischen 1 und 31 liegen\n");
            }
        } while (*day < 1 || *day > 31);

        do {
            printf("Monat Eingeben: ");
            scanf(" %i", month);
            if (*month < 1 || *month > 12) {
                printf("Der Monat muss zwischen 1 und 12 liegen\n");
            }
        } while (*month < 1 || *month > 12);
    } while (*day > get_days_for_month(*month, *year));
}

/** Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. */
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

/** Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt. */
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

/** Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400. */
int exists_date(int day, int month, int year) {
    if (year < 1582 || year > 2400) {
        printf("Ungültiges Jahr übergeben\n");
        return 0;
    }
    return 1;
}

/** Die Funktion gibt den Wochentag für ein bestimmtes Datum an. */
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

int get_day_for_first_monday(int year)
{
    int weekday = weekday_for_the_date(1,1,year);

    if (weekday == 1) {
        return 1;
    }

    if (weekday == 0) {
        return 2;
    }

    return 8 - weekday + 1;

}
int get_calender_week(int dayOfTheYear, int year) {

    int firstDay = get_day_for_first_monday(year);

    int firstCalenderWeek = firstDay + 7;

    int calenderWeeksCounter = 1;

    while (dayOfTheYear > firstCalenderWeek) {
        dayOfTheYear -= 7;
        calenderWeeksCounter++;
    }

    return calenderWeeksCounter;
}

