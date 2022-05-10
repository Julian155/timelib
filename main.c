/**
 * Autor: Julian Sommer
 * Erstellt am: 29.03.2022
 */

#include <stdio.h>
#include "../../timelibLibrary/library.h"


int main()
{
    struct Date date = input_date();

    int dayOfTheYear = day_of_the_year(date);

    printf("Es ist der %i. Tag im Jahr %i\n", dayOfTheYear, date.year);
    print_weekday(weekday_for_the_date(date.day, date.month, date.year));
    printf("Es ist die %i. Kalenderwoche\n", get_calender_week(dayOfTheYear, date.year));

    return 0;
}


