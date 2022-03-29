/**
 *
 * Autor: Julian Sommer
 * Erstellt am: 29.03.2022
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int day_of_the_year(int day, int month, int year)
{

    return 0;
}

int main()
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int tag = 0;
    int monat = 0;
    int jahr = 0;
    int tageGesamt = 0;

    while (1) {
        do {
            printf("Tag Eingeben: ");
            scanf(" %i", &tag);
            if (tag < 1 || tag > 31) {
                printf("Der Tag muss zwischen 1 und 31 liegen\n");
            }
        } while (tag < 0 || tag > 31);

        do {
            printf("Monat Eingeben: ");
            scanf(" %i", &monat);
            if (monat < 1 || monat > 12) {
                printf("Der Monat muss zwischen 1 und 12 liegen\n");
            }
        } while (monat < 1 || monat> 12);

        printf("Jahr Eingeben: ");
        scanf(" %i", &jahr);

        if (tag > tage_pro_monat[monat-1]) {
            if (monat == 2) {
                if ((jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0) && tag == 29) {
                    break;
                }
                printf("Der Februar darf nur maximal 29 Tage haben\n");
            } else {
                printf("Der %i. Monat darf nicht mehr als 30 Tage haben\n", monat);
            }
        } else {
            break;
        }
    }

    if (monat == 1) {
        printf("Es ist der %i. Tag in %i", tag, jahr);
        return 0;
    }

    if (jahr % 4 == 0 && jahr % 100 != 0 || jahr % 400 == 0) {
        tage_pro_monat[1] = 29;
    }

    for (int i = 0; i <= monat-2; ++i) {
        tageGesamt = tageGesamt + tage_pro_monat[i];
    }

    tageGesamt = tageGesamt + tag;

    printf("Es ist der %i. Tag in %i", tageGesamt, jahr);

    return 0;
}
